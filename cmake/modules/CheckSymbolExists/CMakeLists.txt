cmake_minimum_required(VERSION 3.10)
project(check-symbol-exists)
include(CheckSymbolExists)

check_symbol_exists(printf "stdio.h" res) # 输出：
# -- Looking for printf
# -- Looking for printf - found
message("${res}") # 输出：1