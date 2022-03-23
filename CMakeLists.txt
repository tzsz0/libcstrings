cmake_minimum_required(VERSION 3.18)
project(libcstrings)

# first time cmake, pls no bully

set(SOURCES src/string_cat.c
    src/string_cmp.c
    src/string_cpy.c
    src/string_dup.c
    src/string_len.c
    src/string_new.c
    src/string_str.c
    src/string_from_chars.c)

add_subdirectory(contrib/safestringlib)

add_library(cstrings SHARED ${SOURCES})


target_include_directories(cstrings PUBLIC include)
target_include_directories(cstrings PRIVATE src)

target_link_libraries(cstrings PRIVATE safestring_shared)


