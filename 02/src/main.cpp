/*********************************************************************
 * @file   main.cpp
 * @brief  Advent Of Code 2024: 02
 *
 * @author Philipp Jeske
 * @date   2024-12-04
 *********************************************************************/
/* SPDX-License-Identifier: MIT */

#include <argparse/argparse.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "report.h"

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("Advent Of Code 2024: 02");

    program.add_argument("input").help("Input file").default_value(std::string {"reports.txt"});

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err)
    {
        std::cerr << err.what() << '\n';
        std::cerr << program;
        return EXIT_FAILURE;
    }

    std::filesystem::path input_file {program.get<std::string>("input")};

    if (!std::filesystem::exists(input_file))
    {
        std::cerr << "Input file does not exist: " << input_file << '\n';
        return EXIT_FAILURE;
    }

    std::ifstream input_stream {input_file};

    std::vector<pjexx::aoc2024::Report> reports;

    std::string line;
    while (std::getline(input_stream, line))
    {
        std::istringstream line_stream {line};

        std::vector<int> levels;
        int level = 0;
        while (line_stream >> level)
        {
            levels.push_back(level);
        }

        reports.emplace_back(levels);
    }

    std::cout << "Out of " << reports.size() << " reports are "
              << std::ranges::count_if(reports, [](auto report) { return report.isSafe(); }) << " safe.\n";
    std::cout << "Out of " << reports.size() << " reports are "
              << std::ranges::count_if(reports, [](auto report) { return report.isSafeWithDampener(); })
              << " safe with problem dampener.\n";

    return EXIT_SUCCESS;
}
