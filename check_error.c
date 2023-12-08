/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-anastasiia.beginia
** File description:
** checks if directory exists
*/
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "include/my.h"
#include "include/helper.h"

void print_error(char *directory)
{
    my_print_error("my_ls: cannot access ");
    my_print_error(directory);
    my_print_error(": No such file or directory\n");
    exit(84);
}

void check_if_directory_exists(char *directory)
{
    DIR *dir = opendir(directory);

    if (is_file(directory) == 1)
        return;
    if (dir == NULL) {
        print_error(directory);
        exit(84);
    }
    if (is_directory(directory) == 1)
        closedir(dir);
}
