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
    enum class Monotonicity : std::uint8_t
    {
        Increasing,
        Decreasing
    };

    std::optional<int> prev                  = std::nullopt;
    std::optional<Monotonicity> monotonicity = std::nullopt;

    int violationCount = 0;

    for (auto item : levels_)
    {
        if (!prev)
        {
            prev = item;
            continue;
        }

        bool violation = false;

        if (std::abs(*prev - item) == 0 || std::abs(*prev - item) > 3)
        {
            violation = true;
        }

        auto currentMonotonicity = *prev < item ? Monotonicity::Increasing : Monotonicity::Decreasing;

        if (monotonicity && *monotonicity != currentMonotonicity)
        {
            violation = true;
        }
        else if (!monotonicity)
        {
            monotonicity = currentMonotonicity;
        }

        if (violation && ++violationCount <= 1)
        {
            continue;
        }

        if (violation)
        {
            return false;
        }

        prev = item;
    }

    return true;
}
}  // namespace pjexx::aoc2024
