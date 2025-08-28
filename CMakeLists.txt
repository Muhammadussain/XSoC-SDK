cmake_minimum_required(VERSION 3.10)
project(babykyber_sdk)

include_directories(include)
add_executable(babykyber_demo src/babykyber.c src/babykyber_hal.c)
