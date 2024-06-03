cmake_minimum_required(VERSION 3.2)

project(gen_exp_3)

add_custom_target(main a.c b.cpp main.c)

target_compile_definitions(main PRIVATE
$<$<COMPILE_LANGUAGE:C>:A=1>
$<$<COMPILE_LANGUAGE:CXX>:A=10>
)