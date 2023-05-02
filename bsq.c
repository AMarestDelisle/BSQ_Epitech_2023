/*
** EPITECH PROJECT, 2022
** bsq.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int check(int size, int fd)
{
    int fs = 0;

    if (size == 0) {
        write(2, "empty file\n", 12);
        return 84;
    } else if (size == -1)
        return 84;
    else
        fs = fs_read(fd, size);
    if (fs == 84)
        return 84;
    return 0;
}

int bsq(char *filepath)
{
    int fd = 0;
    int size = 0;
    int checker = 0;

    fd = fd_open_file(filepath);
    if (fd == -84)
        return 84;
    else {
        size = recuperation_size(filepath);
        checker = check(size, fd);
    }
    if (checker == 84)
        return 84;
    return 0;
}
