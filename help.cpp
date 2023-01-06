/*
** EPITECH PROJECT, 2021
** 303make
** File description:
** help
*/

#include "include/make.hpp"

int help(char **av)
{
    cout("USAGE");
    cout("\t" << *av << " makefile [file]");
    cout("DESCRIPTION");
    cout("\tmakefile\tname of the makefile");
    cout("\tfile\t\tname of a recently modified file");
    return 0;
}