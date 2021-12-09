#project(TestHelloWorld)
cmake_minimum_required(VERSION 3.11)

add_executable(test_hello_world WIN32 main.cpp)

target_link_libraries(test_hello_world dung_eng)

add_custom_command(TARGET test_hello_world POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sdl2>
        $<TARGET_FILE_DIR:test_hello_world>)