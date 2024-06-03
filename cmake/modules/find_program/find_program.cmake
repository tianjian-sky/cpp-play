#[[

This command is used to find a program. A cache entry, or a normal variable if NO_CACHE is specified, named by <VAR> is created to store the result of this command. If the program is found the result is stored in the variable and the search will not be repeated unless the variable is cleared. If nothing is found, the result will be <VAR>-NOTFOUND.
]]


find_program(res NAMES cmake)
message("${res}") # 输出的值应与${CMAKE_COMMAND}一致
