cmake_minimum_required(VERSION 3.20)
project(find-library)

# 使用tree .查看当前目录的树形结构
# ├── CMakeLists.txt
# ├── dir1
# │   ├── b.lib
# │   └── libb.a
# └── dir2
#     ├── a.lib
#     └── liba.a
# 注意，在不同平台中的输出结果不同

#[[
This command is used to find a library

find_library (
          <VAR>
          name | NAMES name1 [name2 ...] [NAMES_PER_DIR]
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

find_library(res1 NAMES a b HINTS dir1 dir2)
message("${res1}") # 输出.../find_library/dir2/ liba.a 或 a.lib

find_library(res2 NAMES a b NAMES_PER_DIR HINTS dir1 dir2)
message("${res2}") # 输出.../find_library/dir1/ libb.a 或 b.lib
