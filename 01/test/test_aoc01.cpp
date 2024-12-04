/*********************************************************************
 * @file   main.cpp
 * @brief  Advent Of Code 2024: 01
 *
 * @author Philipp Jeske
 * @date   2024-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <catch2/catch_test_macros.hpp>
#include <cstdint>

#include "distcalc.h"

TEST_CASE("List distance calculated")
{
    std::vector<int32_t> lista {3, 4, 2, 1, 3, 3};
    std::vector<int32_t> listb {4, 3, 5, 3, 9, 3};

    REQUIRE(pjexx::aoc2024::distance(lista,listb) == 11);
}
