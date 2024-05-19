cmake_minimum_required(VERSION 3.10)

project(transitiity_2 VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)

message("${mylib_LIBRARY}")
message("CMATE_BUILD_TYPE:"${CMATE_BUILD_TYPE})

message("is  mac" ${APPLE})

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

# b     <-   a
# main  <- b

add_library(A STATIC "./liba/a.cpp")
target_include_directories(A PUBLIC "./liba")


add_library(B STATIC "./libb/b.cpp")
target_include_directories(B PUBLIC "./libb")

target_link_directories(B PRIVATE A)

add_executable(main "./main.cpp")

target_link_directories(main PRIVATE B)

