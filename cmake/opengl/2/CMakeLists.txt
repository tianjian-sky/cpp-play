cmake_minimum_required(VERSION 3.01)
project("opengl_2" VERSION 1.0.1 DESCRIPTION "opengl 2" HOMEPAGE_URL "github.com" LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./dist)
# SET(CMAKE_CXX_COMPILER /usr/bin/g++) mac上如果不用xcode的构建工具，则设置此选项
SET(CMAKE_CACHEFILE_DIR ./cache)
set(CMAKE_BUILD_DIRECTORY ./build)
# set(CMAKE_BUILD_FILES_DIRECTORY ./build_file)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(/usr/local/include)
include_directories(/opt/homebrew/include --std=c++11)
include_directories(/Users/yutianjian/develop/SOIL2/src)
include_directories(/Users/yutianjian/develop/glm)
# add_library("1.1" SHARED 1.1.cpp)
# add_executable("1.1" MACOSX_BUNDLE 1.1.cpp) 

# add_library(SOIL2 STATIC /Users/yutianjian/develop/SOIL2/build/libsoil2.a)
# link_directories(/Users/yutianjian/develop/SOIL2)
# target_link_libraries(SOIL2 /Users/yutianjian/develop/SOIL2/libsoil2.a)

set(GLFW_LINK /opt/homebrew/lib/libglfw.3.dylib)
set(GLEW_LINK /opt/homebrew/lib/libGLEW.dylib)
set(GLM_LINK /Users/yutianjian/develop/glm/build/glm/libglm.a)
link_libraries(${GLFW_LINK}) # link_libraries作为全局链接库设置，需要在add_library或者add_executable命令之前使用
link_libraries(${GLEW_LINK})
link_libraries(${GLM_LINK})


add_executable("main" main.cpp Utils.cpp)
target_link_libraries("main" /Users/yutianjian/develop/SOIL2/libsoil2.a)
# target_link_libraries("main" ) # target_link_libraries为特定的目标指定链接库，则需要在add_library或者add_executable命令之后使用

if (APPLE) # mac 增加-framework OpenGL
  target_link_libraries("main" "-framework OpenGL")
   # mac上soil2 用到了CoreFoundation
  target_link_libraries("main" "-framework CoreFoundation")
endif()

# https://www.coder.work/article/6221866

