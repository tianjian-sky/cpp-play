# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.13)

# Project
project(onnxruntime_samples C CXX)
string(APPEND CMAKE_CXX_FLAGS " /W4")

#onnxruntime-openvino provider
option(onnxruntime_USE_OPENVINO "Build with OpenVINO support" OFF)
option(OPENCV_ROOTDIR "D:\\develop\\test\\opencv-4.x\\build\\install")
option(ONNXRUNTIME_ROOTDIR "onnxruntime root dir")
option(OPENCL_LIB "OPENCL_LIB" "D:\\develop\\test\\OpenCL-SDK-main\\install\\lib")
option(OPENCL_INCLUDE "OPENCL_INCLUDE" "D:\\develop\\test\\OpenCL-SDK-main\\install\\include")

# set onnxruntime_USE_OPENVINO
set(onnxruntime_USE_OPENVINO ON)
set(ONNXRUNTIME_ROOTDIR "D:\\develop\\test\\onnxruntime")
if(NOT ONNXRUNTIME_ROOTDIR)
  set(ONNXRUNTIME_ROOTDIR "C:/Program Files/onnxruntime")
endif()

if(NOT OPENCV_ROOTDIR)
  set(OPENCV_ROOTDIR "D:\\develop\\test\\opencv-4.x\\build\\install")
endif()


if(NOT OPENCL_LIB)
  set(OPENCL_LIB "D:\\develop\\test\\OpenCL-SDK-main\\install\\lib")
endif()

if(NOT OPENCL_INCLUDE)
  set(OPENCL_INCLUDE "D:\\develop\\test\\OpenCL-SDK-main\\install\\include")
endif()

include_directories("${ONNXRUNTIME_ROOTDIR}/include/onnxruntime/core/session")
link_directories("${ONNXRUNTIME_ROOTDIR}\\buildWindowsNN\\RelWithDebInfo\\RelWithDebInfo")

message("ONNXRUNTIME_ROOTDIR:${ONNXRUNTIME_ROOTDIR}")
message("OPENCV_ROOTDIR:${OPENCV_ROOTDIR}")
message("OPENCL_LIB:${OPENCL_LIB}")

if(OPENCV_ROOTDIR)
  set(OPENCV_FOUND true)
  set(OPENCV_INCLUDE_DIRS "${OPENCV_ROOTDIR}/include")
  set(OPENCV_LIBDIR "${OPENCV_ROOTDIR}/x64/vc17/lib")
  file(GLOB OPENCV_DEBUG_LIBRARIES ${OPENCV_LIBDIR}/opencv_world4100.lib) # 修改成对应的lib文件
  file(GLOB OPENCV_RELEASE_LIBRARIES ${OPENCV_LIBDIR}/opencv_world4100.lib) # 修改成对应的lib文件
  #[===[==
    list(FILTER <list> {INCLUDE | EXCLUDE} REGEX <regex>)
    nserts elements to the list to the specified index. 
    It is an error to specify an out-of-range index.
    Valid indexes are 0 to N where N is the length of the list, inclusive. An empty list has length 0. If no variable named <list> exists in the current scope its value is treated as empty and the elements are inserted in that empty list.

  ==]===]#
  list(FILTER OPENCV_RELEASE_LIBRARIES EXCLUDE REGEX ".*d\\.lib")
endif()

if(OPENCL_LIB AND OPENCL_INCLUDE)
  set(OPENCL_FOUND true)
endif()

if(onnxruntime_USE_OPENVINO)
  add_definitions(-DUSE_OPENVINO)
endif()

if(OPENCV_FOUND)
  add_subdirectory(squeezenet_classification)
endif()

if(OPENCL_FOUND)
  add_subdirectory(squeezenet_classification_io_buffer)
endif()

add_subdirectory(model-explorer)
