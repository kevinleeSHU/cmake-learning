cmake_minimum_required(VERSION 3.20)
project(cmake_hello) 

add_executable(cmake_hello cmake_hello.cpp)

# cmake --build . --target cmake_hello.i 预处理
# cmake --build . --target cmake_hello.s 编译
# cmake --build . --target cmake_hello.o 汇编
# cmake --build .                        链接 生成可执行文件

# cmake --build . --target clean 清理