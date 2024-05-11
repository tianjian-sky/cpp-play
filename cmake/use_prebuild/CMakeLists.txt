cmake_minimum_required(VERSION 3.10)
project(use_pre_build_static_lib VERSION 1.0.0)

find_library(mylib_LIB myblib PATHS "../static_lib/install/lib")

message("${mylib_LIB}")

# install(TARGETS main) # 把构建出的文件安装到不同位置 只有在cmake --install阶段生效

add_executable(main main.c)

target_link_libraries(main ${mylib_LIB})
