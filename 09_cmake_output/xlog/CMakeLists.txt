# 静态库：
# 动态库

cmake_minimum_required(VERSION 3.20)

project(xlog)

add_library(xlog STATIC xlog.cpp xlog.h)