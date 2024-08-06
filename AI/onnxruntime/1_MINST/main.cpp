// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#define UNICODE
#include <windows.h>
#include <windowsx.h>
#include <onnxruntime_cxx_api.h>
#include <array>
#include <cmath>
#include <algorithm>

// #pragma comment是#pragma下的一个子命令，使用注释方式引入库或编译目录。
/**
 * 
 *  #pragma comment( comment-type ,["commentstring"] )
    comment-type是一个预定义的标识符，指定注释的类型，应该是compiler，exestr，lib，linker之一。
    commentstring是一个提供为comment-type提供附加信息的字符串。
 *  我们经常用到的是 #pragma comment(lib，"*.lib") 这类写法。
 *  #pragma comment(lib,"Ws2_32.lib") 表示链接Ws2_32.lib这个库。和在工程设置里写上链入Ws2_32.lib的效果一样，
 *  不过这种方法写的程序别人在使用你的代码的时候就不用再设置工程settings了。
 */
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "onnxruntime.lib")


// std::exp(n)

// std::array
// template < class T, size_t N /* Size of the array, */ > class array;

/**
 *  constexpr
 *  与 const 不同，constexpr 也可以应用于函数和类 constructor（构造函数）。 constexpr 指示值或返回值是 constant（常数），如果可能，将在编译时进行计算。
    每当需要 const 整数时（如在模板自变量和数组声明中），都可以使用 constexpr 整数值。 如果在编译时（而非运行时）计算某个值，它可以使程序运行速度更快、占用内存更少。
    为了限制计算编译时 constant（常数）的复杂性及其对编译时间的潜在影响，C++14 标准要求 constant（常数）表达式中所涉及的类型为文本类型。
 * 
 * /

/**
 *  文本类型
 *  是可在编译时确定其布局的类型。 以下均为文本类型：
        * void
        * 标量类型
        * 引用
        * Void、标量类型或引用的数组
        * 具有普通析构函数以及一个或多个 constexpr 构造函数且不移动或复制构造函数的类。 此外，其所有非静态数据成员和基类必须是文本类型且不可变。 
 * 
 */

/**
 * 普通、标准布局、POD 和文本类型
 * 
 * 普通类型
 *      当 C++ 中的类或结构具有编译器提供的或显式默认设置的特殊成员函数时，该类或结构为普通类型。 它占用连续内存区域。 
 *      它可以具有含不同访问说明符的成员。 在 C++ 中，编译器可以自由选择在此情况下对成员排序的方式。 因此，你可以在内存中复制此类对象，但不能从 C 程序中可靠地使用它们。 可以将普通类型 T 复制到 char 或无符号 char 数组，并安全地复制回 T 变量。 请注意，由于对齐要求，类型成员之间可能存在填充字节。
 *      
 *      普通类型具有普通默认构造函数、普通复制构造函数、普通复制赋值运算符和普通析构函数。 
 *      在各种情况下，“普通”意味着构造函数/运算符/析构函数并非用户提供，并且属于存在以下情况的类
            * 没有虚拟函数或虚拟基类，
            * 没有具有相应非普通构造函数/运算符/析构函数的基类
            * 没有具有相应非普通构造函数/运算符/析构函数的类类型的数据成员
 * 
 * 
 * 标准布局类型
 *      当类或结构不包含某些 C++ 语言功能（例如无法在 C 语言中找到的虚拟函数），并且所有成员都具有相同的访问控制时，该类或结构为标准布局类型。 可以在内存中对其进行复制，并且布局已经过充分定义，可以由 C 程序使用。
 *      标准布局类型可以具有用户定义的特殊成员函数。 此外，标准布局类型还具有以下特征：
 *          * 没有虚拟函数或虚拟基类
            * 所有非静态数据成员都具有相同的访问控制
            * 类类型的所有非静态成员均为标准布局
            * 所有基类都为标准布局
            * 没有与第一个非静态数据成员类型相同的基类。
            满足以下条件之一：
            ** 最底层派生类中没有非静态数据成员，并且具有非静态数据成员的基类不超过一个，或者
            ** 没有含非静态数据成员的基类
 *         (在C语言中,没有类的概念,也没有访问权限控制关键字如public和private)
 * 
 *  POD 类型
 *      当某一类或结构同时为普通和标准布局时，该类或结构为 POD（简单旧数据）类型。 因此，POD 类型的内存布局是连续的，并且每个成员的地址都比在其之前声明的成员要高，以便可以对这些类型执行逐字节复制和二进制 I/O。 
 *      标量类型（例如 int）也是 POD 类型。 作为类的 POD 类型只能具有作为非静态数据成员的 POD 类型。
 *      
 * 
 *  文本类型
 *      文本类型是可在编译时确定其布局的类型。
 *               * void
                * 标量类型
                * 引用
                * Void、标量类型或引用的数组
                * 具有普通析构函数以及一个或多个 constexpr 构造函数且不移动或复制构造函数的类。 此外，其所有非静态数据成员和基类必须是文本类型且不可变。 
 
    #include <type_traits>
    int main()
    {
        cout << boolalpha;
        cout << "A is trivial is " << is_trivial<A>() << endl; // false
        cout << "A is standard-layout is " << is_standard_layout<A>() << endl;  // false
        cout << "C is trivial is " << is_trivial<C>() << endl; // true
        cout << "C is standard-layout is " << is_standard_layout<C>() << endl;  // false
        cout << "D is trivial is " << is_trivial<D>() << endl;  // false
        cout << "D is standard-layout is " << is_standard_layout<D>() << endl; // true
        cout << "POD is trivial is " << is_trivial<POD>() << endl; // true
        cout << "POD is standard-layout is " << is_standard_layout<POD>() << endl; // true
        return 0;
    }
 */



