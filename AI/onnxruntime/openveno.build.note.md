[Build OpenVINO™ Runtime for Windows systems
](https://github.com/openvinotoolkit/openvino/blob/2024.3.0/docs/dev/build_windows.md)

[openvino-samples](https://docs.openvino.ai/2024/learn-openvino/openvino-samples/model-creation.html)


## 步骤

* 下载最新的Squeezenet model
```
  Download the latest Squeezenet model from the ONNX Model Zoo.
   This example was adapted from [ONNX Model Zoo](https://github.com/onnx/models).Download the latest version of the [Squeezenet](https://github.com/onnx/models/tree/master/vision/classification/squeezenet) model from here.
```
* 重新编译onnx，加入--use_openvino 开启对openvino的支持
  https://onnxruntime.ai/docs/build/eps.html

  ```
   <openvino_install_directory>\setupvars.bat
  
  ```
* 安装git子模块，安装失败的则手动去git仓库拉取main分支，存放于对应位置
* 安装 Intel® Graphics Driver for Windows 
* 或者不勾选ENABLE_INTEL_GPU（硬件设备不支持或不想使用）
* 不勾选 ENABLE_INTEL_NPU （硬件设备不支持或不想使用）
* 配置opencl

* 安装Chocolatey (通过管理员方式打开cmd)
* 通过Chocolatey 安装shellCheck
* 下载模型 
* 拷贝缺少的dll到调用onnxruntime.dll，openvino.dll的exe文件夹处 ,可通过

```
add_custom_command(TARGET run_squeezenet POST_BUILD 
				COMMAND ${CMAKE_COMMAND} -E copy_if_different
				"${ORTDll}"              
				$<TARGET_FILE_DIR:run_squeezenet>)
```
```
choco install shellcheck
```

## SqueezeNet
A light-weight CNN model providing AlexNet level accuracy with 50x fewer parameters.
Top-5 error from paper - ~20%

## find_program
This command is used to find a program. A cache entry, or a normal variable if NO_CACHE is specified, named by <VAR> is created to store the result of this command. If the program is found the result is stored in the variable and the search will not be repeated unless the variable is cleared. If nothing is found, the result will be <VAR>-NOTFOUND.

```
find_program (
          <VAR>
          name | NAMES name1 [name2 ...] [NAMES_PER_DIR]
          [HINTS [path | ENV var]... ]
          [PATHS [path | ENV var]... ]
          [REGISTRY_VIEW (64|32|64_32|32_64|HOST|TARGET|BOTH)]
          [PATH_SUFFIXES suffix1 [suffix2 ...]]
          [VALIDATOR function]
          [DOC "cache documentation string"]
          [NO_CACHE]
          [REQUIRED]
          [NO_DEFAULT_PATH]
          [NO_PACKAGE_ROOT_PATH]
          [NO_CMAKE_PATH]
          [NO_CMAKE_ENVIRONMENT_PATH]
          [NO_SYSTEM_ENVIRONMENT_PATH]
          [NO_CMAKE_SYSTEM_PATH]
          [NO_CMAKE_INSTALL_PREFIX]
          [CMAKE_FIND_ROOT_PATH_BOTH |
           ONLY_CMAKE_FIND_ROOT_PATH |
           NO_CMAKE_FIND_ROOT_PATH]
         )
```

NAMES 如：cmake,gcc...
Specify one or more possible names for the program.

When using this to specify names with and without a version suffix, we recommend specifying the unversioned name first so that locally-built packages can be found before those provided by distributions.

## find_package 的 config模式

```
Search prefixes unique to the current <PackageName> being found. See policy CMP0074.

New in version 3.12.

Specifically, search prefixes specified by the following variables, in order:

<PackageName>_ROOT CMake variable, where <PackageName> is the case-preserved package name.

<PACKAGENAME>_ROOT CMake variable, where <PACKAGENAME> is the upper-cased package name. See policy CMP0144.

New in version 3.27.

<PackageName>_ROOT environment variable, where <PackageName> is the case-preserved package name.

<PACKAGENAME>_ROOT environment variable, where <PACKAGENAME> is the upper-cased package name. See policy CMP0144.

New in version 3.27.
```
```
set(OpenCV_ROOT "D:\\develop\\test\\opencv-4.x\\build\\install") # 找opencv模块下现有的config脚本
FIND_PACKAGE(OpenCV REQUIRED)
```

## add_custom_command POST_BUILD 指定在某个target构建完成后执行某个命令（如：复制dll）
```
file(GLOB DEP_FILES ${CMAKE_CURRENT_LIST_DIR}/deps/*.*)
foreach(ORTDll IN LISTS DEP_FILES)
add_custom_command(TARGET run_squeezenet POST_BUILD 
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${ORTDll}"              
            $<TARGET_FILE_DIR:run_squeezenet>)
endforeach()
```

## include(GNUInstallDirs)
Define GNU standard installation directories

* CMAKE_INSTALL_<dir>
* CMAKE_INSTALL_FULL_<dir>

where <dir> is one of:
```
BINDIR
user executables (bin)

SBINDIR
system admin executables (sbin)

LIBEXECDIR
program executables (libexec)

SYSCONFDIR
read-only single-machine data (etc)

SHAREDSTATEDIR
modifiable architecture-independent data (com)

LOCALSTATEDIR
modifiable single-machine data (var)

RUNSTATEDIR
New in version 3.9: run-time variable data (LOCALSTATEDIR/run)

LIBDIR
object code libraries (lib or lib64)

On Debian, this may be lib/<multiarch-tuple> when CMAKE_INSTALL_PREFIX is /usr.

INCLUDEDIR
C header files (include)

OLDINCLUDEDIR
C header files for non-gcc (/usr/include)

DATAROOTDIR
read-only architecture-independent data root (share)

DATADIR
read-only architecture-independent data (DATAROOTDIR)

INFODIR
info documentation (DATAROOTDIR/info)

LOCALEDIR
locale-dependent data (DATAROOTDIR/locale)

MANDIR
man documentation (DATAROOTDIR/man)

DOCDIR
documentation root (DATAROOTDIR/doc/PROJECT_NAME)
```

## 设备安装类 与 devguid.h

设备安装类 提供了一种机制，用于对以相同方式安装和配置的设备进行分组。 例如，所有 CD-ROM 驱动器都属于 CDROM 设置类。

设备接口类 提供了一种机制，用于根据共享特征或功能对设备进行分组。 驱动程序和用户应用程序可以注册以接收属于特定接口类的任何设备的到达或删除通知，而不是跟踪单个设备在系统中的状态。

Windows 设备安装类在系统文件 Devguid.h 中定义。 此文件为安装类定义一系列 GUID。 但是， Devguid.h 中表示的设备安装类不得与设备 接口 类混淆。 Devguid.h 文件仅包含安装类的 GUID。


## 什么是NPU？

NPU的全称是Neural network Processing Unit，翻译过来叫“神经网络处理单元”。你可以将它看成是一种特殊的处理器，NPU利用电路模拟人类的神经元和突触结构，来处理特定的任务。

## ONNX Runtime Execution Providers
[Runtime Execution Providers](https://onnxruntime.ai/docs/execution-providers/ONNX)

ONNX Runtime works with different hardware acceleration libraries through its extensible Execution Providers (EP) framework to optimally execute the ONNX models on the hardware platform. This interface enables flexibility for the AP application developer to deploy their ONNX models in different environments in the cloud and the edge and optimize the execution by taking advantage of the compute capabilities of the platform.

ONNX Runtime supports many different execution providers today. Some of the EPs are in production for live service, while others are released in preview to enable developers to develop and customize their application using the different options.

CPU	GPU	IoT/Edge/Mobile	Other
Default CPU	NVIDIA CUDA	Intel OpenVINO	Rockchip NPU (preview)
Intel DNNL	NVIDIA TensorRT	ARM Compute Library (preview)	Xilinx Vitis-AI (preview)
TVM (preview)	DirectML	Android Neural Networks API	Huawei CANN (preview)
Intel OpenVINO	AMD MIGraphX	ARM-NN (preview)	AZURE (preview)
XNNPACK	Intel OpenVINO	CoreML (preview)	 
 	AMD ROCm	TVM (preview)	 
 	TVM (preview)	Qualcomm QNN	 
 	 	XNNPACK	 

