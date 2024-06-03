cmake_minimum_required(VERSION 3.15)

project(genex_eval)

add_executable(main main.c)


# GENEX_EVAL
# Content of expr evaluated as a generator expression in the current context. This enables consumption of generator expressions whose evaluation results itself in generator expressions.


# 设置main的自定义目标属性CUSTOM_EXP的值
set_property(TARGET main PROPERTY CUSTOM_EXP "$<CONFIG>") # set_property不支持生成器表达式

add_custom_target(debug-gen-exp ALL
    COMMAND ${CMAKE_COMMAND} -E echo # 输出Debug或Release等
    "$<GENEX_EVAL:$<TARGET_PROPERTY:main,CUSTOM_EXP>>" 
)