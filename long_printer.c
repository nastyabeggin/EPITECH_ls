/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-myls-anastasiia.beginia
** File description:
** -l flag
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include "include/struct.h"
#include "include/helper.h"
#include "include/my.h"

static char *get_permissions(mode_t mode)
{
    char *permissions = malloc(sizeof(char) * 10);

    permissions[0] = (mode & S_IRUSR) ? 'r' : '-';
    permissions[1] = (mode & S_IWUSR) ? 'w' : '-';
    permissions[2] = (mode & S_IXUSR) ? 'x' : '-';
    permissions[3] = (mode & S_IRGRP) ? 'r' : '-';
    permissions[4] = (mode & S_IWGRP) ? 'w' : '-';
    permissions[5] = (mode & S_IXGRP) ? 'x' : '-';
    permissions[6] = (mode & S_IROTH) ? 'r' : '-';
    permissions[7] = (mode & S_IWOTH) ? 'w' : '-';
    permissions[8] = (mode & S_IXOTH) ? 'x' : '-';
    permissions[8] = (mode & S_ISVTX) ? 't' : permissions[8];
    permissions[9] = '\0';
    return permissions;
}

static char *get_file_type(mode_t mode)
{
    char *file_type = malloc(sizeof(char) * 2);

    if (S_ISREG(mode))
        file_type[0] = '-';
    if (S_ISDIR(mode))
        file_type[0] = 'd';
    if (S_ISCHR(mode))
        file_type[0] = 'c';
    if (S_ISBLK(mode))
        file_type[0] = 'b';
    if (S_ISFIFO(mode))
        file_type[0] = 'p';
    if (S_ISLNK(mode))
        file_type[0] = 'l';
    if (S_ISSOCK(mode))
        file_type[0] = 's';
    file_type[1] = '\0';
    return file_type;
}

char *convert_time(char *old_time)
{
    char *new_time = malloc(sizeof(char) * 13);
    int i = 4;
    int j = 0;

    while (i < 16) {
        new_time[j] = old_time[i];
        i++;
        j++;
    }
    new_time[j] = '\0';
    return new_time;
}

char *get_full_path(char *path, char *file_name)
{
    char *full_path = malloc(sizeof(char) * (my_strlen(path) +
    my_strlen(file_name) + 2));
    int i = 0;
    int j = 0;

    while (path[i] != '\0') {
        full_path[i] = path[i];
        i++;
    }
    full_path[i] = '/';
    i++;
    while (file_name[j] != '\0') {
        full_path[i] = file_name[j];
        i++;
        j++;
    }
    full_path[i] = '\0';
    return full_path;
}

static void consider_device(struct stat *file_stat, char file_type)
{
    long int rdev = file_stat->st_rdev;
    int major_num = (rdev >> 24) & 0xff;
    int minor_num = rdev & 0xffffff;

    if (file_type == 'c' || file_type == 'b')
        mini_printf("%d, %d",
                    major_num, minor_num);
    else
        mini_printf("%d", file_stat->st_size);
}

void print_file_info(char *file_name, char *full_path)
{
    struct stat file_stat;
    struct passwd *pwd;
    struct group *grp;
    char *time;
    char *file_type;
    char *permissions;

    stat(full_path, &file_stat);
    lstat(full_path, &file_stat);
    pwd = getpwuid(file_stat.st_uid);
    grp = getgrgid(file_stat.st_gid);
    time = convert_time(ctime(&file_stat.st_mtime));
    file_type = get_file_type(file_stat.st_mode);
    permissions = get_permissions(file_stat.st_mode);
    mini_printf("%s%s %d %s %s ", file_type,
                permissions, file_stat.st_nlink, pwd->pw_name, grp->gr_name);
    consider_device(&file_stat, file_type[0]);
    mini_printf(" %s %s\n", time, file_name);
}

void long_print_files(char **files_array, char *path)
{
    int i;
    char *full_path;

    for (i = 0; i < my_arr_len(files_array); i++) {
        full_path = get_full_path(path, files_array[i]);
        print_file_info(files_array[i], full_path);
    }
}

void print_total_blocks(char **dir_array, char *path)
{
    int i;
    long total_blocks = 0;
    struct stat fileStat;
    char *full_path;

    for (i = 0; dir_array[i] != NULL; i++) {
        full_path = get_full_path(path, dir_array[i]);
        if (stat(full_path, &fileStat) == 0)
            total_blocks += fileStat.st_blocks;
    }
    mini_printf("total %d\n", total_blocks);
}
