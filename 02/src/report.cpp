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
#include <cstdint>
#include <numeric>
#include <optional>
#include <ranges>

namespace pjexx::aoc2024
{
Report::Report(std::initializer_list<int> levels) : levels_(levels) {}

bool Report::isSafe() const
{
    auto isPairwiseDistanceSafe = [](int val1, int val2)
    { return std::abs(val1 - val2) > 0 && std::abs(val1 - val2) <= 3; };

    auto pairwiseDistanceSafe = std::ranges::all_of(levels_ | std::views::pairwise_transform(isPairwiseDistanceSafe),
                                                    [](bool item) { return item; });

    return pairwiseDistanceSafe &&
           (std::ranges::is_sorted(levels_) || std::ranges::is_sorted(levels_, std::greater {}));
}

bool Report::isSafeWithDampener() const
{
    if (isSafe()) {
        return true;
    }

    auto is_safe = [](const std::vector<int>& v) {
        auto isPairwiseDistanceSafe = [](int val1, int val2)
        { return std::abs(val1 - val2) > 0 && std::abs(val1 - val2) <= 3; };

        bool pairwiseDistanceSafe = std::ranges::all_of(
            v | std::views::pairwise_transform(isPairwiseDistanceSafe),
            [](bool item) { return item; });

        return pairwiseDistanceSafe &&
               (std::ranges::is_sorted(v) || std::ranges::is_sorted(v, std::greater {}));
    };

    return std::ranges::any_of(
        std::views::iota(size_t{0}, levels_.size()),
        [&](size_t skip) {
            std::vector<int> filtered;
            filtered.reserve(levels_.size() - 1);
            for (size_t i = 0; i < levels_.size(); ++i)
                if (i != skip) filtered.push_back(levels_[i]);
            return is_safe(filtered);
        }
    );
}

}  // namespace pjexx::aoc2024
