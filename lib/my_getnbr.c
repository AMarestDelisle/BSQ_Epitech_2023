/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** By Arthur M-D
*/

int next(char *str, int i)
{
    int sign = 1;

    if (str[i] >= 47 && str[i] <= 58)
        if (str[i - 1] == '-')
            sign = -1;
    return (sign);
}

int my_getnbr(char *str)
{
    int sign = 0;
    int number = 0;
    int max = 2147483647;
    int min = -2147483647;

    for (int i = 0; str[i] != '\0'; i++) {
        sign = next(str, i);
        if (str[i] > max - number)
            return (0);
        if (str[i] < min + number)
            return (0);
        number = number * 10;
        number = (number + str[i] - 48);
    }
    number = number * sign;
    return (number * sign);
}
