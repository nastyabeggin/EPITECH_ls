/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-anastasiia.beginia
** File description:
** sort files and directories
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "include/my.h"
#include "include/struct.h"
#include "include/helper.h"
#include "include/check_error.h"

static void change_files(char *files_array[], int i, int j)
{
    char *temp;

    if (my_strcmp((files_array)[i], (files_array)[j]) > 0) {
        temp = (files_array)[i];
        (files_array)[i] = (files_array)[j];
        (files_array)[j] = temp;
    }
}

static long get_time(char *file_name, char *dir_name)
{
    int length = my_strlen(file_name) + my_strlen(dir_name) + 1;
    char *path = malloc(sizeof(char) * length);
    struct stat path_stat;
    long time;

    my_strcpy(path, dir_name);
    my_strcat(path, "/");
    my_strcat(path, file_name);
    stat(path, &path_stat);
    lstat(path, &path_stat);
    time = path_stat.st_mtime;
    return (time);
}

static void change_files_by_time(char *files_array[], char *dir_name,
    int i, int j)
{
    char *temp;
    long time1 = get_time(files_array[i], dir_name);
    long time2 = get_time(files_array[j], dir_name);

    if (time1 < time2) {
        temp = (files_array)[i];
        (files_array)[i] = (files_array)[j];
        (files_array)[j] = temp;
    }
    if (time1 == time2)
        change_files(files_array, i, j);
}

char **sort_by_time(char **files_array, char *dir_name, ls_flags_t *flags)
{
    int i = 0;
    int j = 0;

    while (files_array[i] != 0) {
        j = i + 1;
        while (files_array[j] != 0) {
            change_files_by_time(files_array, dir_name, i, j);
            j++;
        }
        i++;
    }
    if (flags->r_flag)
        reverse_array(files_array);
    return files_array;
}

char **sort_alphabetically(char **files_array, ls_flags_t *flags)
{
    int i = 0;
    int j = 0;

    while (files_array[i] != 0) {
        j = i + 1;
        while (files_array[j] != 0) {
            change_files(files_array, i, j);
            j++;
        }
        i++;
    }
    if (flags->r_flag)
        reverse_array(files_array);
    return files_array;
}

static void paste_if_file(char **dir_array, char ***copy_array, int i, int *j)
{
    if (is_file(dir_array[i]) == 1) {
        (*copy_array)[*j] = malloc(sizeof(char) * str_len_pl(dir_array[i]));
        my_strcpy((*copy_array)[*j], dir_array[i]);
        *j = *j + 1;
    }
}

char **sort_folder_names(char **dir_array, ls_flags_t *flags)
{
    int i = 0;
    int j = 0;
    char **copy_array = malloc(sizeof(char *) * (my_arr_len(dir_array) + 1));

    for (i = 0; i < my_arr_len(dir_array); i++) {
        check_if_directory_exists(dir_array[i]);
        paste_if_file(dir_array, &copy_array, i, &j);
    }
    copy_array = flags->t_flag ? sort_by_time(copy_array, ".", flags) :
        sort_alphabetically(copy_array, flags);
    for (i = 0; i < my_arr_len(dir_array); i++) {
        if (is_directory(dir_array[i]) == 1) {
            copy_array[j] = malloc(sizeof(char) * str_len_pl(dir_array[i]));
            my_strcpy(copy_array[j], dir_array[i]);
            j++;
        }
    }
    copy_array[j] = 0;
    return copy_array;
}
