/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-anastasiia.beginia
** File description:
** helping functions
*/
#include <sys/stat.h>
#include "include/my.h"

int my_arr_len(char **arr)
{
    int i = 0;

    while (arr[i] != 0)
        i++;
    return i;
}

int is_file(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int is_directory(const char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int str_len_pl(char *str)
{
    int len = my_strlen(str);

    return len + 1;
}

void reverse_array(char *arr[])
{
    char *temp;
    int i;
    int j = my_arr_len(arr) - 1;

    for (i = 0; i < j; i++) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}
