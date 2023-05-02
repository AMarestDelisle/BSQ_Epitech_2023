/*
** EPITECH PROJECT, 2022
** find_biggest_square.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int send_buffer(char **array, int x, int buffer, int y)
{
    if (array[0][0] == 'o' && buffer == x * y)
        print_empty(array);
    else if (buffer == x && array[0][0] == '.')
        print_array_with_points(array, x, y);
    else
        malloc_map_int(array, x, y);
    return 0;
}

int reset_buffer(char **array, int x, int y, int *counter)
{
    int buffer = 0;

    if (array[x][y] == '.')
        (*counter)++;
    else
        buffer ++;
    return buffer;
}

int find_square_in_filled_empty_map(char **array)
{
    int x = 0;
    int y = 0;
    int counter = 0;
    int buffer = 0;

    for (x = 0; array[x] != NULL; x++) {
        counter = 0;
        for (y = 0; array[x][y] != '\0'; y++) {
            buffer += reset_buffer(array, x, y, &counter);
        }
    }
    send_buffer(array, x, buffer, y);
    return 0;
}
