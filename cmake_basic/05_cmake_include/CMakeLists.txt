cmake_minimum_required(VERSION 3.20)

project(cmake_include)

message("begin incldue")

# 加载 cmake/test_cmake.cmake中的内容
include("cmake/test_cmake.cmake")

# 使用OPTIONAL，可选的include，如果文件不存在，不会报错
# include("cmake/test_cmake1.cmake") # 报错
include("cmake/test_cmake1.cmake" OPTIONAL) # 不报错
include("cmake/test_cmake1.cmake" OPTIONAL RESULT_VARIABLE result) # 拿到返回值
message("result: " ${result}) # NOTFOUND

include("cmake/test_cmake.cmake" OPTIONAL RESULT_VARIABLE result)
message("result: " ${result}) # 文件的绝对路径 /home/lyw/Code/cmake_study/05_cmake_include/cmake/test_cmake.cmake

message("end include ")