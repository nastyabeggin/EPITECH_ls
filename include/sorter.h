/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** header for sorter.c
*/
#include "struct.h"

#ifndef MYLS_SORTER_H
    #define MYLS_SORTER_H
char **sort_alphabetically(char **, ls_flags_t *);
char **sort_folder_names(char **, ls_flags_t *);
char **sort_by_time(char **, char *, ls_flags_t *);
#endif //MYLS_SORTER_H
