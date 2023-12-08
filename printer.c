/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-anastasiia.beginia
** File description:
** prints file names
*/
#include "include/my.h"
#include "include/struct.h"
#include "include/long_printer.h"

static int get_arr_len(char **arr)
{
    int i = 0;

    while (arr[i] != 0)
        i++;
    return i;
}

static int get_number_of_rows(char **files_array)
{
    int length = get_arr_len(files_array) / 6;

    if (get_arr_len(files_array) % 6 != 0)
        length++;
    return length;
}

static void print_element(char **files_array, int i, int j)
{
    if (i + j * get_number_of_rows(files_array) > get_arr_len(files_array))
        return;
    if (files_array[i + j * get_number_of_rows(files_array)] == 0)
        return;
    mini_printf(files_array[i + j * get_number_of_rows(files_array)]);
    mini_printf(" ");
}

void print_files(char **files_array, ls_flags_t *flags, char *path)
{
    int i;
    int j;
    int number_of_rows = get_number_of_rows(files_array);

    if (flags->l_flag == true) {
        print_total_blocks(files_array, path);
        long_print_files(files_array, path);
        return;
    }
    for (i = 0; i < number_of_rows; i++) {
        for (j = 0; j < 6; j++) {
            print_element(files_array, i, j);
        }
        mini_printf("\n");
    }
}
