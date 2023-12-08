/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-anastasiia.beginia
** File description:
** struct.h
*/
#include <stdbool.h>

#ifndef MYLS_STRUCT_H
    #define MYLS_STRUCT_H
struct ls_flags {
    bool multiple_directories;
    bool set_dir;
    bool has_dir;
    bool has_files;
    bool l_flag;
    bool r_flag;
    bool d_flag;
    bool a_flag;
    bool t_flag;
    bool R_flag;
    char **directories;
};
typedef struct ls_flags ls_flags_t;
#endif //MYLS_STRUCT_H
