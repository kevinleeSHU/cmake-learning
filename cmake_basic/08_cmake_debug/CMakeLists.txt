cmake_minimum_required(VERSION 3.20)
project(cmake_hello) 

# 显示详细的生成日志,或者使用 cmake --build . -v
set(CMAKE_VERBOSE_MAKEFILE ON) # 默认是OFF

add_executable(cmake_hello cmake_hello.cpp)
