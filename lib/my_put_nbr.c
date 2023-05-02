/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** By Arthur M-D
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
        return 0;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else if (nb < 10) {
        my_putchar(nb + '0');
    }
    return 0;
}
