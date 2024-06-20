cmake_minimum_required(VERSION 3.20)
project(num_recognizer)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 11) # 设置C++标准为11
set(onnx_version 1.19.0) # 根据下载的版本进行设置，本例使用1.10.0版本
# 请下载onnxruntime库的压缩包，并解压至该目录中
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
set(ZLIB_LIBRARY_DEBUG TRUE) # 如果只构建了zlibd.lib 则根据FindZLIB.cmake文件的查找逻辑 设置这个变量
find_package(onnxruntime 1.19 REQUIRED) # 指定依赖的最小版本
set(libpng_ROOT "D:\\develop\\test\\libpng-1.6.43\\build\\insall_debug")
find_package(ZLIB REQUIRED)
# find_package(libpng REQUIRED)

add_library(num_recognizer SHARED src/num_recognizer.cpp)

include(GenerateExportHeader)
generate_export_header(num_recognizer)
set_target_properties(num_recognizer PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN 1
)
# onnxruntime::onnxruntime


# target_include_directories(num_recognizer PUBLIC include ${CMAKE_BINARY_DIR})
# target_link_libraries(num_recognizer PRIVATE onnxruntime::onnxruntime png_shared)
# target_compile_definitions(num_recognizer PRIVATE ORT_NO_EXCEPTIONS num_recognizer_EXPORTS)

# add_library(zlib SHARED IMPORTED)
#target_include_directories(zlib INTERFACE "${ZLIB_ROOT}\\include")
# Full path to the import library for an IMPORTED target.
# Set this to the location of the ”.lib” part of a windows DLL. Ignored for non-imported targets.
#set_target_properties(zlib PROPERTIES IMPORTED_IMPLIB_DEBUG "${libpng_ROOT}\\lib\\libpng16d.lib")
#set_target_properties(zlib PROPERTIES IMPORTED_LOCATION_DEBUG "${libpng_ROOT}\\bin\\libpng16d.dll")


#1 链接动态库
add_library(png_shared SHARED IMPORTED)
target_include_directories(png_shared INTERFACE "${libpng_ROOT}\\include\\libpng16")
# Full path to the import library for an IMPORTED target.
# Set this to the location of the ”.lib” part of a windows DLL. Ignored for non-imported targets.
set_target_properties(png_shared PROPERTIES IMPORTED_IMPLIB "${libpng_ROOT}\\lib\\libpng16d.lib")
set_target_properties(png_shared PROPERTIES IMPORTED_LOCATION "${libpng_ROOT}\\bin\\libpng16d.dll")
set_target_properties(png_shared PROPERTIES IMPORTED_IMPLIB_DEBUG "${libpng_ROOT}\\lib\\libpng16d.lib")
set_target_properties(png_shared PROPERTIES IMPORTED_LOCATION_DEBUG "${libpng_ROOT}\\bin\\libpng16d.dll")
# set_target_properties(png_shared PROPERTIES IMPORTED_LOCATION "${libpng_ROOT}\\lib\\libpng16d.lib")
target_include_directories(num_recognizer PUBLIC include ${CMAKE_BINARY_DIR} "${libpng_ROOT}\\include\\libpng16")
#target_link_libraries(num_recognizer D:\\develop\\test\\zlib-1.3.1\\install\\lib\\zlibd.lib)
#target_link_libraries(num_recognizer "${libpng_ROOT}\\bin\\libpng16d.dll")
target_link_libraries(num_recognizer png_shared)




target_compile_definitions(num_recognizer PRIVATE ORT_NO_EXCEPTIONS num_recognizer_EXPORTS)

add_executable(recognize cli/recognize.c)
target_link_libraries(recognize PRIVATE num_recognizer)
