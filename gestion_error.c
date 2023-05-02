/*
** EPITECH PROJECT, 2023
** gestion_error.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int check_intruder(char *buffer)
{
    int i = 0;

    for (; buffer[i] != '\n'; i++)
        if (buffer[i] < 48 && buffer[i] > 57) {
            write(2, "invalid first line\n", 19);
            return -1;
        }
    i++;
    for (; buffer[i]; i++)
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n') {
            write(2, "invalid symbole in file\n", 24);
            return -1;
        }
    return 0;
}

int check_chara(char *buffer, int *i, int first)
{
    int counter = 0;

    for (;buffer[*i] != '\n'; (*i)++) {
        counter++;
    }
    if (counter != first)
        return 84;
    return 0;
}

int true_number_chara_per_lines(char *buffer)
{
    int i = 0;
    int check = 0;
    int first = 0;
    int res = check_intruder(buffer);

    if (res == -1)
        return 84;
    for (; buffer[i] != '\n'; i++);
    i++;
    for (; buffer[i] != '\n'; i++)
        first++;
    i++;
    for (; buffer[i]; i++) {
        check = check_chara(buffer, &i, first);
        if (check == 84)
            return 84;
    }
    return 0;
}

int true_number_lines(char *buffer, int number)
{
    int counter = 0;
    int check;

    number += 1;
    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\n')
            counter++;
    if (counter == number) {
        check = true_number_chara_per_lines(buffer);
        if (check == 84) {
        write(2, "problem with format\n", 20);
        return -1;
        }
        return 0;
    } else {
        write(2, "invalid first line number\n", 26);
        return -1;
    }
    return 0;
}
