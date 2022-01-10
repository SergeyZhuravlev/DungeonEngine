#project(DungEngSource)#dungeon engine
cmake_minimum_required(VERSION 3.11)

set (SOURCES 
	source/graphics.cpp
	source/engine.cpp
	source/math.cpp)

set (HEADERS
	include/dungeng.hpp
	include/dungeng/math.hpp
	include/dungeng/graphics.hpp
	include/dungeng/engine.hpp)

add_library(dung_eng STATIC ${SOURCES} ${HEADERS})
target_include_directories(dung_eng PUBLIC include)

target_link_libraries(dung_eng sdl2 boost_headers)