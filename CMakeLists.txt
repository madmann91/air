cmake_minimum_required(VERSION 3.11)
project(air VERSION 2.0)

find_package(sol REQUIRED)

add_subdirectory(contrib)
add_subdirectory(src)
