/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** make
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <istream>

#include "./macro.hpp"

enum entryType {
    None,
    Master,
    Compile
};

class entry {
    public:
        entry() {};
        ~entry() = default;

        enum entryType type;

        entry *compiloEntry;
        std::string compilo;
        std::string line;
        std::string parent;
        std::vector<std::string> childrens;
};

class make {
    public:
        make() {};
        ~make() = default;

        std::ifstream _stream;
        std::ifstream _fileStream;
        std::vector<std::string> _data;
        std::vector<entry*> _entries;
        std::vector<entry*> _tmp;
        std::vector<std::vector<std::string> > _links;
        std::vector<std::string> _names;

        static bool sorter(const std::vector<std::string>& left, const std::vector<std::string>& right)
        {
            try {
                for (int i = 0; i < left.size() && i < right.size(); i++)
                    if (left[i] > right[i]) return (true);
                    else if (left[i] < right[i]) return false;
            } catch (...) { return false; }
        }
};

#include "./function.hpp"
