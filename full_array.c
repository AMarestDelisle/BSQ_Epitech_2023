/*
** EPITECH PROJECT, 2022
** full_array.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int full_array(char **array, int counter, char *buffer, int *i)
{
    int x = 0;
    int y = 0;

    while (buffer[*i] != '\0') {
        array[x] = malloc(sizeof(char) * (counter + 1));
        while (buffer[(*i)] != '\n' && buffer[*i]) {
            array[x][y] = buffer[(*i)];
            (*i)++;
            y++;
        }
        (*i)++;
        array[x][y] = '\n';
        array[x][y + 1] = '\0';
        y = 0;
        x++;
    }
    free(buffer);
    find_square_in_filled_empty_map(array);
    return 0;
}

int fill_array(char **array, int counter, char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    i++;
    full_array(array, counter, buffer, &i);
    return 0;
}

int malloc_array(char *buffer, int lines)
{
    char **array = malloc(sizeof(char *) * (lines + 1));
    int i = 0;
    int counter = 0;

    array[lines] = NULL;
    while (buffer[i] != '\n')
        i++;
    i++;
    while (buffer[i] != '\n') {
        i++;
        counter++;
    }
    counter++;
    fill_array(array, counter, buffer);
    return 0;
}

int first_line(char *buffer)
{
    int i = 0;
    int res = 0;
    int multi = 1;
    int error;

    while (buffer[i] != '\n') {
        res *= multi;
        if (getnbr(buffer[i]) >= 0) {
            res += getnbr(buffer[i]);
            multi = 10;
            i++;
        } else
            return -1;
    }
    error = true_number_lines(buffer, res);
    if (error == -1)
        return -1;
    return res;
}
