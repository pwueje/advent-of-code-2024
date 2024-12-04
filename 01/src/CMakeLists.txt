# Copyright 2024 Philipp Jeske
# SPDX-License-Identifier: MIT

add_library(${executable}-lib INTERFACE "distcalc.h")
target_include_directories(${executable}-lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(${executable}-lib INTERFACE cxx_std_20)

add_executable(${executable} main.cpp)

target_link_libraries(${executable}
    PRIVATE ${executable}-lib
)
target_add_common_build_properties(${executable})
target_enable_clang_tidy(${executable})

target_compile_features(${executable} PRIVATE cxx_std_20)

find_package(argparse REQUIRED)
target_link_libraries(${executable} PRIVATE argparse::argparse)