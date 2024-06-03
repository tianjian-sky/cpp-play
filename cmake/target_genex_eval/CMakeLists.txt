cmake_minimum_required(VERSION 3.12)

project(genex_eval)


# GENEX_EVAL
# Content of expr evaluated as a generator expression in the current context. This enables consumption of generator expressions whose evaluation results itself in generator expressions.

add_executable(main main.c)
add_executable(main2 MACOSX_BUNDLE main.c)

set_property(TARGET main PROPERTY A "$<TARGET_PROPERTY:A>") #set_property本身不支持生成器表达式
set_property(TARGET main2 PROPERTY A "main2.A")

add_custom_target(debug-gen-exp ALL
    COMMAND ${CMAKE_COMMAND} -E echo # 输出main2.A
    "$<TARGET_GENEX_EVAL:main2,$<TARGET_PROPERTY:main,A>>" 
)