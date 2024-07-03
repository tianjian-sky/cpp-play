cmake_minimum_required(VERSION 3.20)
project(num_recognizer)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17) # 设置C++标准为11
set(onnx_version 1.19.0) # 根据下载的版本进行设置，本例使用1.10.0版本

# 使用find_package进行路径设置

if("$ENV{onnxruntime_ROOT}" STREQUAL "")
  if(WIN32)
      set(ENV{onnxruntime_ROOT} "D:\\develop\\test\\onnxruntime")
  elseif(APPLE)
	#TODO
  else()
	#TODO
  endif()
endif()
set(ZLIB_ROOT "D:\\develop\\test\\zlib-1.3.1\\install")
# find_package(onnxruntime 1.19 REQUIRED) # 指定依赖的最小版本
set(libpng_ROOT "D:\\develop\\test\\libpng-1.6.43\\build\\insall_debug")

find_package(ZLIB REQUIRED)
find_package(libpng REQUIRED)


add_library(num_recognizer SHARED src/num_recognizer.cpp)

include(GenerateExportHeader)
generate_export_header(num_recognizer)
set_target_properties(num_recognizer PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN 1
)

include(GenerateExportHeader)
generate_export_header(num_recognizer)
set_target_properties(num_recognizer PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN 1
)

target_include_directories(num_recognizer PUBLIC include ${CMAKE_BINARY_DIR})
target_link_libraries(num_recognizer PRIVATE png_shared)


get_target_property(a0 png_shared INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(a1 png_shared IMPORTED_IMPLIB)
get_target_property(a2 png_shared IMPORTED_LOCATION)
get_target_property(a3 png_shared IMPORTED_IMPLIB_DEBUG)
get_target_property(a4 png_shared IMPORTED_LOCATION_DEBUG)

message("CMAKE_BINARY_DIR:${CMAKE_BINARY_DIR}")
message("a0:${a0}")
message("a1:${a1}")
message("a2:${a2}")
message("a3:${a3}")
message("a4:${a4}")


target_compile_definitions(num_recognizer PRIVATE ORT_NO_EXCEPTIONS num_recognizer_EXPORTS)

add_executable(recognize cli/recognize.c)
target_link_libraries(recognize PRIVATE num_recognizer)