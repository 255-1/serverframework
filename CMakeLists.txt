cmake_minimum_required(VERSION 3.23)
project(sylar)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

set(LIB_SRC ./sylar/log.cpp sylar/util.h sylar/util.cpp sylar/singleton.h sylar/config.h)
add_library(sylar SHARED ${LIB_SRC} sylar/util.h sylar/singleton.h)

add_executable(test tests/test.cpp)
add_dependencies(test sylar)
target_link_libraries(test sylar)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
