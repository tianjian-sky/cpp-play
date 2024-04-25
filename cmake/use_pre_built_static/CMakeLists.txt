cmake_minimum_required(VERSION 3.10)

project(use_pre_built_static_lib VERSION 1.0.0)

find_library(mylib_LIBRARY mylib PATHS ../static_lib/build/Release)

message("${mylib_LIBRARY}")

add_executable(main main.c)

target_link_libraries(main ${mylib_LIBRARY})
set(CMAKE_INSTALL_PREFIX  ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS main RUNTIME DESTINATION my_use_pre_built_static_lib)

