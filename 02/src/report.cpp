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

    auto is_safe_after_removal = [this](size_t skip) {
        auto filtered = levels_ 
            | std::views::enumerate
            | std::views::filter([skip](const auto& pair) { return pair.first != skip; })
            | std::views::transform([](const auto& pair) { return pair.second; });

        std::vector<int> modified(filtered.begin(), filtered.end());

        auto isPairwiseDistanceSafe = [](int val1, int val2)
        { return std::abs(val1 - val2) > 0 && std::abs(val1 - val2) <= 3; };

        bool pairwiseDistanceSafe = std::ranges::all_of(
            modified | std::views::pairwise_transform(isPairwiseDistanceSafe),
            [](bool item) { return item; });

        return pairwiseDistanceSafe &&
               (std::ranges::is_sorted(modified) || std::ranges::is_sorted(modified, std::greater {}));
    };

    return std::ranges::any_of(
        std::views::iota(size_t{0}, levels_.size()),
        is_safe_after_removal
    );
}

}  // namespace pjexx::aoc2024
