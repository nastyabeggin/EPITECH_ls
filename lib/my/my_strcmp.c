/*
** EPITECH PROJECT, 2023
** B-CPE-100-PAR-1-1-cpoolday06-anastasiia.beginia
** File description:
** task6
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    if (*s1 - *s2 < 0) {
        return -1;
    } else
    if (*s1 - *s2 > 0) {
        return 1;
    } else {
        return 0;
    }
}
