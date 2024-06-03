cmake_minimum_required(VERSION 3.2)

project(gen_exp_1)

add_executable(main $<$<CONFIG:Debug>:debug.c> $<$<CONFIG:Release>:release.c> )