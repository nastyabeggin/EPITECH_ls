/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** my_strcat.c
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
