/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** processThreeArguments
*/

#include "include/make.hpp"

void processTwoArguments(make& makefile)
{
    try {
        link(makefile);
        matrix(makefile);
        std::sort(makefile._links.begin(), makefile._links.end(), makefile.sorter);
        std::cout << std::endl;
        for (int i = makefile._links.size() - 1; i >= 0; i--) {
            for (int y = 0; y < makefile._links[i].size(); y++) {
                std::cout << makefile._links[i][y];
                if (y + 1 < makefile._links[i].size())
                    std::cout << " -> ";
            }
            cout("");
        }
    } catch (...) { exit(84); }
}