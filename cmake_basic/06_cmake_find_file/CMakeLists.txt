cmake_minimum_required(VERSION 3.20)
project("auto_src_h")

set(INCLUDE_PATH "./include")
include_directories(${INCLUDE_PATH})

# 找到当前目录 . 下源码写入MAIN_SRC中
aux_source_directory("." MAIN_SRC)
aux_source_directory("./src" SRC)

# 读取include_directories所有头文件
file(GLOB H_FILE "${INCLUDE_PATH}/*.h" "${INCLUDE_PATH}/*.hpp")

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${SRC})