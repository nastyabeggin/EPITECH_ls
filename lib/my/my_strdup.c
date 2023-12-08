/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** my_strdup
*/
#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int strlen = my_strlen(src);

    str = malloc(sizeof(char) * strlen);
    str = my_strcpy(str, src);
    return str;
}