/*
** EPITECH PROJECT, 2022
** my_bsq.h
** File description:
** By Arthur M-D
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#ifndef MY_BSQ_H_
    #define MY_BSQ_H_
    typedef struct s_square {
        int x;
        int y;
        int two;
        int res;
    }square;
    typedef struct s_coord {
        int x;
        int y;
    }coord;
    typedef struct big {
        int x;
        int y;
        int number;
        int xstart;
        int ystart;
    }big;
    typedef struct s_length {
        int y;
        int x;
        int less;
    }length;
    int my_strlen(char const *str);
    int getnbr(char c);
    int my_getnbr(char *str);
    int bsq(char *filepath);
    int fd_open_file(char const *filepath);
    int recuperation_size(char *filepath);
    int fs_read(int fd, int size);
    int first_line(char *buffer);
    int malloc_array(char *buffer, int lines);
    int fill_array(char **array, int counter, char *buffer);
    int full_array(char **array, int counter, char *buffer, int *i);
    int find_square_in_filled_empty_map(char **array);
    int print_empty(char **array);
    int print_array_full_point(char **array, int xmax, int ymax, int x);
    int reset_buffer(char **array, int x, int y, int *counter);
    int send_buffer(char **array, int x, int buffer, int y);
    int print_array_with_points(char **array, int xmax, int ymax);
    int malloc_map_int(char **array, int xmax, int ymax);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int find_square_in_filled_empty_map(char **array);
    int find_biggest_square(int **int_array, int x, int y);
    int malloc_map_int(char **array, int xmax, int ymax);
    int browse_array(int **int_array, int x, int y);
    int true_number_lines(char *buffer, int number);
    int true_number_chara_per_lines(char *buffer);
    int **create_map(char *patern, int lines);
#endif /* MY_BSQ_H_ */
