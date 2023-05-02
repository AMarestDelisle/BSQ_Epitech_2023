/*
** EPITECH PROJECT, 2022
** find_square_in_int_map.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

square compare(square cord)
{
    if (cord.y <= cord.two)
        cord.res = cord.y;
    else
        cord.res = cord.two;
    return cord;
}

square compare_number(square cord)
{
    if (cord.y <= cord.x)
        cord = compare(cord);
    else if (cord.x <= cord.two)
        cord.res = cord.x;
    else
        cord.res = cord.two;
    return cord;
}

int change_one(int **int_array, int x, int y)
{
    square cord;

    if (int_array[x][y] == 0)
        cord.res = 0;
    else {
        cord.y = int_array[x][y - 1];
        cord.x = int_array[x - 1][y];
        cord.two = int_array[x - 1][y - 1];
        cord = compare_number(cord);
        int_array[x][y] = (cord.res + 1);
    }
    return 0;
}

int browse_array(int **int_array, int x, int y)
{
    int i = 1;
    int j = 1;

    while (i < x) {
        while (j < y) {
            change_one(int_array, i, j);
            j++;
        }
        i++;
        j = 1;
    }
    find_biggest_square(int_array, x, y);
    return 0;
}
