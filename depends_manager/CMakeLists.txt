#project(depends_manager)
cmake_minimum_required(VERSION 3.14)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET OFF)

IF (WIN32 AND MSVC)

#https://www.libsdl.org/download-2.0.php
FetchContent_Declare(
  sdl2_win_debug_downloaded
  URL https://www.libsdl.org/release/SDL2-devel-2.0.16-VC.zip
)
FetchContent_MakeAvailable(sdl2_win_debug_downloaded)

FetchContent_Declare(
  sdl2_win_x86_release_downloaded
  URL https://www.libsdl.org/release/SDL2-2.0.16-win32-x86.zip
)
FetchContent_MakeAvailable(sdl2_win_x86_release_downloaded)

add_library(sdl2 SHARED IMPORTED GLOBAL)
set_property(TARGET sdl2 PROPERTY IMPORTED_IMPLIB "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.lib")
set_property(TARGET sdl2 PROPERTY IMPORTED_LOCATION "${sdl2_win_debug_downloaded_SOURCE_DIR}/SDL2.dll")
set_property(TARGET sdl2 PROPERTY IMPORTED_IMPLIB_RELEASE "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.lib")
set_property(TARGET sdl2 PROPERTY IMPORTED_LOCATION_RELEASE "${sdl2_win_x86_release_downloaded}/SDL2.dll")
set_property(TARGET sdl2 PROPERTY IMPORTED_IMPLIB_DEBUG "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.lib")
set_property(TARGET sdl2 PROPERTY IMPORTED_LOCATION_DEBUG "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2.dll")
target_include_directories(sdl2 INTERFACE "${sdl2_win_debug_downloaded_SOURCE_DIR}/include")

add_library(sdl2main STATIC IMPORTED GLOBAL)
set_property(TARGET sdl2main PROPERTY IMPORTED_LOCATION "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2main.lib")
set_property(TARGET sdl2main PROPERTY IMPORTED_LOCATION_RELEASE "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2main.lib")
set_property(TARGET sdl2main PROPERTY IMPORTED_LOCATION_DEBUG "${sdl2_win_debug_downloaded_SOURCE_DIR}/lib/x86/SDL2main.lib")


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
add_library(sdl2 STATIC IMPORTED)
set_target_properties(sdl2 PROPERTIES
  IMPORTED_LOCATION "${SDL2_LIBRARIES}"
  INTERFACE_INCLUDE_DIRECTORIES "${SDL2_INCLUDE_DIRS}"
)

#find_package(SDL2main REQUIRED)
#add_library(sdl2main STATIC IMPORTED)
#set_target_properties(sdl2main PROPERTIES
#  IMPORTED_LOCATION "${SDL2main_LIBRARIES}"
#  INTERFACE_INCLUDE_DIRECTORIES "${SDL2main_INCLUDE_DIRS}"
#)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.77.0 REQUIRED)
add_library(boost_headers STATIC IMPORTED)
set_target_properties(boost_headers PROPERTIES
  IMPORTED_LOCATION "${Boost_LIBRARIES}"
  INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIRS}"
)

ENDIF ()