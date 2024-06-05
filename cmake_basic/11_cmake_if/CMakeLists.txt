#[[
    常量：
        左边为真，右边为假
        1      / 0
        非零数
        ON     / OFF
        YES(Y) / NO(N)
        TRUE   / FALSE
                 IGNORE NOTFOUND
                 空字符串  
                 -NOTFOUND结尾
                 空

    变量：
        非假值常量为真。未定义和其他为假
        环境变量总为假
        宏参数不是变量
        字符串的值是常量真则为真，如"ON"、"YES"为真；其他带引号的字符串为false假
]]

cmake_minimum_required(VERSION 3.20)
project(cmake_if)

if(1)
    message("1 is true")
endif()

if(OFF)
    message("OFF is true")
elseif(NO)
    message("NO is true")
else()
    message("OFF NO is false")
endif()

if()
    message("empty is true")
else()
    message("empty is false")
endif()

if("YES")  # true
    message(" \"YES\" is true ")
endif()
if("Ye") # false
    message("\"Ye\" is true")
else()
    message("\"Ye\" is false")
endif()

if(VAR) # 未定义为false
    message("VAR is true")
else() 
    message("VAR is false")
endif()

set(VAR "a") 

if(VAR) # true
    message("VAR is true")
else()
    message("VAR is true")
endif()

if(${VAR}) # true
    message("\${VAR} is true")
else()
    message("\${VAR} is false")
endif()

#[[
    变量判断
        DEFINED 判断变量是否定义
        EQUAL 判断数字（数字字符串）是否相等
        STREQUAL 判断任意字符串是否相等
]]
set(VAR_DEF OFF)
if(DEFINED VAR_DEF)
    message("VAR_DEF is defined")
endif()

#[[
    正则匹配
        MATCHES
]]

