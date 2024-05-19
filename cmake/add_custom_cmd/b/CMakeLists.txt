cmake_minimum_required(VERSION 3.20)


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


project(custom-depfile)

add_executable(main2 main2.c)


# configure_file

# Copies an <input> file to an <output> file and substitutes variable values referenced as @VAR@, ${VAR}, $CACHE{VAR} or $ENV{VAR} in the input file content. 
# Each variable reference will be replaced with the current value of the variable, or the empty string if the variable is not defined. Furthermore, input lines of the form
# 宏替换

configure_file(mydep.d ${CMAKE_BINARY_DIR}/mydep.d)

add_custom_command(OUTPUT main2.c
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/main.c main2.c
    DEPENDS main.c
    DEPFILE mydep.d
)

# 多构建立几次， Generating main2.c日志不再出现，因为依赖未更新
# 修改依赖文件1.txt 或 2.txt后，Generating main2.c日志再次出现，因为依赖已经更新
