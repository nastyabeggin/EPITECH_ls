/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** my_ls function
*/
#include <stdlib.h>
#include "include/file_getter.h"
#include "include/parser.h"
#include "include/helper.h"
#include "include/my.h"
#include "include/rec_file_getter.h"

void my_ls(int argc, char **argv)
{
    ls_flags_t flags = get_flags(argc, argv);
    char **dir_names = get_folder_names(argc, argv, &flags);
    int j;

    if (flags.R_flag)
        work_with_r_flag(dir_names, &flags);
    else {
        flags.directories = dir_names;
        proceed_for_one_dir(dir_names, &flags);
        for (j = 0; j < my_arr_len(dir_names); j++)
            proceed_file_or_dir(dir_names[j], &flags);
    }
}
