// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

/**
 * This sample application demonstrates how to use components of the experimental C++ API
 * to query for model inputs/outputs and how to run inferrence on a model.
 *
 * This example is best run with one of the ResNet models (i.e. ResNet18) from the onnx model zoo at
 *   https://github.com/onnx/models
 *
 * Assumptions made in this example:
 *  1) The onnx model has 1 input node and 1 output node
 *  2) The onnx model should have float input
 *
 *
 * In this example, we do the following:
 *  1) read in an onnx model
 *  2) print out some metadata information about inputs and outputs that the model expects
 *  3) generate random data for an input tensor
 *  4) pass tensor through the model and check the resulting tensor
 *
 */

#include <algorithm>  // std::generate
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <onnxruntime_cxx_api.h>

// pretty prints a shape dimension vector

/**
 * 
 * 一个基本的无符号整数的C / C + +类型，它是sizeof操作符返回的结果类型，该类型的大小可选择。
 * 因此，它可以存储在理论上是可能的任何类型的数组的最大大小。换句话说，一个指针可以被安全地放进为size_t类型（一个例外是类的函数指针，但是这是一个特殊的情况下）。 size_t类型通常用于循环、数组索引、大小的存储和地址运算。虽然size_t可以存储一个指针，它的目的是更好地使用另一个unsigned整数类型uintptr_t。在某些情况下，使用size_t类型是更为有效，比习惯性使用无符号类型的程序会更安全。
    size_t是在基于无符号整数memsize类型的C / C + +的标准库中定义的。C语言中，此类型位于头文件stddef.h中，而在C++中，则位于cstddef中。
 * 
 */

std::string print_shape(const std::vector<std::int64_t>& v) {
  std::stringstream ss("");
  for (std::size_t i = 0; i < v.size() - 1; i++) ss << v[i] << "x";
  ss << v[v.size() - 1];
  return ss.str();
}
/**
 * typedef long long          int64_t;
 */
int calculate_product(const std::vector<std::int64_t>& v) {
  int total = 1;
  for (auto& i : v) {
      std::cout << "--print shape:" << i  << std::endl;
      total *= i;
  }
  return total;
}
/**
 * Ort::MemoryInfo 
 * 
 * 
 *  std::string 	GetAllocatorName () const
    OrtAllocatorType 	GetAllocatorType () const
    int 	GetDeviceId () const
    OrtMemoryInfoDeviceType 	GetDeviceType () const
    OrtMemType 	GetMemoryType () const
    bool 	operator== (const MemoryInfoImpl< U > &o) const

    static MemoryInfo 	CreateCpu (OrtAllocatorType type, OrtMemType mem_type1)
 * 
 * 
 */
template <typename T>
Ort::Value vec_to_tensor(std::vector<T>& data, const std::vector<std::int64_t>& shape) {
  Ort::MemoryInfo mem_info =
      Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
    /**
     * static Value Ort::Value::CreateTensor	(const OrtMemoryInfo * 	info, T * 	p_data, size_t 	p_data_element_count, const int64_t * 	shape, size_t 	shape_len )		
        Creates a tensor with a user supplied buffer. Wraps OrtApi::CreateTensorWithDataAsOrtValue.
        *  Parameters
            info	Memory description of where the p_data buffer resides (CPU vs GPU etc).
            p_data	Pointer to the data buffer.
            p_data_element_count	The number of elements in the data buffer.
            shape	Pointer to the tensor shape dimensions.
            shape_len	The number of tensor shape dimensions.
    */
  auto tensor = Ort::Value::CreateTensor<T>(mem_info, data.data(), data.size(), shape.data(), shape.size());
  return tensor;
}
/**
 * 
 * 后来查了一下这两个函数的区别，发现有如下特点：
　　    1、main()是WINDOWS的控制台程序（32BIT）或DOS程序（16BIT）,   
    　  2、WinMain()是WINDOWS的GUI程序,   
    　  3、 wmain()是UNICODE版本的main()，wmain也是main的另一個别名,是为了支持二个字节的语言环境
        4、_tmain()是个宏,如果是UNICODE则他是wmain()否则他是main()
    因此分析，在main(int argc, _TCHAR* argv[])和wmain(int argc, _TCHAR* argv[])两种情况下
    同样输入***.exe /set
    wmain中argv[1] = "/"   ,占两个字节
    main中argv[1] = "/s" ,占两个字节
*/

