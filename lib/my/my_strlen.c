/*
** EPITECH PROJECT, 2023
** B-CPE-100-PAR-1-1-cpoolday04-anastasiia.beginia
** File description:
** task3
*/

int	my_strlen(char const *str)
{
    int	str_len;

    str_len = 0;
    while (*str != '\0') {
        str++ ;
        str_len++ ;
    }
    return (str_len);
}