// softmax

template <typename T>
static void softmax(T& input) {
  float rowmax = *std::max_element(input.begin(), input.end());
  std::vector<float> y(input.size());
  float sum = 0.0f;
  for (size_t i = 0; i != input.size(); ++i) {
    sum += y[i] = std::exp(input[i] - rowmax); // std::exp(n) => e^n
  }
  for (size_t i = 0; i != input.size(); ++i) {
    input[i] = y[i] / sum;
  }
}

// This is the structure to interface with the MNIST model
// After instantiation, set the input_image_ data to be the 28x28 pixel image of the number to recognize
// Then call Run() to fill in the results_ data with the probabilities of each
// result_ holds the index with highest probability (aka the number the model thinks is in the image)
struct MNIST {
  MNIST() {
    /**
     * static MemoryInfo Ort::MemoryInfo::CreateCpu	(OrtAllocatorType type, OrtMemType mem_type1 )	
        * OrtAllocatorType
                OrtInvalidAllocator 	
                OrtDeviceAllocator 	
                OrtArenaAllocator 	
        * OrtMemType
                OrtMemTypeCPUInput 	 Any CPU memory used by non-CPU execution provider.
                OrtMemTypeCPUOutput 	 CPU accessible memory outputted by non-CPU execution provider, i.e. CUDA_PINNED.
                OrtMemTypeCPU 	 Temporary CPU accessible memory allocated by non-CPU execution provider, i.e. CUDA_PINNED.
                OrtMemTypeDefault 	 The default allocator for execution provider.
     */
    auto memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
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
    input_tensor_ = Ort::Value::CreateTensor<float>(memory_info, input_image_.data(), input_image_.size(),
                                                    input_shape_.data(), input_shape_.size());
    output_tensor_ = Ort::Value::CreateTensor<float>(memory_info, results_.data(), results_.size(),
                                                     output_shape_.data(), output_shape_.size());
  }
  
  /**
   * ptrdiff_t是C/C++标准库中定义的一个与机器相关的数据类型。ptrdiff_t类型变量通常用来保存两个指针减法操作的结果
   * 
   */

  /**
   * Ort::RunOptions
   * loglevel,runtag, configEntry..
   */

  /**
   * Ort::Env
   *  	Env (std::nullptr_t)
        Create an empty Env object, must be assigned a valid one to be used.
    
        Env (OrtLoggingLevel logging_level=ORT_LOGGING_LEVEL_WARNING, const char *logid="")
        Wraps OrtApi::CreateEnv.
    
        Env (OrtLoggingLevel logging_level, const char *logid, OrtLoggingFunction logging_function, void *logger_param)
        Wraps OrtApi::CreateEnvWithCustomLogger.
    
        Env (const OrtThreadingOptions *tp_options, OrtLoggingLevel logging_level=ORT_LOGGING_LEVEL_WARNING, const char *logid="")
        Wraps OrtApi::CreateEnvWithGlobalThreadPools.
    
        Env (const OrtThreadingOptions *tp_options, OrtLoggingFunction logging_function, void *logger_param, OrtLoggingLevel logging_level=ORT_LOGGING_LEVEL_WARNING, const char *logid="")
        Wraps OrtApi::CreateEnvWithCustomLoggerAndGlobalThreadPools.
    
        Env (OrtEnv *p)
   * 
   * 
   */

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

   /**
    *  struct 与 class区别
    *   这就是区别的本质所在，默认情况下类是私有的，如果你不指定修改任何可见性，那默认值就是私有的私有的（private）。而在结构体中默认值却是公有的 （public） ，技术上讲这是类与结构的唯一区别。 
    *   struct 结构体在 C++ 中继续存在的唯一原因，是因为它希望与 C 保持向后兼容性，因为C代码没有类，但是有结构体，如果我们去掉这个结构体关键字，就会失去兼容性，那样的话 C 的编译器就不知道什么是 struct。
    * 
    */

  std::ptrdiff_t Run() {
    const char* input_names[] = {"Input3"};
    const char* output_names[] = {"Plus214_Output_0"};

    Ort::RunOptions run_options;

    /**
     * 
     * Run the model returning results 
     * Run (const RunOptions &run_options, const char *const *input_names, const Value *input_values, size_t input_count, const char *const *output_names, Value *output_values, size_t output_count)
     * 
     */
    session_.Run(run_options, input_names, &input_tensor_, 1, output_names, &output_tensor_, 1);
    softmax(results_);
    /**
     * std::distance
     *  return distance between iterators (the number of elements between first and last)
     */
    result_ = std::distance(results_.begin(), std::max_element(results_.begin(), results_.end()));
    return result_;
  }

  static constexpr const int width_ = 28;
  static constexpr const int height_ = 28;

  std::array<float, width_ * height_> input_image_{};
  std::array<float, 10> results_{};
  int64_t result_{0};

 private:
  Ort::Env env;
  Ort::Session session_{env, L"mnist.onnx", Ort::SessionOptions{nullptr}};

  Ort::Value input_tensor_{nullptr};
  std::array<int64_t, 4> input_shape_{1, 1, width_, height_};

  Ort::Value output_tensor_{nullptr};
  std::array<int64_t, 2> output_shape_{1, 10};
};

