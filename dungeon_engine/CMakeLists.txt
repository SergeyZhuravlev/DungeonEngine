#project(DungEngSource)#dungeon engine
cmake_minimum_required(VERSION 3.11)

add_library(dung_eng STATIC source/dummy.cpp)
target_link_libraries(dung_eng sdl2 sdl2main boost_headers)