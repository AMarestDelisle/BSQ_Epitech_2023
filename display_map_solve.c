/*
** EPITECH PROJECT, 2022
** display_map_solve.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int put_x(coord coord, big square, int nb)
{
    if (coord.x >= square.x && coord.x <= square.xstart &&
    coord.y >= square.y && coord.y <= square.ystart)
        write(1, "x", 1);
    else if (nb == 0)
        write(1, "o", 1);
    else
        write(1, ".", 1);
    return 0;
}

int change_array_with_x(int **int_array, struct big square, int x, int y)
{
    coord coord;
    coord.x = 0;
    coord.y = 0;

    while (coord.x < x) {
        while (coord.y < y) {
            put_x(coord, square, int_array[coord.x][coord.y]);
            coord.y++;
        }
        write(1, "\n", 1);
        coord.y = 0;
        coord.x++;
    }
    return 0;
}

big conditionnal(int **int_array, int i, int j, struct big square)
{
    if (int_array[i][j] > square.number) {
        square.xstart = i;
        square.ystart = j;
        square.number = int_array[i][j];
    }
    return square;
}

int find_biggest_square(int **int_array, int x, int y)
{
    big square;
    int i = 1;
    int j = 1;
    square.number = 0;

    while (i < x) {
        while (j < y) {
            square = conditionnal(int_array, i, j, square);
            j++;
        }
        i++;
        j = 1;
    }
    square.x = square.xstart - (square.number - 1);
    square.y = square.ystart - (square.number - 1);
    change_array_with_x(int_array, square, x, y);
    return 0;
}
