/*********************************************************************
 * @file   main.cpp
 * @brief  Advent Of Code 2024: 02
 *
 * @author Philipp Jeske
 * @date   2024-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <catch2/catch_test_macros.hpp>
#include <cstdint>

#include "report.h"

TEST_CASE("Calc safety of report")
{
    SECTION("Report is safely decreasing")
    {
        pjexx::aoc2024::Report report {7, 6, 4, 2, 1};
        REQUIRE(report.isSafe());
    }

    SECTION("Report is safely increasing")
    {
        pjexx::aoc2024::Report report {1, 3, 6, 7, 9};
        REQUIRE(report.isSafe());
    }

    SECTION("Report is not safe, because of big increase")
    {
        pjexx::aoc2024::Report report {1, 2, 7, 8, 9};
        REQUIRE_FALSE(report.isSafe());
    }

    SECTION("Report is not safe, because of big decrease")
    {
        pjexx::aoc2024::Report report {9, 7, 6, 2, 1};
        REQUIRE_FALSE(report.isSafe());
    }

    SECTION("Report is not safe, because of violating monotonicity")
    {
        pjexx::aoc2024::Report report {1, 3, 2, 4, 5};
        REQUIRE_FALSE(report.isSafe());
    }

    SECTION("Report is not safe, because of violating strict monotonicity")
    {
        pjexx::aoc2024::Report report {8, 6, 4, 4, 1};
        REQUIRE_FALSE(report.isSafe());
    }
}

TEST_CASE("Calc safety of report after Problem Dampener")
{
    SECTION("Report is safely decreasing")
    {
        pjexx::aoc2024::Report report {7, 6, 4, 2, 1};
        REQUIRE(report.isSafeWithDampener());
    }

    SECTION("Report is safely increasing")
    {
        pjexx::aoc2024::Report report {1, 3, 6, 7, 9};
        REQUIRE(report.isSafeWithDampener());
    }

    SECTION("Report is not safe, because of big increase")
    {
        pjexx::aoc2024::Report report {1, 2, 7, 8, 9};
        REQUIRE_FALSE(report.isSafeWithDampener());
    }

    SECTION("Report is not safe, because of big decrease")
    {
        pjexx::aoc2024::Report report {9, 7, 6, 2, 1};
        REQUIRE_FALSE(report.isSafeWithDampener());
    }

    SECTION("Report is not safe, because of violating monotonicity")
    {
        pjexx::aoc2024::Report report {1, 3, 2, 4, 5};
        REQUIRE(report.isSafeWithDampener());
    }

    SECTION("Report is not safe, because of violating strict monotonicity")
    {
        pjexx::aoc2024::Report report {8, 6, 4, 4, 1};
        REQUIRE(report.isSafeWithDampener());
    }

    SECTION("Report is not safe, because of two violations")
    {
        pjexx::aoc2024::Report report {34, 33, 35, 38, 41, 42, 48, 48};
        REQUIRE_FALSE(report.isSafeWithDampener());
    }

    SECTION("Report is safe, because of only one violation at the end")
    {
        pjexx::aoc2024::Report report {61, 62, 63, 66, 66};
        REQUIRE(report.isSafeWithDampener());
    }

    SECTION("Report is safe, because of only one violation at the begin")
    {
        pjexx::aoc2024::Report report {63, 62, 63, 66, 67};
        REQUIRE(report.isSafeWithDampener());
    }
}
