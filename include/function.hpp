/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** function
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>

int help(char **av);
bool parse(make& makefile, std::vector<std::string> dat, std::string line);
bool link(make& makefile);
bool matrix(make& makefile);
void processTwoArguments(make& makefile);
void processThreeArguments(make& makefile, char **av, std::string& line);
entry *getEP(make& makefile, std::string child);
std::vector<entry *>getMP(make& makefile, std::string child);
bool vcontains(std::vector<std::string> val, std::string v);