const constexpr int drawing_area_inset_{4};  // Number of pixels to inset the top left of the drawing area
const constexpr int drawing_area_scale_{4};  // Number of times larger to make the drawing area compared to the shape inputs
const constexpr int drawing_area_width_{MNIST::width_ * drawing_area_scale_};
const constexpr int drawing_area_height_{MNIST::height_ * drawing_area_scale_};
/**
 * std::unique_ptr
 * 独占所有权:std::unique_ptr拥有对其管理的对象的唯一所有权,意味着没有两个std::unique_ptr指针可以指向同一个对象。
 */
std::unique_ptr<MNIST> mnist_;


/**
 * 什么是句柄（HANDLE）
    HANDLE：　　

　　句柄是WONDOWS用来标识被应用程序所建立或使用的对象的唯一整数，WINDOWS使用各种各样的句柄标识诸如应用程序实例，窗口，
　　控制，位图，GDI对象等等。从数据类型上来看它是一个16位的无符号整数（0 ~ 65535）。
　　如果想更透彻一点地认识句柄，我可以告诉大家，句柄是一种指向指针的指针。我们知道，所谓指针是一种内存地址。应用程序启动后，组
　　成这个程序的各对象是住留在内存的。如果简单地理解，似乎我们只要获知这个内存的首地址，那么就可以随时用这个地址访问对象。

　　但是，如果您真的这样认为，那么您就大错特错了。我们知道，Windows是一个以虚拟内存为基础的操作 系统。在这种系统环境下，Win-
　　dows内存管理器经常在内存中来回移动对象，依此来满足各种应用程序的内存需要。对象被移动意味着它的地址变化了。如果 地址总是如
　　此变化，我们该到哪里去找该对象呢?
　　为了解决这个问题，Windows操作系统为各应用程序腾出一些内存储地址，用来专门登记各应用对象在内存中的地址变化，而这个地址(存
　　储单元的位置)本身是不变的。Windows内存管理器在移动对象在内存中的位置后，把对象新的地址告知这个句柄地址来保存。这样我们只
　　需记住这个句柄地址就可以间接地知道对象具体在内存中的哪个位置。这个地址是在对象装载(Load)时由系统分配给的，当系统卸载时(Un
　　load)又释放给系统。
　　　　　　句柄地址(稳定)→记载着对象在内存中的地址────→对象在内存中的地址(不稳定)→实际对象
 * 
 */

/**
 * DECLARE_HANDLE
 * 
 * 而DECLARE_HANDLE(HWND);就是：
　　struct HWND__ { int unused;};
　　typedef struct HWND__ *HWND;
　　现在实际上都清楚啦，这些Handles都不过是指向struct的指针，至于这个struct的用处，连M$都说unused
 * 
 */

/**
 * BITMAP：BITMAP是一个储存位图长宽等信息的结构体，也储存位图的内容 作者：Leaf编译者 https://www.bilibili.com/read/cv17674311/ 出处：bilibili
 * HBITMAP：它在windef.h中定义，但像BITMAP一样，“#include <windows.h>” 就行，但在Microsoft Docs中没有找到它。它储存了完整的位图的句柄 作者：Leaf编译者 https://www.bilibili.com/read/cv17674311/ 出处：bilibili
 */
HBITMAP dib_;
/**
 * HDC显示是一种Windows API的数据类型，表示设备上下文句柄。每个图形设备都有一个HDC句柄，它用于保存设备表面的信息。在图形显示中，与显示设备相关的所有绘图操作都需要指定一个HDC句柄。因此，HDC显示是用于访问图形设备上下文的一种数据类型。HDC表示一个在屏幕上呈现的二维空间，在这个空间里我们可以显示和绘制图形、文本等内容。
 */
HDC hdc_dib_;
bool painting_{};

/**
 * createSolidBrush 函数 (wingdi.h)
 * CreateSolidBrush 函数创建具有指定纯色的逻辑画笔。

 */
HBRUSH brush_winner_{CreateSolidBrush(RGB(128, 255, 128))};
HBRUSH brush_bars_{CreateSolidBrush(RGB(128, 128, 255))};

/**
 * DIB设备无关位图文件
 * 这是一种文件格式，是为了保证由某个应用程序创建的位图图形可以被其它应用程序装载或显示。
 * DIB的与设备无关性主要体现在以下两个方面：
 * DIB的颜色模式与设备无关。例如，一个256色的DIB既可以在真彩色显示模式下使用，也可以在16色模式下使用。256色以下（包括256色）的DIB拥有自己的颜色表，像素的颜色独立于系统调色板。
 * 由于DIB不依赖于具体设备，因此可以用来永久性地保存图象。DIB一般是以*.BMP文件的形式保存在磁盘中的，有时也会保存在*.DIB文件中。运行在不同输出设备下的应用程序可以通过DIB来交换图象。
 * 
 *  与Borland C++下的框架类库OWL不同，MFC未提供现成的类来封装DIB。尽管Microsoft列出了一些理由，但没有DIB类确实给MFC用户带来很多不便。用户要想使用DIB，首先应该了解DIB的结构。
    在内存中，一个完整的DIB由两部分组成：一个BITMAPINFO结构和一个存储像素阵列的数组。BITMAPINFO描述了位图的大小，颜色模式和调色板等各种属性

    与DDB不同，DIB的字节数组是从图象的最下面一行开始的逐行向上存储的，也即等于把图象倒过来然后在逐行扫描。另外，字节数组中每个扫描行的字节数必需是4的倍数，如果不足要用0补齐

    由于MFC未提供DIB类，用户在使用DIB时将面临繁重的Windows API编程任务
 */

