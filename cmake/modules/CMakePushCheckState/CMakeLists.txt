cmake_minimum_required(VERSION 3.10)
project(push-check-state)
include(CMakePushCheckState)

include(CheckIncludeFiles)


# 状态栈包括如下变量
# CMAKE_REQUIRED_FLAGS
# CMAKE_REQUIRED_DEFINITIONS
# CMAKE_REQUIRED_INCLUDES
# CMAKE_REQUIRED_LINK_OPTIONS
# CMAKE_REQUIRED_LIBRARIES
# CMAKE_REQUIRED_QUIET

set(CMAKE_REQUIRED_INCLUDES "${CMAKE_SOURCE_DIR}")
check_include_files("a.h" res) # 输出：
# -- Looking for include file a.h
# -- Looking for include file a.h - found

cmake_push_check_state()

set(CMAKE_REQUIRED_INCLUDES "${CMAKE_SOURCE_DIR}/b")
check_include_files("b.h" res2) # 输出：
# -- Looking for include file b.h
# -- Looking for include file b.h - found

cmake_pop_check_state()

#set(CMAKE_REQUIRED_INCLUDES "${CMAKE_SOURCE_DIR}")
check_include_files("a.h" res3) # 输出：
# -- Looking for include file a.h
# -- Looking for include file a.h - found