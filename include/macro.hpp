/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** macro
*/

#pragma once

#define cout(message) std::cout << message << std::endl
#define coutn(message) std::cout << message

#define eraise(message) ({ \
    cout(message); \
    exit(84); \
})

#define getChildren() ({ \
    obj->childrens.push_back(dat[i]); \
    if (!vcontains(makefile._names, dat[i])) makefile._names.push_back(dat[i]); \
})

#define getForEachChildren(n) ({ \
    for (int i = n; i < dat.size(); i++) getChildren(); \
})

#define pushEl(lv, child) ({ \
    lv.push_back(child); \
    pushParent(lv); \
})

#define pushParent(lv) ({ \
    lv.push_back(obj->parent); \
    lv.push_back(parent->parent); \
    makefile._links.push_back(lv); \
})

#define checkLink(n, name) !makefile._links[i][n].compare(name) && makefile._links[i][n].size() == name.size()
