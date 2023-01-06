/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** processThreeArguments
*/

#include "include/make.hpp"

#define FIRST_LINK makefile._links[i][0]

static void secondSubProcess(make& makefile, int i, std::vector<std::string>& val)
{
    for (int y = 1; y < makefile._links[i].size(); y++) {
        std::vector<entry *> nt = getMP(makefile, makefile._links[i][y]);
        if (!nt.size()) eraise("");
        for (int u = 0; u < nt.size(); u++)
            if (!vcontains(val, nt[u]->compiloEntry->line))
                val.push_back(nt[u]->compiloEntry->line);
    }
}

static void firstSubProcess(make& makefile, char **av, std::vector<std::string>& val)
{
    for (int i = makefile._links.size() - 1; i >= 0; i--) {
        if (!FIRST_LINK.compare(av[1]) && FIRST_LINK.size() == std::string(av[1]).size())
            secondSubProcess(makefile, i, val);
    }
}

void processThreeArguments(make& makefile, char **av, std::string& line)
{
    try {
        for (int i = 0; i < strlen(av[1]); i++) {
            if (!(av[1][i] >= 'a' && av[1][i] <= 'z') &&
            !(av[1][i] >= 'A' && av[1][i] <= 'Z') &&
            (av[1][i] != '.')) eraise("");
        }
        if (line.find(".") == std::string::npos || line.size() <= 1 || !link(makefile) || getEP(makefile, av[1]) == NULL) eraise("");
        std::vector<std::string> val;
        firstSubProcess(makefile, av, val);
        std::sort(val.begin(), val.end(), std::greater<std::string>());
        if (!val.size()) {cout("");}
        else
            for (int i = val.size() - 1; i >= 0; i--) cout(val[i]);
    } catch (...) { exit(84); }
}