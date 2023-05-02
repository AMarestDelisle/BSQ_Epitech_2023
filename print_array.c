/*
** EPITECH PROJECT, 2022
** print_array.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int print_array_full_point(char **array, int xmax, int ymax, int x)
{
    char c = 'x';

    for (int y = 0; array[x][y] != '\0'; y++) {
        if (x < ymax && y < xmax && array[x][y] != '\n')
            write(1, &c, 1);
        else
            write(1, &array[x][y], 1);
    }
    return 0;
}

int print_array_with_points(char **array, int xmax, int ymax)
{
    for (int x = 0; array[x] != NULL; x++)
        print_array_full_point(array, xmax, ymax, x);
    return 0;
}

int print_empty(char **array)
{
    for (int x = 0; array[x] != NULL; x++)
        for (int y = 0; array[x][y] != '\0'; y++)
            write(1, &array[x][y], 1);  
    return 0;
}
