/*
** EPITECH PROJECT, 2023
** B-CPE-100-PAR-1-1-cpoolday03-anastasiia.beginia
** File description:
** task7
*/
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
    return (0);
}
