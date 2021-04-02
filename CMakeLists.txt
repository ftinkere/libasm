cmake_minimum_required(VERSION 3.17)
project(libasm C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/clang")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(libasm
        COMMAND make all
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )

#add_custom_target(libasm.a)

#add_custom_command(OUTPUT libasm.a
#        COMMAND make all
#        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/srcs/ft_strlen.s
#            ${CMAKE_CURRENT_SOURCE_DIR}/srcs/ft_strcpy.s
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#        )

add_executable(test srcs/main.c libasm.h libasm.a srcs/ft_strcpy.s srcs/ft_strlen.s)
set_property(TARGET test PROPERTY LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/libasm.a)
add_dependencies(test libasm)
target_link_libraries(test asm)
