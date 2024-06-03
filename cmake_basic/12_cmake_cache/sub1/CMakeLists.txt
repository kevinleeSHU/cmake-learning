cmake_minimum_required(VERSION 3.20)
project(sub1)

message("in sub1")

set(VAR_CACHE_SUB1 "var cache sub1" CACHE STRING "sub1 doc")
message("int sub1  VAR_CACHE_SUB1: ${VAR_CACHE_SUB1}")