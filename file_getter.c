/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** get info about file
*/
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "include/sorter.h"
#include "include/long_printer.h"
#include "include/my.h"
#include "include/parser.h"
#include "include/printer.h"
#include "include/helper.h"

int get_number_of_files(char *dir_name)
{
    DIR *pDir = opendir(dir_name);
    struct dirent *pDirent = readdir(pDir);
    int total = 0;

    while (pDirent != NULL) {
        if (pDirent->d_name[0] != '.')
            total ++;
        pDirent = readdir(pDir);
    }
    return total;
}

static void alloc_mem_for_st(char **files_array,
    struct dirent *pDirent, int output)
{
    int str_len = my_strlen(pDirent->d_name);

    files_array[output] = malloc(sizeof(char) * (str_len + 1));
    my_strcpy(files_array[output], pDirent->d_name);
}

char **get_files(char *dir_name, ls_flags_t *flags)
{
    DIR *pDir = opendir(dir_name);
    struct dirent *pDirent = readdir(pDir);
    int output = 0;
    char **files_array;

    files_array = malloc(sizeof(char *) * (get_number_of_files(dir_name) + 1));
    while (pDirent != NULL) {
        if (pDirent->d_name[0] == '.' && !flags->a_flag) {
            pDirent = readdir(pDir);
            continue;
        }
        alloc_mem_for_st(files_array, pDirent, output);
        output ++;
        pDirent = readdir(pDir);
    }
    files_array[output] = 0;
    files_array = (flags->t_flag ? sort_by_time(files_array, dir_name, flags) :
        sort_alphabetically(files_array, flags));
    closedir(pDir);
    return files_array;
}

void proceed_for_one_dir(char **dir_names, ls_flags_t *flags)
{
    char **files_array;

    if (flags->set_dir)
        return;
    if (my_arr_len(dir_names) == 1) {
        if (is_directory(dir_names[0]) == 1) {
            files_array = get_files(dir_names[0], flags);
            print_files(files_array, flags, dir_names[0]);
        } else
            mini_printf("%s\n", dir_names[0]);
    }
    exit(0);
}

static bool is_last_file(char *dir_name, char **dir_names)
{
    int i = 0;

    while (is_file(dir_names[i]) == 1 && dir_names[i] != 0)
        i++;
    if (my_strcmp(dir_name, dir_names[i - 1]) == 0)
        return true;
    return false;
}

static bool is_last_dir(char *dir_name, char **dir_names)
{
    int last_ind = my_arr_len(dir_names) - 1;

    if (my_strcmp(dir_name, dir_names[last_ind]) == 0)
        return true;
    return false;
}

static void proceed_file(char *dir_name, ls_flags_t *flags)
{
    if (flags->l_flag) {
        print_file_info(dir_name, dir_name);
        if (is_last_file(dir_name, flags->directories) && flags->has_dir)
            mini_printf("\n");
        return;
    }
    mini_printf("%s", dir_name);
    if (is_last_file(dir_name, flags->directories) && flags->has_dir)
        mini_printf("\n\n");
    else if (!flags->has_dir && is_last_file(dir_name, flags->directories))
        mini_printf("\n");
    else
        mini_printf("  ");
}

void proceed_file_or_dir(char *dir_name, ls_flags_t *flags)
{
    char **files_array;

    if (is_file(dir_name) == 1)
        proceed_file(dir_name, flags);
    else {
        if (flags->multiple_directories || flags->has_files)
            mini_printf("%s:\n", dir_name);
        files_array = get_files(dir_name, flags);
        print_files(files_array, flags, dir_name);
        if (!is_last_dir(dir_name, flags->directories))
            mini_printf("\n");
    }
}
