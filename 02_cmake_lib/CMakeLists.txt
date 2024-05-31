cmake_minimum_required(VERSION 3.20)

project(xlog)

include_directories(xlog)

add_library(xlog SHARED xlog/xlog.cpp) # 创建动态库libxlog.so
add_executable(test_xlog test_xlog/test_xlog.cpp)
target_link_libraries(test_xlog xlog)  # test_xlog中引入动态库