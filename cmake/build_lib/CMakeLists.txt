cmake_minimum_required(VERSION 3.14)

project(proj_build_lib VERSION 1.0.0)



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
#       别

add_library(my_dylib SHARED ../static_lib/lib.c)

add_library(my_obj_lib OBJECT ../static_lib/lib.c)


add_library(my_dylib_exclude_all SHARED EXCLUDE_FROM_ALL main.c)
# 若不指定库类型参数，可以在命令行中指定BUILD_SHARED_LIBS 参数
SET(BUILD_SHARED_LIBS OFF)
add_library(my_slib_exclude_all EXCLUDE_FROM_ALL main.c)
