#project(TestHelloWorld)
cmake_minimum_required(VERSION 3.11)

IF (WIN32 AND MSVC)

add_executable(test_hello_world WIN32 main.cpp)

add_custom_command(TARGET test_hello_world POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sdl2origin>
        $<TARGET_FILE_DIR:test_hello_world>)

ELSE ()

add_executable(test_hello_world main.cpp)

ENDIF ()
target_compile_features(test_hello_world PRIVATE cxx_std_17)
target_link_libraries(test_hello_world dung_eng)
