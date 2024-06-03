cmake_minimum_required(VERSION 3.20)
project(cmake_property)

#[[
    全局属性
]]
set_property(GLOBAL PROPERTY GLOBAL_PROP "GLOBAL_PROP1")
get_property(val GLOBAL PROPERTY GLOBAL_PROP)
message("GLOBAL_PROP = ${val}")