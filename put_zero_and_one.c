/*
** EPITECH PROJECT, 2022
** put_zero_and_one.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int **put_0_and_1_in_map(char **array, int **int_array, int x, int y)
{
    if (array[x][y] == '.')
        int_array[x][y] = 1;
    else if (array[x][y] == 'o')
        int_array[x][y] = 0;
    return int_array;
}

int fill_map_int(char **array, int **int_array)
{
    int i = 0;
    int j = 0;

    for (; array[i]; i++)
        for (j = 0; array[i][j]; j++);
    j--;
    for (int x = 0; x < i; x++)
        for (int y = 0; y < j; y++)
            int_array = put_0_and_1_in_map(array, int_array, x, y);
    for (int f = 0; array[f]; f++)
        free(array[f]);
    free(array);
    browse_array(int_array, i, j);
    return 0;
}

int malloc_map_int(char **array, int xmax, int ymax)
{
    int x = 0;
    int **int_array = malloc(sizeof(int *) * (xmax + 1));

    ymax -= 1;
    int_array[xmax] = NULL;
    while (x < xmax) {
        int_array[x] = malloc(sizeof(int) * (ymax + 1));
        int_array[x][ymax] = '\0';
        x++;
    }
    fill_map_int(array, int_array);
    return 0;
}
