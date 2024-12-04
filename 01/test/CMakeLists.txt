# Copyright 2024 Philipp Jeske
# SPDX-License-Identifier: MIT
set(testname ${executable}-test)

add_executable(${testname} test_aoc01.cpp)

find_package(Catch2 REQUIRED)

target_link_libraries(${testname} PRIVATE
    Catch2::Catch2WithMain
    ${executable}-lib
)