#ifdef _WIN32
int wmain(int argc, ORTCHAR_T* argv[]) {
#else
int main(int argc, ORTCHAR_T* argv[]) {
#endif
  if (argc != 2) {
    std::cout << "Usage: ./onnx-api-example <onnx_model.onnx>" << std::endl;
    return -1;
  }

  /**
   * basic_string模板类
   * basic_string是C++标准库中的一个类，它提供了对字符串的基本操作
   */
  std::basic_string<ORTCHAR_T> model_file = argv[1];

  // onnxruntime setup

  /**
   * The Env holds the logging state used by all other objects. Note: One Env must be created before using any other Onnxruntime functionality
   *
    Ort::Env::Env	(	OrtLoggingLevel 	logging_level = ORT_LOGGING_LEVEL_WARNING, const char * 	logid = "" )	
   * 
   */
  Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "example-model-explorer");
  Ort::SessionOptions session_options;
  /**
     * Ort::Session
     *  	Session (std::nullptr_t)
            Create an empty Session object, must be assigned a valid one to be used.
    
            Session (const Env &env, const char *model_path, const SessionOptions &options)
            Wraps OrtApi::CreateSession.
    
            Session (const Env &env, const char *model_path, const SessionOptions &options, OrtPrepackedWeightsContainer *prepacked_weights_container)
            Wraps OrtApi::CreateSessionWithPrepackedWeightsContainer.
        
            Session (const Env &env, const void *model_data, size_t model_data_length, const SessionOptions &options)
            Wraps OrtApi::CreateSessionFromArray.
        
            Session (const Env &env, const void *model_data, size_t model_data_length, const SessionOptions &options, OrtPrepackedWeightsContainer *prepacked_weights_container) 
    * 
    * 
    */
  Ort::Session session = Ort::Session(env, model_file.c_str(), session_options);

  // print name/shape of inputs
  /**
   * OrtAllocator 
   * Memory allocation interface
   * 
   * Public Attributes
    uint32_t 	version
        Must be initialized to ORT_API_VERSION.
    
    void *(* 	Alloc )(struct OrtAllocator *this_, size_t size)
        Returns a pointer to an allocated block of size bytes.
    
    void(* 	Free )(struct OrtAllocator *this_, void *p)
        Free a block of memory previously allocated with OrtAllocator::Alloc.
    
    const struct OrtMemoryInfo *(* 	Info )(const struct OrtAllocator *this_)
        Return a pointer to an OrtMemoryInfo that describes this allocator.
    
    void *(* 	Reserve )(struct OrtAllocator *this_, size_t size)
        Optional allocation function to use for memory allocations made during session initialization. Use this function if you want to separate allocations made by ORT during Run() calls from those made during session initialization. This allows for separate memory management strategies for these allocations.
   * 
   * 
   */
  Ort::AllocatorWithDefaultOptions allocator;
  std::vector<std::string> input_names;
  std::vector<std::int64_t> input_shapes;
  std::cout << "Input Node Name/Shape (" << input_names.size() << "):" << std::endl;

  /**
   * 
    size_t Ort::detail::ConstSessionImpl< T >::GetInputCount	(		)	const
   * Returns the number of model inputs.
   */

  /**
   * 
    
    AllocatedStringPtr Ort::detail::ConstSessionImpl< T >::GetInputNameAllocated	(	size_t 	index,
    OrtAllocator * 	allocator 
    )
   * Returns a copy of input name at the specified index.
   * 
   * AllocatedStringPtr
   * unique_ptr typedef used to own strings allocated by OrtAllocators and release them at the end of the scope. 
   * The lifespan of the given allocator must eclipse the lifespan of AllocatedStringPtr instance
   * 
   * unique_ptr
   * 存储指向拥有的对象或数组的指针。 此对象/数组仅由 unique_ptr 拥有。 unique_ptr 被销毁后，此对象/数组也将被销毁。
   */

  /**
   * TypeInfo Ort::detail::ConstSessionImpl< T >::GetInputTypeInfo	(	size_t 	index	)	const
   * SessionGetInputTypeInfo()
   * OrtStatus * OrtApi::SessionGetInputTypeInfo	(	const OrtSession * 	session,
        size_t 	index,
        OrtTypeInfo ** 	type_info 
)	
   * 
   * Ort::TypeInfo
   * Type information that may contain either TensorTypeAndShapeInfo or the information about contained sequence or map depending on the ONNXType.
   *    
   */

  /**
   * CastTypeInfoToTensorInfo()
   * Get OrtTensorTypeAndShapeInfo from an OrtTypeInfo.
   * 
   * OrtTensorTypeAndShapeInfo
   * 
   * Ort::detail::TensorTypeAndShapeInfoImpl
   *    Public Member Functions
            ONNXTensorElementDataType 	GetElementType () const
                Wraps OrtApi::GetTensorElementType.
            
            size_t 	GetElementCount () const
                Wraps OrtApi::GetTensorShapeElementCount.
            
            size_t 	GetDimensionsCount () const
                Wraps OrtApi::GetDimensionsCount.
            
            void 	GetDimensions (int64_t *values, size_t values_count) const
                Wraps OrtApi::GetDimensions.
            
            void 	GetSymbolicDimensions (const char **values, size_t values_count) const
                Wraps OrtApi::GetSymbolicDimensions.
            
            std::vector< int64_t > 	GetShape () const
                Uses GetDimensionsCount & GetDimensions to return a std::vector of the shape.
   * 
   * 
    std::vector< int64_t > Ort::detail::TensorTypeAndShapeInfoImpl< T >::GetShape	(		)	const
    Uses GetDimensionsCount & GetDimensions to return a std::vector of the shape.
   * 
   */
  for (std::size_t i = 0; i < session.GetInputCount(); i++) {
    input_names.emplace_back(session.GetInputNameAllocated(i, allocator).get());
    input_shapes = session.GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
    std::cout << "\t" << input_names.at(i) << " : " << print_shape(input_shapes) << std::endl;
  }
  // some models might have negative shape values to indicate dynamic shape, e.g., for variable batch size.
  for (auto& s : input_shapes) {
    if (s < 0) {
      s = 1;
    }
  }

  // print name/shape of outputs
  std::vector<std::string> output_names;
  std::cout << "Output Node Name/Shape (" << output_names.size() << "):" << std::endl;
  for (std::size_t i = 0; i < session.GetOutputCount(); i++) {
    output_names.emplace_back(session.GetOutputNameAllocated(i, allocator).get());
    auto output_shapes = session.GetOutputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
    std::cout << "\t" << output_names.at(i) << " : " << print_shape(output_shapes) << std::endl;
  }

  // Assume model has 1 input node and 1 output node.
  assert(input_names.size() == 1 && output_names.size() == 1);

  // Create a single Ort tensor of random numbers
  auto input_shape = input_shapes;
  auto total_number_elements = calculate_product(input_shape);

  std::cout << "total_number_elements:" << total_number_elements << std::endl;

  // generate random numbers in the range [0, 255]
  std::vector<float> input_tensor_values(total_number_elements);
  
  
  /**
  * std::generate
    template< class ExecutionPolicy, class ForwardIt, class Generator >
    void generate( ExecutionPolicy&& policy, ForwardIt first, ForwardIt last, Generator g );
  * 以给定函数对象 g 所生成的值赋值范围 [first, last) 中的每个元素。
  *
  */
  
  /**
    * c++ lambda
    * https://learn.microsoft.com/zh-cn/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
    *
    *capture 子句
    Lambda 可在其主体中引入新的变量（用 C++14），它还可以访问（或“捕获”）周边范围内的变量。 Lambda 以 capture 子句开头。 它指定捕获哪些变量，以及捕获是通过值还是通过引用进行的。 有与号 (&) 前缀的变量通过引用进行访问，没有该前缀的变量通过值进行访问。

    空 capture 子句 [ ] 指示 lambda 表达式的主体不访问封闭范围中的变量。

    可以使用默认捕获模式来指示如何捕获 Lambda 体中引用的任何外部变量：[&] 表示通过引用捕获引用的所有变量，而 [=] 表示通过值捕获它们。
    */


  std::generate(input_tensor_values.begin(), input_tensor_values.end(), [&] { return rand() % 255; });
  std::vector<Ort::Value> input_tensors;
  input_tensors.emplace_back(vec_to_tensor<float>(input_tensor_values, input_shape));

  // double-check the dimensions of the input tensor
  assert(input_tensors[0].IsTensor() && input_tensors[0].GetTensorTypeAndShapeInfo().GetShape() == input_shape);
  std::cout << "\ninput_tensor shape: " << print_shape(input_tensors[0].GetTensorTypeAndShapeInfo().GetShape()) << std::endl;

  // pass data through model
  std::vector<const char*> input_names_char(input_names.size(), nullptr);
  /**
  * std::transform
  * Applies the given function to a range and stores the result in another range, b
  *
  */
  /**
  * std::c_str()
  *这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串样式。
  * Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
  */
  std::transform(std::begin(input_names), std::end(input_names), std::begin(input_names_char),
                 [&](const std::string& str) { return str.c_str(); });

  std::vector<const char*> output_names_char(output_names.size(), nullptr);
  std::transform(std::begin(output_names), std::end(output_names), std::begin(output_names_char),
                 [&](const std::string& str) { return str.c_str(); });

  std::cout << "Running model..." << std::endl;
  try {
    auto output_tensors = session.Run(Ort::RunOptions{nullptr}, input_names_char.data(), input_tensors.data(),
                                      input_names_char.size(), output_names_char.data(), output_names_char.size());
    std::cout << "Done!" << std::endl;

    // double-check the dimensions of the output tensors
    // NOTE: the number of output tensors is equal to the number of output nodes specifed in the Run() call
    assert(output_tensors.size() == output_names.size() && output_tensors[0].IsTensor());
  } catch (const Ort::Exception& exception) {
      std::cout << "ERROR running model inference: " << exception.what() << std::endl;
    exit(-1);
  }
}
