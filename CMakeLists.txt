# Copyright 2024 Philipp Jeske
# SPDX-License-Identifier: MIT

cmake_minimum_required (VERSION 3.22)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_LINKER_TYPE LLD)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AdventOfCode"
		VERSION 0.1
		DESCRIPTION "Implementation of a circular buffer as a playground for new C++ features"
        HOMEPAGE_URL "https://adventofcode.com/2024"
		LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/_cmake")
include(ClangTidy)
include(BuildProperties)
include(Coverage)

add_subdirectory(01)
add_subdirectory(02)

include(CTest)
enable_testing()