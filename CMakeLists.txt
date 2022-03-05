cmake_minimum_required(VERSION 3.16)
project(MyByteArray)

add_executable(mybytearray main.c includes/networking_class.c includes/networking_class.h)

include_directories(./ ./includes)

set_property(TARGET mybytearray PROPERTY C_STANDARD 11)


