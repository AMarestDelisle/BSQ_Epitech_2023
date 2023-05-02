/*
** EPITECH PROJECT, 2022
** open_read.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int fs_read(int fd, int size)
{
    char *buffer = malloc(sizeof(char) *(size + 1));
    int fs_read = read(fd, buffer, size);
    int first_line_number = 0;

    if (fs_read != size) {
        write(2, "problem with read encounter", 28);
        return 84;
    } else {
        buffer[size] = '\0';
        first_line_number = first_line(buffer);
        if (first_line_number < 2) {
            write(2, "first line false", 16);
            return 84;
        } else {
            malloc_array(buffer, first_line_number);
            return 0;
        }
    }
}

int recuperation_size(char *filepath)
{
    int result = 0;
    struct stat informations;
    int res = stat(filepath, &informations);
    if (res != 0) {
        write(2, "problem size encounter", 22);
        return -1;
    } else
        result = informations.st_size;
    return result;
}

int fd_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        write(2, "open file problem", 17);
        return -84;
    } else
        return fd;
}
