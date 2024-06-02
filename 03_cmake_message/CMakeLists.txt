# 单行注释

#[[
    多行注释
    ---
]]

cmake_minimum_required(VERSION 3.20)

project(message)

#[[
    message(arg1 arg2 arg3)
]]
message("参数1") # 测试message
message("参数1" "参数2" "p3" p4) # 拼接


#[[ message 日志级别
    ERROR：FATAL_ERROR  停止cmake运行和生成，打印到stderr
           SEND_ERROR  cmake继续运行，生成跳过，打印到stderr
    WARNING: 打印到stderr
    (none) 或 NOTICE：打印到stderr
    STATUS：项目用户可能感兴趣的信息
    VERBOSE：项目用户的详细信息
    DEBUG：开发人员使用的信息
    TRACE：非常低级别的细粒度信息
]]

#[[
message(FATAL_ERROR "Test fatal error")
message("after fatal error") # 不会执行
]]

# 进程继续，生成退出
message(SEND_ERROR "test send error")
add_executable(test_message test_message.cpp)  # 不会生成项目
message("after send error")

# 打印代码路径和行号
message(WARNING "test warning")

# NOTICE 等同于什么都不加  stderr
message("test none") 
message(NOTICE "TEST NOTICE")

# 加前缀 -- 用户可能感兴趣
message(STATUS "test status!!")

message(VERBOSE "test VERBOSE")

# 重定向标准输出到文件
# cmake -S . -B build --log-level=VERBOSE>log.txt

# 重定向标准输出到文件，标准错误输出重定向至标注输出
# cmake -S . -B build --log-level=VERBOSE>log.txt 2>&1

# cmake -S . -B build --log-level=DEBUG
message(DEBUG "test DEBUG")

# cmake -S . -B build --log-level=TRACE
message(TRACE "test TRACE")


# 2.4 message Reporting checks 查找库日志
#[[
    CHECK_START 开始记录将要执行检查的消息
    CHECK_PASS 记录检查的成功结果
    CHECK_FAIL 记录不成功的检查结果
]]
message("======================2.4======================")
# 开始查找
message(CHECK_START "查找xcpp")

# 查找xcpp库的代码
# ...

# message缩进
set(CMAKE_MESSAGE_INDENT "--")

# 嵌套查找
message(CHECK_START "查找xlog")
# 查找xlog代码
message(CHECK_PASS "成功")

# 取消缩进
set(CMAKE_MESSAGE_INDENT "")

message(CHECK_FAIL "失败")


