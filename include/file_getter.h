/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** header for file_getter.c
*/
#include "struct.h"

#ifndef BOOTSTRAP_MY_LS_FILE_GETTER_H
    #define BOOTSTRAP_MY_LS_FILE_GETTER_H
void my_ls(int, char **);
void proceed_for_one_dir(char **, ls_flags_t *);
void proceed_file_or_dir(char *, ls_flags_t *);
#endif //BOOTSTRAP_MY_LS_FILE_GETTER_H
