cmake_minimum_required(VERSION 3.20)
project(cmake_hello) 

# cmake -S . -B build   .表示CMakeLists.txt所在目录，build表示构建的临时文件目录
# cmake --build build   在build目录下编译
add_executable(cmake_hello cmake_hello.cpp)

# 或者分开
# add_executable(cmake_hello)
# target_sources(cmake_hello PUBLIC cmake_hello.cpp)
