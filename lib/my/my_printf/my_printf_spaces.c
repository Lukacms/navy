/*
** EPITECH PROJECT, 2021
** my printf spaces
** File description:
** Function for space flag of my printf
*/

#include "my.h"

void spaces_nbr(int *argument, int nbr)
{
    int tmp = 1;
    int result = 0;

    while (tmp < argument[0]) {
        tmp *= 10;
        result += 1;
    }
    nbr -= result;
    for (; nbr > 0; nbr -= 1) {
        my_putchar(' ');
    }
}

void spaces_strings(char *argument, int nbr)
{
    nbr -= my_strlen(argument);
    for (; nbr > 0; nbr -= 1)
        my_putchar(' ');
}

void spaces_characters(char *argument, int nbr)
{
    nbr -= 1;

    for (; nbr > 0; nbr -= 1)
        my_putchar(' ');
}
