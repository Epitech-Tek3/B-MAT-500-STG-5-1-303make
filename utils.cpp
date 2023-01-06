/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** utils
*/

#include "include/make.hpp"

bool vcontains(std::vector<std::string> val, std::string v)
{
    try {
        for (int i = 0; i < val.size(); i++)
            if (!val[i].compare(v) && val[i].size() == v.size()) return (true);
    } catch (...) { return (false); }
    return (false);
}

static bool contains(std::string val, char c)
{
    for (int i = 0; i < val.size(); i++)
        if (val[i] == c) return (true);
    return (false);
}

bool parse(make& makefile, std::vector<std::string> dat, std::string line)
{
    try {
        entry *obj = new entry();

        if (!dat.size()) exit(84);
        if (':' == dat[0][dat[0].length() - 1]) {
            obj->type = Master;
            dat[0].erase(dat[0].length() - 1);
            obj->parent = dat[0];
            if (!vcontains(makefile._names, obj->parent)) makefile._names.push_back(obj->parent);
            getForEachChildren(1);
        } else if ("cc" == dat[0]) {
            obj->compilo = dat[1];
            obj->type = Compile;
            getForEachChildren(2);
            if (makefile._entries.size() && makefile._entries.back()->type == Master)
                makefile._entries.back()->compiloEntry = obj;
        } else exit(84);
        obj->line = line;
        makefile._tmp.push_back(obj);
        makefile._entries.push_back(obj);
    } catch (...) { exit(84); }
    return (true);
}

entry *getEP(make& makefile, std::string child)
{
    try {
        for(int i = 0; i < makefile._entries.size(); i++)
            for (int x = 0; x < makefile._entries[i]->childrens.size(); x++)
                if (!makefile._entries[i]->childrens[x].compare(child) && makefile._entries[i]->childrens[x].size() == child.size())
                    return (makefile._entries[i]);
    } catch (...) { exit(84); }
}

std::vector<entry *>getMP(make& makefile, std::string child)
{
    std::vector<entry *> n;

    try {
        for(int i = 0; i < makefile._entries.size(); i++) {
            if (makefile._entries[i]->type != Master) continue;
            if (!makefile._entries[i]->parent.compare(child) && makefile._entries[i]->parent.size() == child.size())
                n.push_back(makefile._entries[i]);
        }
    } catch (...) { return (n); }
    return (n);
}

bool link(make& makefile)
{
    try {
        while (makefile._tmp.size()) {
            entry *obj = makefile._tmp.back();
            entry *parent;

            makefile._tmp.pop_back();
            if (obj->type == Compile || !contains(obj->parent, '.')) return (link(makefile));
            if (!obj->childrens.size()) exit(84);
            parent = getEP(makefile, obj->parent);
            std::vector<std::string> val;
            pushEl(val, obj->childrens[0]);
            std::vector<std::string> small;
            pushParent(small);
            if (obj->childrens.size() < 2) exit(84);
            std::vector<std::string> temp;
            pushEl(temp, obj->childrens[1]);
        }
    } catch (...) { exit(84); }
    return (true);
}

static bool dep(make& makefile, std::string name1, std::string name2)
{
    try {
        for (int i = 0; i < makefile._links.size(); i++) {
            if (makefile._links[i].size() < 2) continue;
            if (checkLink(0, name1) && checkLink(1, name2)) return (true);
        }
        return (false);
    } catch (...) { return (false); }
}

bool matrix(make& makefile)
{
    if (!makefile._names.size()) exit(84);
    try {
        std::sort(makefile._names.begin(), makefile._names.end(), std::less<std::string>());
        for (int i = 0; i < makefile._names.size(); i++) {
            for (int y = 0; y < makefile._names.size(); y++) {
                if (y == 0) coutn("[");
                if (i == y) coutn("0");
                else if (dep(makefile, makefile._names[i], makefile._names[y])) coutn("1");
                else coutn("0");
                if (y + 1 < makefile._names.size()) coutn(" ");
                else cout("]");
            }
        }
    } catch (...) { exit(84); }
    return (true);
}