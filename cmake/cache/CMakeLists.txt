cmake_minimum_required(VERSION 3.10)
project(MatchOrder)

set(a 缓存变量 CACHE STRING)
set(a 缓存变量2 CACHE STRING)
set(a 普通变量)

message("\${a} : ${a}") # 普通变量
message("\$CACHE{a} : $CACHE{a}") #

set(b 缓存变量b CACHE STRING "" )
set(b 缓存变量b2 CACHE STRING "" )
set(b 普通变量b) # 普通变量和缓存变量同时存在，普通变量引用语法优先匹配普通变量

message("\${b} : ${b}") # 普通变量b
message("\$CACHE{b} : $CACHE{b}") #缓存变量b

set(c 缓存变量c CACHE STRING "")
set(c 缓存变量c2 CACHE STRING "" FORCE) # 不加force，后续忽略对该缓存变量的设置
set(c 普通变量c)

message("\${c} : ${c}") # 普通变量b
message("\$CACHE{c} : $CACHE{c}") #缓存变量b