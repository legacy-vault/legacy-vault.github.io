cmake_minimum_required(VERSION 2.8)
project(html_item_game)

set(SOURCES
	src/const.h
	src/const.c
	src/main.h
	src/main.c
	src/str.h
	src/str.c
	src/types.h)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O3")

add_executable(html_item_game ${SOURCES})