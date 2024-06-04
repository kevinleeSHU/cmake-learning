# 静态库：
# 动态库

cmake_minimum_required(VERSION 3.20)

project(xlog)

add_library(${PROJECT_NAME} xlog.cpp xlog.h) # 生成静态/动态库由外层CMakeLists.txt指定