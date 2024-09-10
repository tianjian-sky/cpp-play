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
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <experimental_onnxruntime_cxx_api.h>

// pretty prints a shape dimension vector
std::string print_shape(const std::vector<int64_t>& v) {
  std::stringstream ss("");
  for (size_t i = 0; i < v.size() - 1; i++)
    ss << v[i] << "x";
  ss << v[v.size() - 1];
  return ss.str();
}

int calculate_product(const std::vector<int64_t>& v) {
  int total = 1;
  for (auto& i : v) total *= i;
  return total;
}

using namespace std;

/**
 * 
 * OpenVINO™ 工具包是一个开源工具包，它通过降低延迟和提高吞吐量来加速 AI 推理，同时保持精度，减少模型占用空间，并优化硬件使用。它简化了 AI 开发，并在计算机视觉、大型语言模型（LLM）和生成式 AI 等领域中集成深度学习，并支持来自 PyTorch、TensorFlow、ONNX 等流行框架的模型。用户可以转换和优化模型，并在包括英特尔®硬件在内的多种环境中进行部署，无论是在本地设备、浏览器还是云端。
 
 * OpenVINO is an open-source toolkit for optimizing and deploying deep learning models from cloud to edge. It accelerates deep learning inference across various use cases, such as generative AI, video, audio, and language with models from popular frameworks like PyTorch, TensorFlow, ONNX, and more. Convert and optimize models, and deploy across a mix of Intel® hardware and environments, on-premises and on-device, in the browser or in the cloud.
 * 
 * https://github.com/openvinotoolkit/openvino/blob/2024.3.0/docs/dev/build_windows.md
 * 
 */

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Usage: model-explorer.exe <onnx_model.onnx>" << endl;
    return -1;
  }

#ifdef _WIN32
  std::string str = argv[1];
  cout << "model path:" << str << endl;
  /**
   * std::wstring
   * This is an instantiation of the basic_string class template that uses wchar_t as the character type,
   * 
   * wchar_t
   * char是8位字符类型，最多只能包含256种字符，许多外文字符集所含的字符数目超过256个，char型无法表示。
    wchar_t数据类型一般为16位或32位，但不同的C或C++库有不同的规定，如GNU Libc规定wchar_t为32位，总之，wchar_t所能表示的字符数远超char型。
   * 
   */
  std::wstring wide_string = std::wstring(str.begin(), str.end());

/**
   * ORTCHAR_T 定义在onnxruntime_c_api.h中
   * #define ORTCHAR_T wchar_t
   */
  std::basic_string<ORTCHAR_T> model_file = std::basic_string<ORTCHAR_T>(wide_string);
#else
  std::string model_file = argv[1];
#endif

  // onnxruntime setup
  Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "example-model-explorer");
  Ort::SessionOptions session_options;
  //Appending OpenVINO Execution Provider API
  #ifdef USE_OPENVINO
      cout << "USE_OPENVINO:" << 1 << endl;
    // Using OPENVINO backend
    OrtOpenVINOProviderOptions options;
    options.device_type = "CPU_FP32"; //Other options are: GPU_FP32, GPU_FP16, MYRIAD_FP16
    std::cout << "OpenVINO device type is set to: " << options.device_type << std::endl;
    cout << "before AppendExecutionProvider_OpenVINO" << endl;
    session_options.AppendExecutionProvider_OpenVINO(options);
    cout << "after AppendExecutionProvider_OpenVINO" << endl;
  #endif
  cout << "before session" << endl;
  Ort::Experimental::Session session = Ort::Experimental::Session(env, model_file, session_options);  // access experimental components via the Experimental namespace
    cout << "after session" << endl;
  // print name/shape of inputs
  std::vector<std::string> input_names = session.GetInputNames();
  std::vector<std::vector<int64_t> > input_shapes = session.GetInputShapes();
  cout << "Input Node Name/Shape (" << input_names.size() << "):" << endl;
  for (size_t i = 0; i < input_names.size(); i++) {
    cout << "\t" << input_names[i] << " : " << print_shape(input_shapes[i]) << endl;
  }

  // print name/shape of outputs
  std::vector<std::string> output_names = session.GetOutputNames();
  std::vector<std::vector<int64_t> > output_shapes = session.GetOutputShapes();
  cout << "Output Node Name/Shape (" << output_names.size() << "):" << endl;
  for (size_t i = 0; i < output_names.size(); i++) {
    cout << "\t" << output_names[i] << " : " << print_shape(output_shapes[i]) << endl;
  }

  // Assume model has 1 input node and 1 output node.
  assert(input_names.size() == 1 && output_names.size() == 1);

  // Create a single Ort tensor of random numbers
  auto input_shape = input_shapes[0];
  int total_number_elements = calculate_product(input_shape);
  std::vector<float> input_tensor_values(total_number_elements);
  std::generate(input_tensor_values.begin(), input_tensor_values.end(), [&] { return rand() % 255; });  // generate random numbers in the range [0, 255]
  std::vector<Ort::Value> input_tensors;
  input_tensors.push_back(Ort::Experimental::Value::CreateTensor<float>(input_tensor_values.data(), input_tensor_values.size(), input_shape));

  // double-check the dimensions of the input tensor
  assert(input_tensors[0].IsTensor() &&
         input_tensors[0].GetTensorTypeAndShapeInfo().GetShape() == input_shape);
  cout << "\ninput_tensor shape: " << print_shape(input_tensors[0].GetTensorTypeAndShapeInfo().GetShape()) << endl;

  // pass data through model
  cout << "Running model...";
  try {
    auto output_tensors = session.Run(session.GetInputNames(), input_tensors, session.GetOutputNames());
    cout << "done" << endl;

    // double-check the dimensions of the output tensors
    // NOTE: the number of output tensors is equal to the number of output nodes specifed in the Run() call
    assert(output_tensors.size() == session.GetOutputNames().size() &&
           output_tensors[0].IsTensor());
    cout << "output_tensor_shape: " << print_shape(output_tensors[0].GetTensorTypeAndShapeInfo().GetShape()) << endl;

  } catch (const Ort::Exception& exception) {
    cout << "ERROR running model inference: " << exception.what() << endl;
    exit(-1);
  }
}
