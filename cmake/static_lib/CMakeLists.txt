cmake_minimum_required(VERSION 3.10)

project(mylib VERSION 1.0.0)

add_library(mylib STATIC lib.c)

# CMAKE_CURRENT_SOURCE_DIR 当前路径
# 不设置CMAKE_INSTALL_PREFIX的话，默认在windows会安装到C:\Program Files (x86)下
set(CMAKE_INSTALL_PREFIX  ${CMAKE_CURRENT_SOURCE_DIR})



# install命令被用来指定安装目标。TARGETS关键字后面跟着的是要安装的目标名称。
# RUNTIME和ARCHIVE指定了安装时的文件类型，DESTINATION关键字后面是文件安装的目的地路径。FILES命令用于安装单个的文件。

# 安装可执行文件
# install(TARGETS MyExecutable RUNTIME DESTINATION bin)
# 安装静态库文件
# install(TARGETS MyLibrary ARCHIVE DESTINATION lib)
# 安装资源文件或其他文件
# install(FILES mydata.txt DESTINATION share/MyProject)


install(TARGETS mylib ARCHIVE DESTINATION my_static_lib)

set(CPACK_PACKAGE_NAME "my_static_lib")

# include命令 执行cmake程序
include(Cpack) # 生成打包相关的配置

