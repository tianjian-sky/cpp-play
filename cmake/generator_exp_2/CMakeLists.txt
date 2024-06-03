cmake_minimum_required(VERSION 3.2)

project(gen_exp_2)

add_custom_target(debug-gen-exp COMMAND ${CMAKE_COMMAND} -E echo "CONFIG:  $<CONFIG>")

add_custom_target(debug-gen-exp2 ALL 
COMMAND ${CMAKE_COMMAND} -E echo "CONFIG:  $<BOOL:ABC>"
COMMAND ${CMAKE_COMMAND} -E echo "CONFIG:  $<BOOL:NO>"
COMMAND ${CMAKE_COMMAND} -E echo "CONFIG:  $<NOT:$<BOOL:NO>>"
COMMAND ${CMAKE_COMMAND} -E echo "CONFIG:  $<BOOL:X-NOTFOUND>"
)