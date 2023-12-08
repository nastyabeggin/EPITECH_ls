/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** parsing flags
*/
#include <stdlib.h>
#include <stdbool.h>
#include "include/struct.h"
#include "include/my.h"
#include "include/sorter.h"
#include "include/helper.h"
#include "include/check_error.h"

static void parse_flags(ls_flags_t *flags, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'l')
            flags->l_flag = true;
        if (str[i] == 'R')
            flags->R_flag = true;
        if (str[i] == 'd')
            flags->d_flag = true;
        if (str[i] == 'r')
            flags->r_flag = true;
        if (str[i] == 't')
            flags->t_flag = true;
        if (str[i] == 'a')
            flags->a_flag = true;
        i++;
    }
}

ls_flags_t get_flags(int argc, char **argv)
{
    ls_flags_t flags = {false, false, false, false, false, false, false,
        false, false, false};
    int dir_len = 0;
    bool met_dir_or_file;

    flags.multiple_directories = false;
    flags.set_dir = argc != 1;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && is_directory(argv[i]) == 1)
            dir_len++;
        if (is_file(argv[i]) == 1)
            flags.has_files = true;
        if (argv[i][0] != '-')
            met_dir_or_file = true;
        if (argv[i][0] == '-' && !met_dir_or_file)
            parse_flags(&flags, argv[i]);
    }
    flags.has_dir = dir_len > 0;
    flags.multiple_directories = dir_len > 1;
    return (flags);
}

static int get_number_of_dirs(int argc, char **argv)
{
    int dir_len = 0;
    bool met_dir = false;

    if (argc == 1)
        return 1;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || met_dir) {
            dir_len++;
            met_dir = true;
        }
    }
    return dir_len;
}

static void create_for_no_arg(char ***folder_names)
{
    (*folder_names)[0] = malloc(sizeof(char) * 3);
    (*folder_names)[0] = "./";
    (*folder_names)[1] = 0;
}

static void paste_file(char *filename, char ***folder_names, int *j)
{
    int str_len;

    str_len = my_strlen(filename);
    (*folder_names)[*j] = malloc(sizeof(char) * (str_len + 1));
    my_strcpy((*folder_names)[*j], filename);
    (*j)++;
}

int count_not_flags(int argc, char **argv)
{
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            count++;
    }
    return count;
}

char **get_folder_names(int argc, char **argv, ls_flags_t *flags)
{
    int dir_number = get_number_of_dirs(argc, argv);
    char **folder_names = malloc(sizeof(char *) * (dir_number + 1));
    bool met_dir = false;
    int i;
    int j = 0;

    if (count_not_flags(argc, argv) == 0) {
        create_for_no_arg(&folder_names);
        return folder_names;
    }
    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || met_dir) {
            met_dir = true;
            check_if_directory_exists(argv[i]);
            paste_file(argv[i], &folder_names, &j);
        }
    }
    folder_names = sort_folder_names(folder_names, flags);
    return folder_names;
}
