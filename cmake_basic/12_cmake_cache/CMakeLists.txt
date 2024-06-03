cmake_minimum_required(VERSION 3.20)
project(cmake_cache)

#[[
    set(<variable> <value>... CACHE <type> <docstring> [FORCE])
        type:
            BOOL
            STRING 
            PATH
            FILEPATH
]]

# 设置缓存变量
set(VAR1 "CACHE VAR1 VALUE" CACHE STRING "This is a cache variable")

# 缓存变量第二次修改不生效
set(VAR2 "CACHE VAR1 VALUE-2" CACHE STRING "This is a cache variable")
message("VAR1: ${VAR1}")

# 强制修改缓存变量
set(VAR1 "CACHE VAR1 VALUE-3 FORCE" CACHE STRING "This is a cache variable" FORCE)
message("VAR1: ${VAR1}")

# CACHE变量作用域是全局的
# 普通变量作用域 自身和子模块
set(VAR_NORMAL "NORMAL VAR VALUE")
message("VAR_NORMAL: ${VAR_NORMAL}")

message("in main")
add_subdirectory(sub1) # 子目录sub1可以访问到VAR_NORMAL
add_subdirectory(sub2) # 子目录sub2可以访问到VAR_NORMAL,但sub1访问不到sub2中的普通变量

option(OPTION1 "OPTION1 VALUE" ON)
option(OPTION2 "OPTION2 VALUE" OFF)
message(OPTION1: ${OPTION1})
message(OPTION2: ${OPTION2})

# ccmake修改缓存变量
# ccmake build


#[[
    缓存策略:
        默认:先找普通变量,$CACHE{VAR}找缓存变量
        cmake_policy(SET CMP0216 OLD): 删除同名普通变量
]]

set(NVAR1 "normal var1")
set(NVAR1 "cache var1" CACHE STRING "cache doc")
message("NVAR1: ${NVAR1}") # 普通变量
message("CACHE NVAR1: $CACHE{NVAR1}") # 缓存变量

message("----------------------------------------------------------------")
#[[
    传递缓存变量
]]
# cmake -S . -B build -D PARA1=PARA1_VALUE
message("PARA1 = ${PARA1}")

# 内置缓存变量
# cmake -S . -B build -D BUILD_SHARED_LIBS=ON
message("BUILD_SHARED_LIBS: ${BUILD_SHARED_LIBS}") # 默认为空