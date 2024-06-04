cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories(xlog)

# 动态库.so 输出路径(linux中有效),默认路径在build目录下
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")  # build/lib/libxlog.so

# 想以CMakeLists.txt绝对路径为基准
message("CMAKE_CURRENT_LIST_DIR = " ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

# 执行程序 和windows中dll 动态库pdb调试文件 输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

# 归档文件输出路径 静态库 .lib 动态库 .lib地址文件 linux静态库.a
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

# --------------------------------指定子模块生成静态/动态库--------------------------------------
# 添加xlog动态库
# add_library(xlog SHARED xlog/xlog.cpp)      

# 添加静态库
# set(BUILD_SHARED_LIBS OFF)
# add_definitions(-Dxlog_STATIC) # windows下使用

# 添加动态库
set(BUILD_SHARED_LIBS ON) # xlog为.so动态库
# -----------------------------------------------------------------------

add_subdirectory(xlog)
add_subdirectory(test_xlog)

# # 执行文件
# add_executable(test_xlog test_xlog/test_xlog.cpp)

# # 链接库
# target_link_libraries(test_xlog xlog)