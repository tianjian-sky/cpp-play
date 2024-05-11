cmake_minimum_required(VERSION 3.10)

project(use_pre_built_static_lib VERSION 1.0.0)

message("${mylib_LIBRARY}")

# 库类型
#
#   一般库
#       STATIC
#       SHARED
#           POSITION_INDEPENDENT_CODE=TRUE
#       MODULE
#           仅仅用于运行时动态加载 dlopen...
#   目标库
#       OBJECT
#           只是生产一系列目标文件，并不链接或打包
#           由于不会输出文件只是逻辑概念，因此所有是要目标库的地方需要加上表达式  $<TARGET_OBJECTS:my_obj_lib>
#           target_link_libraries(main  $<TARGET_OBJECTS:my_obj_lib>)
#
#   伪目标
#       接口库  自身不需要编译，但有一定构建要求，如：头文件
#           INTERFACE
#       导入目标    如第三方库中的构建目标，已经构建好，无需再构建
#
#       别名目标    另一个构建目标的别名


# 自动提取原文件
# 1. file(GLOB ...)
#       CONFIGURE_DEPENDS 每次构件时重新刷文件列表
# 2. aux_source_directory()

file(GLOB NEED_COMPILE_SOURCE_FILES RELATIVE "${CMAKE_CURRENT_LIST_DIR}" CONFIGURE_DEPENDS  "*.c")
aux_source_directory("." NEED_COMPILE_SOURCE_FILES_2)

message("NEED_COMPILE_SOURCE_FILES:"${NEED_COMPILE_SOURCE_FILES})
message("NEED_COMPILE_SOURCE_FILES2:"${NEED_COMPILE_SOURCE_FILES_2})

add_library(my_obj_lib OBJECT ../static_lib/lib.c)

add_executable(main ${NEED_COMPILE_SOURCE_FILES})
target_link_libraries(main  $<TARGET_OBJECTS:my_obj_lib>)


add_executable(main2 ${NEED_COMPILE_SOURCE_FILES_2})
target_link_libraries(main2  $<TARGET_OBJECTS:my_obj_lib>)

set(CMAKE_INSTALL_PREFIX  ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS main RUNTIME DESTINATION my_use_obj_lib)