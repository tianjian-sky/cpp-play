cmake_minimum_required(VERSION 3.16)
project(find-threads)

# 调用FindThreads模块，它会创建一个导入目标Threads::Threads


# 查找模式

# Module mode
# CMake searches for a file called Find<PackageName>.cmake, looking first in the locations listed in the CMAKE_MODULE_PATH, 、
# then among the Find Modules provided by the CMake installation. If the file is found, it is read and processed by CMake. It is responsible for finding the package, checking the version, and producing any needed messages. Some Find modules provide limited or no support for versioning; check the Find module's documentation.

## Config mode
# CMake searches for a file called <lowercasePackageName>-config.cmake or <PackageName>Config.cmake. 
# It will also look for <lowercasePackageName>-config-version.cmake or <PackageName>ConfigVersion.cmake if version details were specified (see Config Mode Version Selection for an explanation of how these separate version files are used).

# In config mode, the command can be given a list of names to search for as package names. The locations where CMake searches for the config and version files is considerably more complicated than for Module mode (see Config Mode Search Procedure).

find_package(Threads) 

add_executable(main main.cpp)
# 如果不链接Threads::Threads，在Linux环境中构建会出错：
# undefined reference to `pthread_create'
target_link_libraries(main PRIVATE Threads::Threads)