/**
 * DIBSECTION 结构包含有关通过调用 CreateDIBSection 函数创建的 DIB 的信息。 
 * DIBSECTION 结构包括有关位图尺寸、颜色格式、颜色掩码、可选文件映射对象和可选位值存储偏移量的信息。 
 * 应用程序可以通过调用 GetObject 函数获取给定 DIB 的填充 DIBSECTION 结构。
 * 
 * typedef struct tagDIBSECTION {
  BITMAP           dsBm;
  BITMAPINFOHEADER dsBmih;
  DWORD            dsBitfields[3];
  HANDLE           dshSection;
  DWORD            dsOffset;
} DIBSECTION, *LPDIBSECTION, *PDIBSECTION;

 * 
 */

/**
 * typedef struct tagBITMAP
  {
    LONG        bmType;
    LONG        bmWidth;
    LONG        bmHeight;
    LONG        bmWidthBytes;
    WORD        bmPlanes;
    WORD        bmBitsPixel;
    LPVOID      bmBits;
  } BITMAP 
 * 
 */

/**
 * ::全局作用域符号：global scope(全局作用域符），用法（::name)
 */
struct DIBInfo : DIBSECTION {
  DIBInfo(HBITMAP hBitmap) noexcept { ::GetObject(hBitmap, sizeof(DIBSECTION), this); }

  int Width() const noexcept { return dsBm.bmWidth; }
  int Height() const noexcept { return dsBm.bmHeight; }

  void* Bits() const noexcept { return dsBm.bmBits; }
  int Pitch() const noexcept { return dsBmih.biSizeImage / abs(dsBmih.biHeight); }
};

/**
 *  真彩色（麦金塔电脑用户则为百万色）图像是一种用三个或更多字节描述像素的计算机图像存储方式。 
 *  伪彩色图像的含义是，每个像素的颜色不是由每个基色分量的数值直接决定，而是把像素值当作彩色查找表(color look-up table，CLUT)的表项入口地址，去查找一个显示图像时使用的R，G，B强度值，用查找出的R，G，B强度值产生的彩色称为伪彩色。
 */


/**
 * static_cast 在编译时被检查，用以确定两种类型之间是否有继承关系。 如果两种类型无关，强制转换会导致编译器错误。
 * ①用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。
        进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
        进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
    ②用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。这种转换的安全性也要开发人员来保证。
    ③把空指针转换成目标类型的空指针。
    ④把任何类型的表达式转换成void类型。
    注意：static_cast不能转换掉expression的const、volatile、或者__unaligned属性。
    C++中static_cast和reinterpret_cast的区别
    C++primer第四版第五章里写了编译器隐式执行任何类型转换都可由static_cast显示完成;reinterpret_cast通常为操作数的位模式提供较低层的重新解释
 *  
 * dynamic_cast 如果将一个对象强制转换（更具体地说，帽子 ^）为派生程度更大的类型，你预期目标对象可能有时是 nullptr 或者该强制转换可能会失败，并且你希望将该条件处理为普通的代码路径而不是异常，请使用 dynamic_cast
 * 将一个基类对象指针（或引用）转换到继承类指针，dynamic_cast会根据基类指针是否真正指向继承类指针来做相应处理。
 * 
 */

// We need to convert the true-color data in the DIB into the model's floating point format
// TODO: (also scales down the image and smooths the values, but this is not working properly)
void ConvertDibToMnist() {
  DIBInfo info{dib_};

  const DWORD* input = reinterpret_cast<const DWORD*>(info.Bits());
  float* output = mnist_->input_image_.data();

  std::fill(mnist_->input_image_.begin(), mnist_->input_image_.end(), 0.f);

  for (unsigned y = 0; y < MNIST::height_; y++) {
    for (unsigned x = 0; x < MNIST::width_; x++) {
      output[x] += input[x] == 0 ? 1.0f : 0.0f;
    }
    input = reinterpret_cast<const DWORD*>(reinterpret_cast<const BYTE*>(input) + info.Pitch());
    output += MNIST::width_;
  }
}


/**
 * sal.h
 * sal.h provides a set of annotations to describe how a function uses its
* parameters - the assumptions it makes about them, and the guarantees it makes
*  upon finishing.
 *   _In_     : input parameter to a function, unmodified by called function
      _Out_    : output parameter, written to by called function, pointed-to
                 location not expected to be initialized prior to call
      _Outptr_ : like _Out_ when returned variable is a pointer type
                 (so param is pointer-to-pointer type). Called function
                 provides/allocated space.
      _Outref_ : like _Outptr_, except param is reference-to-pointer type.
      _Inout_  : inout parameter, read from and potentially modified by
                 called function.
      _Ret_    : for return values
      _Field_  : class/struct field invariants
 */

/**
 * winuser.h 标头
 * https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/
 */

/**
 * typedef LONG_PTR            LRESULT;
 * _MSC_VER
 * _MSC_VER是微软公司推出的C/C++编译器在ANSI/ISO C99标准之外扩展的宏定义，用来定义当前微软公司自己的编译器的主版本。需要注意的是，这并不是Visual Studio 的版本号，也不是Visual C++的版本号。
 * __stdcall
 * _stdcall是Pascal方式清理C方式压栈，通常用于Win32 Api中，函数采用从右到左的压栈方式
 *  是函数调用约定的一种，函数调用约定主要约束了两件事：
 *  1.参数从右向左压入堆栈
    2.函数被调用者修改堆栈
    3.函数名(在编译器这个层次)自动加前导的下划线，后面紧跟一个@符号，其后紧跟着参数的尺寸
 * 
 * #elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
    #define CALLBACK    __stdcall
 */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
