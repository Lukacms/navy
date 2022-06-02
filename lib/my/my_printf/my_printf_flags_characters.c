/*
** EPITECH PROJECT, 2021
** my printf character flags
** File description:
** Function for character flags
*/

#include "my.h"
#include <stdio.h>

static const converter_and_symbol_t hashtag[] = {
    {.flag = 'o', .str = "0"},
    {.flag = 'x', .str = "0x"},
    {.flag = 'X', .str = "0X"},
    {.flag = '\0', .str = NULL},
};

void display_hashtag(char *format, int *i, void *tmp)
{
    int flag = 0;
    int string_pointer = 0;

    for (int j = 0; hashtag[j].flag != '\0'; j += 1) {
        if (hashtag[j].flag == format[i[0] + 1]) {
            string_pointer = j;
            flag = 1;
        }
    }
    if (flag != 0)
        my_putstr(hashtag[string_pointer].str);
}

void display_space(char *format, int *i, int argument)
{
    if (argument >= 0 && format[i[0] + 1] == 'd' || format[i[0] + 1] == 'i' ) {
        my_putchar(' ');
    }
}

void get_nbr_for_spaces(char *format, int *i, void *argument)
{
    int nbr = 0;
    int nbr_spaces = 1;

    for (; format[i[0]] >= '0' && format[i[0]] <= '9'; i[0] += 1) {
        nbr += format[i[0]] - 48;
        if (format[i[0] + 1] >= '0' && format[i[0] + 1] <= '9')
            nbr *= 10;
    }
    if (format[i[0]] == 'i' || format[i[0]] == 'd')
        spaces_nbr(argument, nbr);
    if (format[i[0]] == 's')
        spaces_strings(argument, nbr);
    else if (format[i[0]] == 'c')
        spaces_characters(argument, nbr);
    i[0] -= 1;
}

void put_percentage(void)
{
    my_putchar('%');
}
