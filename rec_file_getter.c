/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-bsmyls-anastasiia.beginia
** File description:
** get list of files recursively
*/
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include "include/my.h"
#include "include/rec_file_getter.h"
#include "include/file_getter.h"
#include "include/helper.h"
#include "include/check_error.h"

void initialize_folder_array(FolderArray *array)
{
    array->paths = malloc(INITIAL_CAPACITY * sizeof(char *));
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
}

void add_folder_path(FolderArray *array, const char *path)
{
    array->paths[array->size] = my_strdup(path);
    array->size++;
}

void free_folder_array(FolderArray *array)
{
    for (size_t i = 0; i < array->size; i++) {
        free(array->paths[i]);
    }
    free(array->paths);
}

static void concat_strings(char *result, size_t result_size,
    char *str1, char *str2)
{
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);

    if (len1 + len2 + 1 > result_size) {
        result[0] = '\0';
    } else {
        my_strcpy(result, str1);
        if (my_strcmp(str1, "./") != 0)
            my_strcat(result, "/");
        my_strcat(result, str2);
    }
}

static void check_error(DIR *dir, char *dir_name)
{
    if (dir == NULL) {
        print_error(dir_name);
        exit(84);
    }
}

static void process_subf(char *entry_path, FolderArray *array)
{
    DIR *subdir = opendir(entry_path);

    if (subdir != NULL) {
        add_folder_path(array, entry_path);
        list_subfolders(entry_path, array);
        closedir(subdir);
    }
}

void list_subfolders(char *dir_path, FolderArray *array)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry = readdir(dir);
    char entry_path[PATH_MAX];

    check_error(dir, dir_path);
    while (entry != NULL) {
        if (entry->d_name[0] == '.') {
            entry = readdir(dir);
            continue;
        }
        concat_strings(entry_path, sizeof(entry_path),
    dir_path, entry->d_name);
        process_subf(entry_path, array);
        entry = readdir(dir);
    }
    closedir(dir);
}

void work_with_r_flag(char **dir_names, ls_flags_t *flags)
{
    int i;
    FolderArray folderArray;

    initialize_folder_array(&folderArray);
    for (i = 0; i < my_arr_len(dir_names); i++) {
        add_folder_path(&folderArray, dir_names[i]);
        if (is_file(dir_names[i]) == 1)
            continue;
        list_subfolders(dir_names[i], &folderArray);
    }
    flags->directories = folderArray.paths;
    flags->multiple_directories = folderArray.size > 1;
    flags->has_dir = folderArray.size > 1;
    flags->set_dir = true;
    for (i = 0; i < folderArray.size; i++)
        proceed_file_or_dir(folderArray.paths[i], flags);
}
