# 静态库：
# 动态库

cmake_minimum_required(VERSION 3.20)

project(xlog)

set(VAR1 "测试VAR1的值")
message("VAR1=" ${VAR1})
message("VAR1 in string ${VAR1}")
message("\${VAR1} = ${VAR1}") # 转义
# unset(VAR1) # 取消变量

# 嵌套
set(VAR2 "VAR1")
message("VAR2=" ${VAR2})
message("VAR2 = " ${${VAR2}})

# 提供信息的内部变量
message("项目名称 = " ${PROJECT_NAME}) # 对应project(test_var)中的名字
message("项目源码目录 = " ${PROJECT_SOURCE_DIR}) # 对应CMakeLists.txt所在的目录
message("项目构建目录 = " ${PROJECT_BINARY_DIR}) # 对应输出构建目录

# 描述系统的变量
message("MSVC = " ${MSVC})
message("WIN32 = " ${WIN32}) # 为空
message("UNIX = " ${UNIX})  # 1
message("CMAKE_SYSTEM_NAME = " ${CMAKE_SYSTEM_NAME}) # Linux

# 控制构建过程的变量

# cmake传递变量/宏给c/c++
add_definitions(-Dxlog_STATIC)

# set(BUILD_SHARED_LIBS ON)  # 生成动态库
set(BUILD_SHARED_LIBS OFF)  # 生成静态库
add_library(${PROJECT_NAME} xlog.cpp xlog.h)
