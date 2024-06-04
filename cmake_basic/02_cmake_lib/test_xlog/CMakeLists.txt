cmake_minimum_required(VERSION 3.20)

project(test_xlog)

# 指定库查找路径
link_directories("../xlog/build")

# 指定头文件搜索路径
include_directories("../xlog")

add_executable(test_xlog test_xlog.cpp)

# 指定加载的库
target_link_libraries(test_xlog xlog)