/**
 * #define APIENTRY    WINAPI 
 * 
 *  #elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
    #define CALLBACK    __stdcall
    #define WINAPI      __stdcall
    #define WINAPIV     __cdecl
    #define APIENTRY    WINAPI
    #define APIPRIVATE  __stdcall
    #define PASCAL      __stdcall
    #else
 */

/**
 * #define _In_                            _SAL2_Source_(_In_, (), _Pre1_impl_(__notnull_impl_notref) _Pre_valid_impl_ _Deref_pre1_impl_(__readaccess_impl_notref))
 */

// The Windows entry point function
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE /*hPrevInstance*/, _In_ LPTSTR /*lpCmdLine*/,
                      _In_ int nCmdShow) {
  try {
    mnist_ = std::make_unique<MNIST>();
  } catch (const Ort::Exception& exception) {
    MessageBoxA(nullptr, exception.what(), "Error:", MB_OK);
    return 0;
  }

/**
 * typedef WNDCLASSEXW WNDCLASSEX;
 * WNDCLASSEX
    用于注册窗口类的结构体
    https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/ns-winuser-wndclassexa?redirectedfrom=MSDN
 **/
  {
    WNDCLASSEX wc{};
    wc.cbSize = sizeof(WNDCLASSEX); // 此结构的大小（以字节为单位）。 将此成员设置为 sizeof(WNDCLASSEX)
    wc.style = CS_HREDRAW | CS_VREDRAW; // 类样式 () 。 此成员可以是 类样式的任意组合。
    wc.lpfnWndProc = WndProc; // 指向窗口过程的指针。 必须使用 CallWindowProc 函数调用窗口过程
    wc.hInstance = hInstance; // 实例的句柄，该实例包含类的窗口过程。
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // 类游标的句柄。
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 类背景画笔的句柄。 此成员可以是用于绘制背景的画笔的句柄
    wc.lpszClassName = L"ONNXTest"; // 指向以 null 结尾的字符串或 的指针是原子
    RegisterClassEx(&wc);
  }
  {
    BITMAPINFO bmi{};
    bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
    bmi.bmiHeader.biWidth = MNIST::width_;
    bmi.bmiHeader.biHeight = -MNIST::height_;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biCompression = BI_RGB;

    void* bits;
    dib_ = CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS, &bits, nullptr, 0);
  }
  if (dib_ == nullptr) return -1;
  /**
   * CreateCompatibleDC函数创建一个与指定设备兼容的内存设备上下文环境（DC）
   */
  hdc_dib_ = CreateCompatibleDC(nullptr);
  /**
   * 
   * SelectObject计算机编程语言函数，该函数选择一对象到指定的设备上下文环境中，该新对象替换先前的相同类型的对象。
   * SelectObject([in] hdc DC 的句柄, [in] h 要选择的对象的句柄。 指定的对象必须已使用以下函数之一创建)
   * https://learn.microsoft.com/zh-cn/windows/win32/api/wingdi/nf-wingdi-selectobject
   */
  SelectObject(hdc_dib_, dib_);
  SelectObject(hdc_dib_, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));
  RECT rect{0, 0, MNIST::width_, MNIST::height_};
  FillRect(hdc_dib_, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

  HWND hWnd = CreateWindow(L"ONNXTest", L"ONNX Runtime Sample - MNIST", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                           CW_USEDEFAULT, 512, 256, nullptr, nullptr, hInstance, nullptr);
  if (!hWnd)
    return FALSE;

  /**
   * hWnd
   * 指窗口句柄
   * nCmdShow
   * 指定窗口如何显示。如果发送应用程序的程序提供了STARTUPINFO结构，则应用程序第一次调用ShowWindow时该参数被忽略。否则，在
   * ShowWindow(hWnd, nCmdShow)，则应用程序第一次调用ShowWindow时该参数被忽略。否则，在第一次调用ShowWindow函数时，该值应为在函数WinMain中nCmdShow参数。在随后的调用中，该参数可以为下列值之一：
   * ：该函数设置指定窗口的显示状态。
   * 
   */
  ShowWindow(hWnd, nCmdShow);

  MSG msg;

  /**
   * GetMessage是从调用线程的消息队列里取得一个消息并将其放于指定的结构。
   * 此函数可取得与指定窗口联系的消息和由PostThreadMessage寄送的线程消息。
   * 此函数接收一定范围的消息值。GetMessage不接收属于其他线程或应用程序的消息。
   * 获取消息成功后，线程将从消息队列中删除该消息。函数会一直等待直到有消息到来才有返回值。
   * 
   * GetMessage（LPMSG lpMsg，HWND hWnd，UINT wMsgFilterMin，UINT wMsgFilterMax）
        参数：
        lpMsg：指向MSG结构的指针，该结构从线程的消息队列里接收消息信息。
        hWnd：取得其消息的窗口的句柄。当其值取NULL时，GetMessage为任何属于调用线程的窗口检索消息，线程消息通过PostThreadMessage寄送给调用线程。
        wMsgFilterMin：指定被检索的最小消息值的整数。
        wMsgFilterMax：指定被检索的最大消息值的整数。
   */
  while (GetMessage(&msg, NULL, 0, 0)) {

    /**
     * TranslateMessage( CONST MSG*lpMsg );
     * 该函数将虚拟键消息转换为字符消息。字符消息被寄送到调用线程的消息队列里，当下一次线程调用函数GetMessage或PeekMessage时被读出。
     */
    TranslateMessage(&msg);
    /**
     * lpmsg：指向含有消息的MSG结构的指针。
     * LONG DispatchMessage（CONST MSG*lpmsg）
     * 该函数分发一个消息给窗口程序。通常消息从GetMessage函数获得或者TranslateMessage函数传递的。消息被分发到回调函数（过程函数），作用是消息传递给操作系统，然后操作系统去调用我们的回调函数，也就是说我们在窗体的过程函数中处理消息。
     */
    DispatchMessage(&msg);
  }

  // DeleteObject，该函数删除一个逻辑笔、画笔、字体、位图、区域或者调色板，释放所有与该对象有关的系统资源，在对象被删除之后，指定的句柄也就失效了。
  DeleteObject(dib_);
  DeleteDC(hdc_dib_);

  DeleteObject(brush_winner_);
  DeleteObject(brush_bars_);

  return (int)msg.wParam;
}

