/*********************************************************************
 * @file distcalc.h
 * @brief
 *
 * @author Philipp Jeske
 * @date 2024-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#pragma once

#include <algorithm>
#include <numeric>
#include <ranges>

#ifndef PJEXX_AOC2024_DISTCALC_H_
#define PJEXX_AOC2024_DISTCALC_H_

namespace pjexx::aoc2024
{
/**
 * @brief Calculate the distance between two lists
 *
 * At first, the lists are sorted. Then the absolute difference between the elements of the lists is calculated and
 * summed up.
 *
 * @param list1 The first list
 * @param list2 The second list
 * @return The sum of the absolute differences between the elements of the lists
 */
auto distance(std::ranges::input_range auto list1, std::ranges::input_range auto list2)
{
    std::ranges::sort(list1);
    std::ranges::sort(list2);

    auto merged_ranges = std::views::zip(list1, list2) |
                         std::views::transform([](auto a) { return std::abs(std::get<0>(a) - std::get<1>(a)); });

    return std::accumulate(merged_ranges.begin(), merged_ranges.end(), 0);
}
}  // namespace pjexx::aoc2024

#endif  // PJEXX_AOC2024_DISTCALC_H_
