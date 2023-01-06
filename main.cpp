/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** main
*/

#include "include/make.hpp"

make makefile;

static void fileProcess(std::string& line)
{
    std::string cpy = std::string(line.c_str());
    std::vector<std::string> splitedData;

    for (size_t pos = line.find(" "); std::string::npos != pos; pos = line.find(" ")) {
        if (line.substr(0, pos).size())
            splitedData.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    if (line.length() > 1 && line.size()) splitedData.push_back(line);
    parse(makefile, splitedData, cpy);
}

static void parsing(char **av, std::string& line)
{
    try {
        makefile._stream.open(*av);
        if (makefile._stream.fail()) eraise("Bad input.");
        while (std::getline(makefile._stream, line)) {
            makefile._data.push_back(line.c_str());
            if (std::string::npos != line.find(" ")) fileProcess(line);
        }
    } catch (...) { exit(84); }
}

int main(int ac, char **av)
{
    std::string line;

    if (2 <= ac && (!strcmp(av[1], "-h") || !strcmp(av[1], "-help"))) return help(av);
    if (2 > ac || (2 != ac && 3 != ac)) eraise("Bad usage.");
    av++;
    parsing(av, line);
    if (!makefile._entries.size()) return 84;
    if (2 == ac) processTwoArguments(makefile);
    else if (3 == ac) processThreeArguments(makefile, av, line);
    return 0;
}