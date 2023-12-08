/*
** EPITECH PROJECT, 2023
** B-CPE-100-PAR-1-1-cpoolday06-anastasiia.beginia
** File description:
** task1
*/

char *my_strcpy(char *dest, char const *src)
{
    char *ptr = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ptr;
}
