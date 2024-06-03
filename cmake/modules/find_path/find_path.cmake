if(WIN32)
    find_path(notepad_path notepad.exe)
    message("${notepad_path}") # 输出：C:/Windows/System32
endif()

# 使用tree .查看当前目录的树形结构
# ├── a
# │   └── b
# │       └── 1.txt     
# ├── b
# │   └── a
# │       └── 1.txt     
# └── find_path.cmake   

#[[
This command is used to find a directory containing the named file. A cache entry, or a normal variable if NO_CACHE is specified, named by <VAR> is created to store the result of this command. If the file in a directory is found the result is stored in the variable and the search will not be repeated unless the variable is cleared. If nothing is found, the result will be <VAR>-NOTFOUND.

find_path (
          <VAR>
          name | NAMES name1 [name2 ...]
          [HINTS [path | ENV var]... ]
          [PATHS [path | ENV var]... ]
          [REGISTRY_VIEW (64|32|64_32|32_64|HOST|TARGET|BOTH)]
          [PATH_SUFFIXES suffix1 [suffix2 ...]]
          [VALIDATOR function]
          [DOC "cache documentation string"]
          [NO_CACHE]
          [REQUIRED]
          [NO_DEFAULT_PATH]
          [NO_PACKAGE_ROOT_PATH]
          [NO_CMAKE_PATH]
          [NO_CMAKE_ENVIRONMENT_PATH]
          [NO_SYSTEM_ENVIRONMENT_PATH]
          [NO_CMAKE_SYSTEM_PATH]
          [NO_CMAKE_INSTALL_PREFIX]
          [CMAKE_FIND_ROOT_PATH_BOTH |
           ONLY_CMAKE_FIND_ROOT_PATH |
           NO_CMAKE_FIND_ROOT_PATH]
         )
]]

find_path(res1 1.txt HINTS a b PATH_SUFFIXES b)
message("${res1}") # 输出：.../CMake-Book/src/ch009/find_path/a/b

find_path(res2 1.txt HINTS a b PATH_SUFFIXES a)
message("${res2}") # 输出：.../CMake-Book/src/ch009/find_path/b/a
