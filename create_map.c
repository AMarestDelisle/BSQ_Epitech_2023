/*
** EPITECH PROJECT, 2023
** create_map.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int **transform(char *buffer, int lines)
{
    int x = 0;
    int **int_array = malloc(sizeof(int*) * (lines + 1));

    for (int i = 0; buffer[x]; i++) {
        int_array[i] = malloc(sizeof(int) * lines);
        for (int j = 0; j <= lines; j++, x++) {
            if (buffer[x] == '.')
                int_array[i][j] = 1;
            if (buffer[x] == 'o')
                int_array[i][j] = 0;
        }
    }
    return int_array;
}

char *generate_map(char *buffer, char *pattern, int lines, int all)
{
    int len = my_strlen(pattern);
    int i = 0;
    int sentence = 0;

    for (int j = 0; i < all; i++, j++, sentence++) {
        if (j == len)
            j = 0;
        if (sentence == lines) {
            buffer[i] = '\n';
            i++;
            sentence = 0;
        }
        buffer[i] = pattern[j];
    }
    buffer[all] = '\0';
    return buffer;
}

int **create_map(char *pattern, int lines)
{
    int len = my_strlen(pattern);
    char *buffer = NULL;
    int all = (lines) * (lines + 1);
    int **array;

    if (len == 0 || lines <= 0) {
        write(2, "number lines or length of pattern non fonctionnal\n", 50);
        return NULL;
    }
    buffer = malloc(sizeof(char) * (all + 1));
    if (buffer == NULL) {
        write(2, "problem with malloc\n", 20);
        return NULL;
    }
    buffer = generate_map(buffer, pattern, lines, all);
    array = transform(buffer, lines);
    return array;
}
