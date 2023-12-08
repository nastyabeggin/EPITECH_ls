/*
** EPITECH PROJECT, 2023
** B-CPE-100-PAR-1-1-cpoolday04-anastasiia.beginia
** File description:
** task2
*/
#include "my.h"

int	my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str++);
    }
    return (0);
}
