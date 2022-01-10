#project(depends_manager)
cmake_minimum_required(VERSION 3.14)

IF (WIN32 AND MSVC)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET OFF)

#https://www.libsdl.org/download-2.0.php
FetchContent_Declare(
  sdl2_win_debug_downloaded
  URL https://www.libsdl.org/release/SDL2-devel-2.0.16-VC.zip
)
FetchContent_MakeAvailable(sdl2_win_debug_downloaded)
message ("SDL2 debug downloaded at '${sdl2_win_debug_downloaded_SOURCE_DIR}'")

FetchContent_Declare(
  sdl2_win_x86_release_downloaded
  URL https://www.libsdl.org/release/SDL2-2.0.16-win32-x86.zip
)
FetchContent_MakeAvailable(sdl2_win_x86_release_downloaded)
message ("SDL2 release downloaded at ${sdl2_win_x86_release_downloaded}'")

add_library(sdl2origin SHARED IMPORTED GLOBAL)
set_property(TARGET sdl2origin PROPERTY IMPORTED_IMPLIB "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.lib")
set_property(TARGET sdl2origin PROPERTY IMPORTED_LOCATION "${sdl2_win_debug_downloaded_SOURCE_DIR}/SDL2.dll")
set_property(TARGET sdl2origin PROPERTY IMPORTED_IMPLIB_RELEASE "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.lib")
set_property(TARGET sdl2origin PROPERTY IMPORTED_LOCATION_RELEASE "${sdl2_win_x86_release_downloaded}/SDL2.dll")
set_property(TARGET sdl2origin PROPERTY IMPORTED_IMPLIB_DEBUG "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.lib")
set_property(TARGET sdl2origin PROPERTY IMPORTED_LOCATION_DEBUG "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.dll")
target_include_directories(sdl2origin INTERFACE "${sdl2_win_debug_downloaded_SOURCE_DIR}/include")

add_library(sdl2main STATIC IMPORTED GLOBAL)
set_property(TARGET sdl2main PROPERTY IMPORTED_LOCATION "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2main.lib")
set_property(TARGET sdl2main PROPERTY IMPORTED_LOCATION_RELEASE "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2main.lib")
set_property(TARGET sdl2main PROPERTY IMPORTED_LOCATION_DEBUG "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2main.lib")

add_library(sdl2 STATIC main.cpp)
target_link_libraries(sdl2 sdl2origin sdl2main)

#https://www.boost.org/users/history/version_1_77_0.html
FetchContent_Declare(
  boost_win_downloaded
  URL https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.zip
)
FetchContent_MakeAvailable(boost_win_downloaded)

add_library(boost_headers INTERFACE)
target_include_directories(boost_headers INTERFACE
        "${boost_win_downloaded_SOURCE_DIR}")

ELSE ()

find_package(SDL2 REQUIRED)
message ("SDL2 libraries founded at '${SDL2_LIBRARIES}'")
message ("SDL2 includes founded at '${SDL2_INCLUDE_DIRS}'")
add_library(sdl2 STATIC main.cpp)
target_link_libraries(sdl2 "${SDL2_LIBRARIES}")
target_include_directories(sdl2 INTERFACE "${SDL2_INCLUDE_DIRS}/SDL2")

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0 REQUIRED)
message ("Boost libraries founded at '${Boost_LIBRARIES}'")
message ("Boost includes founded at '${Boost_INCLUDE_DIRS}'")
add_library(boost_headers INTERFACE)
target_include_directories(boost_headers INTERFACE "${Boost_INCLUDE_DIRS}")

ENDIF ()