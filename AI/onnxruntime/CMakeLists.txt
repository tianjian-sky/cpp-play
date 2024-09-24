# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.13)

# Project
project(onnxruntime_samples C CXX)
if (WIN32)
 string(APPEND CMAKE_CXX_FLAGS " /W4")
else()
 string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")
 string(APPEND CMAKE_C_FLAGS " -Wall -Wextra")
endif()

#onnxruntime providers
option(onnxruntime_USE_CUDA "Build with CUDA support" OFF)
option(onnxruntime_USE_TENSORRT "Build with TensorRT support" OFF)
set(LIBPNG_ROOTDIR D:\\develop\\test\\libpng-1.6.43\\build\\insall_debug)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

if(NOT ONNXRUNTIME_ROOTDIR)
  if(WIN32)
    set(ONNXRUNTIME_ROOTDIR "D:\\develop\\test\\onnxruntime")
    set(ONNXRUNTIME_LIBDIR "${ONNXRUNTIME_ROOTDIR}\\buildWindowsNN\\RelWithDebInfo\\RelWithDebInfo")
else()
    set(ONNXRUNTIME_ROOTDIR "/usr/local")
  endif()
endif()
message("ONNXRUNTIME_ROOTDIR:${ONNXRUNTIME_ROOTDIR}")
# The ORT package has a different include directory structure to a local install via cmake.
# We added the path for the pre-built package above. Add the path for a local install to support either usage.
# TODO: If we want to support additional EPs being loadable from a local install we also need to add EP specific
# directories under /include/onnxruntime/core/providers
include_directories("${ONNXRUNTIME_ROOTDIR}/include"                           # Pre-built package
                    "${ONNXRUNTIME_ROOTDIR}/include/onnxruntime"               # Linux local install to /usr/local
                    "${ONNXRUNTIME_ROOTDIR}/include/onnxruntime/core/session") # Windows local install

link_directories("${ONNXRUNTIME_LIBDIR}")


#[===[==
    wil
    Windows Implementation Library
    The Windows Implementation Libraries (WIL) is a header-only C++ library created to make life easier for developers on Windows through readable type-safe C++ interfaces for common Windows coding patterns.

    include/wil/resource.h (documentation): Smart pointers and auto-releasing resource wrappers to let you manage Windows API HANDLEs, HWNDs, and other resources and resource handles with RAII semantics.
    include/wil/win32_helpers.h (documentation): Wrappers for API functions that save you the work of manually specifying buffer sizes, calling a function twice to get the needed buffer size and then allocate and pass the right-size buffer, casting or converting between types, and so on.
    include/wil/registry.h (documentation): Type-safe functions to read from, write to, and watch the registry. Also, registry watchers that can call a lambda function or a callback function you provide whenever a certain tree within the Windows registry changes.
    include/wil/result.h (documentation): Preprocessor macros to help you check for errors from Windows API functions, in many of the myriad ways those errors are reported, and surface them as error codes or C++ exceptions in your code.
    include/wil/Tracelogging.h: This file contains the convenience macros that enable developers define and log telemetry. These macros use TraceLogging API to log data. This data can be viewed in tools such as Windows Performance Analyzer.

#==]===]
if(WIN32)
  add_library(wil INTERFACE)

  FetchContent_Declare(
      microsoft_wil
      URL https://github.com/microsoft/wil/archive/refs/tags/v1.0.220914.1.zip
    )
  FetchContent_Populate(microsoft_wil)
  target_include_directories(wil INTERFACE ${microsoft_wil_SOURCE_DIR}/include)
  set(WIL_LIB wil)
endif()

# On Linux the samples use libjpeg and libpng for decoding images.
# On Windows they use Windows Image Component(WIC)
if(NOT WIN32)
    find_package(JPEG)
    if(LIBPNG_ROOTDIR)
      set(PNG_FOUND true)
      set(PNG_LIBRARIES png16)
      set(PNG_INCLUDE_DIRS "${LIBPNG_ROOTDIR}/include/libpng16")
      set(PNG_LIBDIR "${LIBPNG_ROOTDIR}/lib")
    else()
      find_package(PNG)
    endif()
endif()

if(onnxruntime_USE_CUDA)
  add_definitions(-DUSE_CUDA)
endif()
if(onnxruntime_USE_TENSORRT)
  add_definitions(-DUSE_TENSORRT)
endif()
if(onnxruntime_USE_DML)
  message("Enabling DML")
  add_definitions(-DUSE_DML)
endif()

# Windows might have an onnxruntime.dll in the system directory so it's more robust to manually copy the dlls to
# the output dir. Define a function to do so. This is called from the cmake file in the subdirectories.
function(copy_ort_dlls target_name)
  if (MSVC)
      file(GLOB ORT_DLLS ${ONNXRUNTIME_LIBDIR}/*.dll)
      foreach(ORT_DLL ${ORT_DLLS})
          add_custom_command(TARGET ${target_name} POST_BUILD
                            COMMAND ${CMAKE_COMMAND} -E copy ${ORT_DLL}  $<TARGET_FILE_DIR:${target_name}>)
      endforeach()
  endif()
endfunction()

# some examples require a Windows build environment
if(WIN32)
#   add_subdirectory(imagenet)
  add_subdirectory(1_MINST)
  add_subdirectory(2_MODEL_EXPLORER)
  add_subdirectory("3_OpenVINO_EP\\windows")
endif()
# add_subdirectory(squeezenet)
if(WIN32 OR PNG_FOUND)
#   add_subdirectory(fns_candy_style_transfer)
endif()
# add_subdirectory(model-explorer)
