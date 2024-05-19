cmake_minimum_required(VERSION 3.10)

project(phony_target_import_lib VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)

message("${mylib_LIBRARY}")
message("CMATE_BUILD_TYPE:"${CMATE_BUILD_TYPE})

message("is  mac" ${APPLE})

# 库类型
#
#   一般库
#       STATIC
#       SHARED
#           POSITION_INDEPENDENT_CODE=TRUE
#       MODULE
#           仅仅用于运行时动态加载 dlopen...
#   目标库
#       OBJECT
#           只是生产一系列目标文件，并不链接或打包
#           由于不会输出文件只是逻辑概念，因此所有是要目标库的地方需要加上表达式  $<TARGET_OBJECTS:my_obj_lib>
#           target_link_libraries(main  $<TARGET_OBJECTS:my_obj_lib>)
#
#   伪目标
#       接口库  自身不需要编译，但有一定构建要求，如：头文件
#           INTERFACE
#       导入目标    如第三方库中的构建目标，已经构建好，无需再构建
#
#       别名目标    另一个构建目标的别名

# 自动提取原文件
# 1. file(GLOB ...)
#       CONFIGURE_DEPENDS 每次构件时重新刷文件列表
# 2. aux_source_directory()

file(GLOB NEED_COMPILE_SOURCE_FILES RELATIVE "${CMAKE_CURRENT_LIST_DIR}" CONFIGURE_DEPENDS  "*.cp?p?")
aux_source_directory("." NEED_COMPILE_SOURCE_FILES_2)

message("NEED_COMPILE_SOURCE_FILES:"${NEED_COMPILE_SOURCE_FILES})
message("NEED_COMPILE_SOURCE_FILES2:"${NEED_COMPILE_SOURCE_FILES_2})

# 目标库 TODO:
# add_library(my_obj_lib OBJECT ../static_lib/lib.c)



# target_link_libraries(<target> <PRIVATE|PUBLIC|INTERFACE> <item>...[<PRIVATE|PUBLIC|INTERFACE> <item>...]...)

# Each of the commands has a PRIVATE, PUBLIC and INTERFACE mode. 
# The PRIVATE mode populates only the non-INTERFACE_ variant of the target property and 
# the INTERFACE mode populates only the INTERFACE_ variants. 
# The PUBLIC mode populates both variants of the respective target property. Each command may be invoked with multiple uses of each keyword:


# add imported exe
if (APPLE)
    add_executable(impored_exe IMPORTED)
    set_target_properties(impored_exe PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../build_exe/build/main")
    add_custom_target(run_impored_exe ALL impored_exe)
endif()
# add impored lib

if (APPLE)
    set(BOOST_INCLUDE_DIR /usr/local/lib/boost)
    set(BOOST_REGEX_SRC_PATH /usr/local/lib/boost/libs/regex/build_lib)
    set(BOOST_REGEX_LIB_PATH /usr/local/lib/boost/libs/regex/build_lib/build)
endif()

set(HEADER_DIR ${CMAKE_SOURCE_DIR}/../src/static_lib_src)

message("CMAKE_SOURCE_DIR:"${CMAKE_SOURCE_DIR})
message("HEADER_DIR:"${HEADER_DIR})
message("NEED_COMPILE_SOURCE_FILES_2:"${NEED_COMPILE_SOURCE_FILES_2})
message("BOOST_INCLUDE_DIR:"${BOOST_INCLUDE_DIR})
message("BOOST_REGEX_LIB_PATH:"${BOOST_REGEX_LIB_PATH}/libboost_regex.a)


# 目标库 (生成一系列目标文件，而不会对其打包或链接，只是逻辑上的概念)
add_library(my_object_target OBJECT "${CMAKE_CURRENT_SOURCE_DIR}/../src/object_lib_src/bbb.cpp")

set(CMAKE_SORT_BY_FILENAME OFF)
# 导入boost静态库
add_subdirectory(${BOOST_REGEX_SRC_PATH} lib_boost)

# 设置目录属性
# set_property(DIRECTORY ${BOOST_REGEX_SRC_PATH} PROPERTY BINARY_DIR ${BOOST_REGEX_LIB_PATH}/libboost_regex)
get_directory_property(BOOST_BINARY_DIR DIRECTORY ${BOOST_REGEX_SRC_PATH} BINARY_DIR)
# get_property(BOOST_BINARY_DIR DIRECTORY ${BOOST_REGEX_SRC_PATH} PROPERTY BINARY_DIR)
message("get BOOST_BINARY_DIR property:"${BOOST_BINARY_DIR})





# add_library(boost-regex OBJECT )
add_library(boost-regex STATIC IMPORTED)
target_include_directories(boost-regex INTERFACE ${BOOST_INCLUDE_DIR})

# if (BOOST_MULTI_BUILD_MODE)
#     set_property(TARGET boost-regex PROPERTY IMPORTED_CONFIGURATIONS DEBUG;RELEASE)
#     set_target_properties(boost-regex PROPERTIES
#     IMPORTED_LOCATION_DEBUG ${BOOST_REGEX_LIB_PATH}/debug/libboost_regex.a
#     IMPORTED_LOCATION_RELEASE ${BOOST_REGEX_LIB_PATH}/release/libboost_regex.a
#     )
# else()
    # set_target_properties(boost-regex PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/build/lib_boost/libboost_regex.a)
    set_target_properties(boost-regex PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/build/lib_boost/libboost_regex.a)

    # 依赖关系建立
    # a. 通过target_link_libraries(...)
    # b. 通过add_dependencies(...) 用于没有明显链接关系情况
    add_dependencies(boost-regex  boost_regex)

# endif()



add_executable(main2 ${NEED_COMPILE_SOURCE_FILES_2} ${HEADER_DIR}/b.cpp $<TARGET_OBJECTS:my_object_target>)
# 头文件搜索路径
target_include_directories(main2 PUBLIC ${HEADER_DIR} ${HEADER_DIR}/../object_lib_src)

# # 接口库
add_library(my_interface_target INTERFACE)
target_include_directories(my_interface_target INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../src/interface_lib_src")
# target_link_libraries(main2  my_interface_target)
# # 使用别名
add_library(my_interface_target_alias ALIAS my_interface_target)
target_link_libraries(main2  my_interface_target_alias)


# target_link_libraries(main2  my_interface_target $<TARGET_OBJECTS:my_obj_lib>)
target_link_libraries(main2 boost-regex)


set(CMAKE_INSTALL_PREFIX  ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS main2 RUNTIME DESTINATION my_install)