/*********************************************************************
 * @file report.cpp
 * @brief
 *
 * @author Philipp Jeske
 * @date 2024-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include "report.h"

#include <algorithm>
#include <numeric>
#include <ranges>

namespace pjexx::aoc2024
{
bool Report::isSafe() const
{
    auto isPairwiseDistanceSafe = [](int a, int b) { return std::abs(a - b) > 0 && std::abs(a - b) <= 3; };
    auto pairwiseDistanceSafe =
        std::ranges::all_of(levels_ | std::views::pairwise_transform(isPairwiseDistanceSafe), [](bool b) { return b; });

    return pairwiseDistanceSafe && (std::ranges::is_sorted(levels_) || std::ranges::is_sorted(levels_, std::greater{}));
}
}  // namespace pjexx::aoc2024
