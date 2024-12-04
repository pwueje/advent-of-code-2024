# Copyright 2024 Philipp Jeske
# SPDX-License-Identifier: MIT

add_library(${executable}-lib  "report.cpp" "report.h")
target_include_directories(${executable}-lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(${executable}-lib PUBLIC cxx_std_23)
target_add_common_build_properties(${executable}-lib)
target_enable_clang_tidy(${executable}-lib)

add_executable(${executable} main.cpp)

target_link_libraries(${executable}
    PRIVATE ${executable}-lib
)
target_add_common_build_properties(${executable})
target_enable_clang_tidy(${executable})

target_compile_features(${executable} PRIVATE cxx_std_20)

find_package(argparse REQUIRED)
target_link_libraries(${executable} PRIVATE argparse::argparse)

if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/../data/reports.txt)
    configure_file(../data/reports.txt reports.txt COPYONLY)
endif()