/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** header for rec_file_getter.c
*/
#include "struct.h"

#ifndef MYLS_REC_FILE_GETTER_H
    #define MYLS_REC_FILE_GETTER_H
    #define INITIAL_CAPACITY 10000000

typedef struct {
    char **paths;
    size_t size;
    size_t capacity;
} FolderArray;
void initialize_folder_array(FolderArray *);
void list_subfolders(char *, FolderArray *);
void add_folder_path(FolderArray *, const char *);
void work_with_r_flag(char **, ls_flags_t *);
#endif //MYLS_REC_FILE_GETTER_H
