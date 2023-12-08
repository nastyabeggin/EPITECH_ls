/*
** EPITECH PROJECT, 2023
** B-CPE-101-PAR-1-1-miniprintf-anastasiia.beginia
** File description:
** mini_printf func
*/
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

static int len_helper(unsigned x)
{
    if (x >= 1000000000)
        return 10;
    if (x >= 100000000)
        return 9;
    if (x >= 10000000)
        return 8;
    if (x >= 1000000)
        return 7;
    if (x >= 100000)
        return 6;
    if (x >= 10000)
        return 5;
    if (x >= 1000)
        return 4;
    if (x >= 100)
        return 3;
    if (x >= 10)
        return 2;
    return 1;
}

static int print_len(int x)
{
    int res = x < 0 ? len_helper(-x) + 1 : len_helper(x);

    return res;
}

int handle_after(char format, void *param)
{
    int count = 1;

    switch (format) {
    case 'i':
    case 'd':
        my_put_nbr((int) param);
        count = print_len((int) param);
        break;
    case 's':
        my_putstr((char *) param);
        count = my_strlen((char *) param);
        break;
    case 'c':
        my_putchar((char) param);
        break;
    default:
        my_putchar('%');
    }
    return count;
}

int mini_printf(const char *format , ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    while (*format != '\0') {
        if (*format != '%') {
            my_putchar(*format);
            count ++;
            format ++;
            continue;
        }
        format ++;
        if (*format == '%')
            count += handle_after(*format, &count);
        else
            count += handle_after(*format, va_arg(list, void *));
        format ++;
    }
    va_end(list);
    return count;
}
