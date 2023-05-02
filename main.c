/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** By Arthur M-D
*/

#include "my_bsq.h"

int main(int ac, char * const *av)
{
    int res = 0;
    int **buffer;

    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2) {
        res = bsq(av[1]);
        if (res == 84)
            return 84;
        else
            return 0;
    } else {
        buffer = create_map(av[2], my_getnbr(av[1]));
        browse_array(buffer, my_getnbr(av[1]), my_getnbr(av[1]));
    }
}
