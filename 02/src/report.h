/*********************************************************************
 * @file report.h
 * @brief
 *
 * @author Philipp Jeske
 * @date 2024-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#pragma once
#ifndef PJEXX_AOC2024_DISTCALC_H_
#define PJEXX_AOC2024_DISTCALC_H_

#include <initializer_list>
#include <ranges>
#include <vector>

namespace pjexx::aoc2024
{
class Report
{
  public:
    explicit Report(std::ranges::input_range auto &&levels) : levels_(levels) {}
    explicit Report(std::initializer_list<int> levels);

    bool isSafe() const;
    bool isSafeWithDampener() const;

  private:
    std::vector<int> levels_;
};

}  // namespace pjexx::aoc2024

#endif  // PJEXX_AOC2024_DISTCALC_H_
