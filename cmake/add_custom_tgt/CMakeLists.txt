cmake_minimum_required(VERSION 3.20)

project(custom-target)



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



# add_custom_target
# 默认情况只有指定ALL参数的目标会被构建

# 指定构建目标
#  cmake --build ./build --target a b
add_custom_target(a
    ${CMAKE_COMMAND} -E echo "custom target: a"
    SOURCES a.c
    VERBATIM)


# 依赖关系建立
# a. 通过target_link_libraries(...)
# b. 通过add_dependencies(...)  用于没有明显链接关系情况
add_dependencies(a b)
add_custom_target(b ALL
    ${CMAKE_COMMAND} -E echo "custom target: b"
    SOURCES b.c
    VERBATIM)