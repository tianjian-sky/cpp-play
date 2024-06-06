cmake_minimum_required(VERSION 3.20)
project(find-onnxruntime)

# CMAKE_MODULE_PATH 
# specifying a search path for CMake modules to be loaded by the include() or find_package() commands before checking the default modules that come with CMake

# CMAKE_CURRENT_LIST_DIR
# Full directory of the listfile currently being processed.
message("CMAKE_CURRENT_LIST_DIR:${CMAKE_CURRENT_LIST_DIR}")
message("CMAKE_MODULE_PATH:${CMAKE_MODULE_PATH}")
message("ISWIN32:${WIN32}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR};${CMAKE_MODULE_PATH}")
set(CMAKE_CXX_STANDARD 11) # 设置C++标准为11
set(onnx_version 1.19.0) # 根据下载的版本进行设置，本例使用1.10.0版本


# ENV
# Operator to read environment variables.
# set(ProgramFiles_x86 "$ENV{ProgramFiles\(x86\)}")
# Environment Variables are like ordinary Variables, with the following differences:
#	Scope
#	Environment variables have global scope in a CMake process. They are never cached.
#	References
#	Variable References have the form $ENV{<variable>}, using the ENV operator.



# 请下载onnxruntime库的压缩包，并解压至该目录中
if("$ENV{onnxruntime_ROOT}" STREQUAL "")
  if(WIN32)
      set(ENV{onnxruntime_ROOT} "D:\\develop\\test\\onnxruntime")
  elseif(APPLE)
      # TODO
  else()
      #TODO
  endif()
endif()

find_package(onnxruntime ${onnx_version}) # 指定依赖的最小版本
add_executable(main main.cpp)
target_link_libraries(main onnxruntime::onnxruntime)
target_compile_definitions(main PRIVATE ORT_NO_EXCEPTIONS)