/**
 * typedef LONG_PTR            LRESULT;
 * _MSC_VER
 * _MSC_VER是微软公司推出的C/C++编译器在ANSI/ISO C99标准之外扩展的宏定义，用来定义当前微软公司自己的编译器的主版本。需要注意的是，这并不是Visual Studio 的版本号，也不是Visual C++的版本号。
 * __stdcall
 * _stdcall是Pascal方式清理C方式压栈，通常用于Win32 Api中，函数采用从右到左的压栈方式
 *  是函数调用约定的一种，函数调用约定主要约束了两件事：
 *  1.参数从右向左压入堆栈
    2.函数被调用者修改堆栈
    3.函数名(在编译器这个层次)自动加前导的下划线，后面紧跟一个@符号，其后紧跟着参数的尺寸
 * 
 * #elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
    #define CALLBACK    __stdcall
 */
/**
 * 
 * 每个窗口会有一个称为窗口过程的回调函数(WndProc)，它带有四个参数，分别为：
    窗口句柄(Window Handle) HWND,
    消息ID(Message ID) UINT,
    和两个消息参数(wParam, lParam)WPARAM、LPARAM,
    WndProc的第一个参数hWnd就是当前接收消息的窗口句柄，第二个参数就是被传送过来的消息，第三、第四个参数都是附加在消息上的数据，这和MSG结构体是一样的。
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
  switch (message) {
    // WM_PAINT 指示视窗讯息处理程式在显示区域上画一些东西。
    case WM_PAINT: {
      /**
       * PAINTSTRUCT 结构包含可用于绘制窗口的工作区的信息。
       * hdc
        标识用于绘制要使用的显示上下文。
        fErase
        指定背景是否需要重新绘制。 ，如果应用程序应重新绘制背景，它不是 0。 应用程序将绘制背景负责，如果窗口类的窗口创建的，而不用背景画笔 (请参见 WNDCLASS 结构的 hbrBackground 成员的说明。 Windows SDK)。
        rcPaint
        指定绘制请求矩形的左上角和右下角。
        fRestore
        保留的成员。 窗口在内部使用它。
        fIncUpdate
        保留的成员。 窗口在内部使用它。
        rgbReserved [16]
        保留的成员。 保留窗口内部使用的内存块。
            * 
       * 
       */
      PAINTSTRUCT ps;
      /**
       * BeginPaint函数为指定窗口进行绘图工作的准备，并用将和绘图有关的信息填充到一个PAINTSTRUCT结构中。
       * BOOL StretchBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, DWORD dwRop)；
       */
      HDC hdc = BeginPaint(hWnd, &ps);

      // Draw the image
      /**
       * StretchBlt，函数名。该函数从源矩形中复制一个位图到目标矩形，必要时按目标设备设置的模式进行图像的拉伸或压缩。
       * BOOL StretchBlt(HDC hdcDest, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, DWORD dwRop)；
       * hdcDest：指向目标设备环境的句柄。
        nXOriginDest：指定目标矩形左上角的X轴坐标，按逻辑单位表示坐标。
        nYOriginDest：指定目标矩形左上角的Y轴坐标，按逻辑单位表示坐标。
        nWidthDest：指定目标矩形的宽度，按逻辑单位表示宽度。
        nHeightDest：指定目标矩形的高度，按逻辑单位表示高度。
        hdcSrc：指向源设备环境的句柄。
        nXOriginSrc：指向源矩形区域左上角的X轴坐标，按逻辑单位表示坐标。
        nYOriginSrc：指向源矩形区域左上角的Y轴坐标，按逻辑单位表示坐标。
        nWidthSrc：指定源矩形的宽度，按逻辑单位表示宽度。
        nHeightSrc：指定源矩形的高度，按逻辑单位表示高度。
        dwRop：指定要进行的光栅操作。光栅操作码定义了系统如何在输出操作中组合颜色，这些操作包括刷子、源位图和目标位图等对象。参考BitBlt可了解常用的光栅操作码列表。
            下面列出了一些常见的光栅操作代码：
            BLACKNESS：表示使用与物理调色板的索引0相关的色彩来填充目标矩形区域，（对缺省的物理调色板而言，该颜色为黑色）。
            DSTINVERT：表示使目标矩形区域颜色取反。
            MERGECOPY：表示使用布尔型的AND（与）操作符将源矩形区域的颜色与特定模式组合一起。
            MERGEPAINT：通过使用布尔型的OR（或）操作符将反向的源矩形区域的颜色与目标矩形区域的颜色合并。
            NOTSRCCOPY：将源矩形区域颜色取反，再拷贝到目标矩形区域。
            NOTSRCERASE：使用布尔类型的OR（或）操作符组合源和目标矩形区域的颜色值，然后将合成的颜色取反。
            PATCOPY：将特定的模式拷贝到目标位图上。
            PATPAINT：通过使用布尔OR（或）操作符将源矩形区域取反后的颜色值与特定模式的颜色合并。然后使用OR（或）操作符将该操作的结果与目标矩形区域内的颜色合并。
            PATINVERT：通过使用XOR（异或）操作符将源和目标矩形区域内的颜色合并。
            SRCAND：通过使用AND（与）操作符来将源和目标矩形区域内的颜色合并。
            SRCCOPY：将源矩形区域直接拷贝到目标矩形区域。
            SRCERASE：通过使用AND（与）操作符将目标矩形区域颜色取反后与源矩形区域的颜色值合并。
            SRCINVERT：通过使用布尔型的XOR（异或）操作符将源和目标矩形区域的颜色合并。
            SRCPAINT：通过使用布尔型的OR（或）操作符将源和目标矩形区域的颜色合并。
            WHITENESS：使用与物理调色板中索引1有关的颜色填充目标矩形区域。（对于缺省物理调色板来说，这个颜色就是白色）。
       * 
       */
      StretchBlt(hdc, drawing_area_inset_, drawing_area_inset_, drawing_area_width_, drawing_area_height_, hdc_dib_, 0,
                 0, MNIST::width_, MNIST::height_, SRCCOPY);
      /**
       * GetStockObject是一个Windows API函数，该函数检索预定义的备用笔、刷子、字体或者调色板的句柄，函数原型是HGDIOBJ GetStockObject(int)。
       * fnObject：指定对象的类型，该参数可取如下值之一；
        BLACK_BRUSH：黑色画刷；DKGRAY_BRUSH：暗灰色画刷；
        DC_BRUSH：在Windows98,Windows NT 5.0和以后版本中为纯颜色画刷，缺省色为白色，可以用SetDCBrushColor函数改变颜色，更多的信息参见以下的注释部分。
        GRAY_BRUSH：灰色画刷笔；
        HOLLOW_BRUSH：空画刷（相当于NULL_BRUSH）；
        NULL_BRUSH：空画刷（相当于HOLLOW_BRUSH）；
        LTGRAY_BRUSH：亮灰色画刷；
        WHITE_BRUSH：白色画刷；
        BLACK_PEN：黑色钢笔；
        DC_PEN：在Windows98、Windows NT 5.0和以后版本中为纯色钢笔，缺省色为白色，使用SetDCPenColor函数可以改变色彩，更多的信息，参见下面的注释部分。
        WHITE_PEN：白色钢笔；
        ANSI_FIXED_FONT：在Windows中为固定间距（等宽）系统字体；
        ANSI_VAR_FONT：在Windows中为变间距（比例间距）系统字体；
        DEVICE_DEFAUCT_FONT：在WindowsNT中为设备相关字体；
        DEFAULT_GUI_FONT：用户界面对象缺省字体，如菜单和对话框；
        OEM_FIXED_FONT：原始设备制造商（OEM）相关固定间距（等宽）字体；
        SYSTEM_FONT：系统字体，在缺省情况下，系统使用系统字体绘制菜单，对话框控制和文本；
        SYSTEM_FIXED_FONT：固定间距（等宽）系统字体，该对象仅提供给兼容16位Windows版本；
        DEFAULT_PALETTE：缺省调色板，该调色板由系统调色板中的静态色彩组成
       * 
       */
      SelectObject(hdc, GetStockObject(BLACK_PEN));
      SelectObject(hdc, GetStockObject(NULL_BRUSH));
      /**
       * Rectangle是一个函数，使用该函数画一个矩形，可以用当前的画笔画矩形轮廓，用当前画刷进行填充。
       */
      Rectangle(hdc, drawing_area_inset_, drawing_area_inset_, drawing_area_inset_ + drawing_area_width_,
                drawing_area_inset_ + drawing_area_height_);

      constexpr int graphs_left = drawing_area_inset_ + drawing_area_width_ + 5;
      constexpr int graph_width = 64;
      SelectObject(hdc, brush_bars_);


      /**
       * min_element Finds the smallest element in the range 
       */
      auto least = *std::min_element(mnist_->results_.begin(), mnist_->results_.end());
      auto greatest = mnist_->results_[mnist_->result_];
      auto range = greatest - least;

      int graphs_zero = static_cast<int>(graphs_left - least * graph_width / range);

      // Hilight the winner
      RECT rc{graphs_left, static_cast<LONG>(mnist_->result_) * 16, graphs_left + graph_width + 128,
              static_cast<LONG>(mnist_->result_ + 1) * 16};
    
      FillRect(hdc, &rc, brush_winner_);

      // For every entry, draw the odds and the graph for it

      /**
       * SetBkMode，Windows API，设置指定DC的背景混合模式，背景混合模式用于与文本，填充画刷和当画笔不是实线时。
       */
      SetBkMode(hdc, TRANSPARENT);
      wchar_t value[80];
      for (unsigned i = 0; i < 10; i++) {
        int y = 16 * i;
        float result = mnist_->results_[i];
        /**
         * 函数wsprintf [1]()将一系列的字符和数值输入到缓冲区。
         * 返回写入的长度
         */
        auto length = wsprintf(value, L"%2d: %d.%02d", i, int(result), abs(int(result * 100) % 100));

        /**
         * TextOut，函数名。该函数用当前选择的字体、背景颜色和正文颜色将一个字符串写到指定位置。
         * hdc
            [输入] 设备环境的句柄
            nXStart
            [输入] 指定用于字符串对齐的基准点的逻辑X坐标。
            nYStart
            [输入] 指定用于字符串对齐的基准点的逻辑Y坐标。
            lpString
            [输入] 指向将被绘制字符串的指针。此字符串不必为以\0结束的，因为cbString中指定了字符串的长度。
            cbString
            [输入] 指定了字符串的长度。
         */
        TextOut(hdc, graphs_left + graph_width + 5, y, value, length);

        Rectangle(hdc, graphs_zero, y + 1, static_cast<int>(graphs_zero + result * graph_width / range), y + 14);
      }

      // Draw the zero line
      /***
       * MoveToEx是函数，功能是将当前绘图位置移动到某个具体的点，同时也可获得之前位置的坐标。
       */
      MoveToEx(hdc, graphs_zero, 0, nullptr);
      LineTo(hdc, graphs_zero, 16 * 10);
    /**
     * BeginPaint是函数为指定窗口进行绘图的开始。EndPaint是绘图的结束，释放绘图区，相似函数，GetDC () 与ReleaseDC () 。前者与后者的区别是，利用从GetDC()传回的句柄可以在整个客户区上绘图。
     */
      EndPaint(hWnd, &ps);
      return 0;
    }
    /**
     * WM_LBUTTONDOWN是一个Windows消息，该消息当用户在window客户区域点击鼠标左键的时候发送。
     */
    case WM_LBUTTONDOWN: {
      /**
       * 将鼠标捕获设置为属于当前线程的指定窗口。 
       * 当鼠标悬停在捕获窗口上时，或者在鼠标悬停在捕获窗口上且按钮仍然向下的情况下按下鼠标按钮时，SetCapture 将捕获鼠标输入。 一次只会有一个窗口捕获鼠标。
        如果鼠标光标位于另一个线程创建的窗口上，则仅当鼠标按钮按下时，系统才会将鼠标输入定向到指定的窗口。
        */
      SetCapture(hWnd);
      painting_ = true;
      int x = (GET_X_LPARAM(lParam) - drawing_area_inset_) / drawing_area_scale_;
      int y = (GET_Y_LPARAM(lParam) - drawing_area_inset_) / drawing_area_scale_;
      MoveToEx(hdc_dib_, x, y, nullptr);
      return 0;
    }

    case WM_MOUSEMOVE:
      if (painting_) {
        int x = (GET_X_LPARAM(lParam) - drawing_area_inset_) / drawing_area_scale_;
        int y = (GET_Y_LPARAM(lParam) - drawing_area_inset_) / drawing_area_scale_;
        LineTo(hdc_dib_, x, y);
        InvalidateRect(hWnd, nullptr, false);
      }
      return 0;

    /**
     * 发送到丢失鼠标捕获的窗口。
     */
    case WM_CAPTURECHANGED:
      painting_ = false;
      return 0;

    case WM_LBUTTONUP:
      ReleaseCapture();
      ConvertDibToMnist();
      /**
       * 
       * Run the model returning results in an Ort allocated vector.
       * The caller provides a list of inputs and a list of the desired outputs to return.
       */
      mnist_->Run();
       /**
       * InvalidateRect是一个函数，该函数向指定的窗体更新区域添加一个矩形，然后窗体跟新区域的这一部分将被重新绘制。
       * 
       * BOOL InvalidateRect（HWND hWnd,CONST RECT *lpRect,BOOL bErase）;
       *    hWnd：要更新的客户区所在的窗体的句柄。如果为NULL，则系统将在函数返回前重新绘制所有的窗口, 然后发送 WM_ERASEBKGND 和 WM_PAINT 给窗口过程处理函数。
            lpRect：无效区域的矩形代表，它是一个结构体指针，存放着矩形的大小。如果为NULL，全部的窗口客户区域将被增加到更新区域中。
            bErase：指出无效矩形被标记为有效后，是否重画该区域，重画时用预先定义好的画刷。当指定TRUE时需要重画。
       */
      InvalidateRect(hWnd, nullptr, true);
      return 0;

    case WM_RBUTTONDOWN:  // Erase the image
    {
      RECT rect{0, 0, MNIST::width_, MNIST::height_};
      FillRect(hdc_dib_, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
      /**
       * InvalidateRect是一个函数，该函数向指定的窗体更新区域添加一个矩形，然后窗体跟新区域的这一部分将被重新绘制。
       */
      InvalidateRect(hWnd, nullptr, false);
      return 0;
    }
    /*
    * WM_DESTROY
    * 窗口销毁后（调用DestroyWindow（）后），消息队列得到的消息。
    */
    case WM_DESTROY:
      /**
       * PostQuitMessage，函数名。该函数向系统表明有个线程有终止请求。通常用来响应WM_DESTROY消息。
       */
      PostQuitMessage(0);
      return 0;
  }
  /**
   * DefWindowProc函数调用缺省的窗口过程来为应用程序没有处理的任何窗口消息提供缺省的处理。该函数确保每一个消息得到处理。
   * hWnd：指向接收消息的窗口过程的句柄。
    Msg：指定消息类型。
    wParam：指定其余的、消息特定的信息。该参数的内容与Msg参数值有关。
    IParam：指定其余的、消息特定的信息。该参数的内容与Msg参数值有关。
    返回值：返回值就是消息处理结果，它与发送的消息有关。
  */
  return DefWindowProc(hWnd, message, wParam, lParam);
}