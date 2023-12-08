/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** header for parser.c
*/
#include "struct.h"

#ifndef MYLS_PARSER_H
    #define MYLS_PARSER_H
ls_flags_t get_flags(int, char **);
char **get_folder_names(int, char **, ls_flags_t *);
#endif //MYLS_PARSER_H
