/*
** EPITECH PROJECT, 2021
** Wrappers
** File description:
** Wrappers for struct
*/

#include <stdarg.h>
#include "my.h"

void wrapper_putnbr(va_list *list)
{
    int nbr = va_arg(*list, int);

    my_put_nbr(nbr);
}

void wrapper_putchar(va_list *list)
{
    char ch = va_arg(*list, int);

    my_putchar(ch);
}

void wrapper_putstr(va_list *list)
{
    char *string = va_arg(*list, char *);

    my_putstr(string);
}

void wrapper_putnbr_oct(va_list *list)
{
    unsigned int nbr = va_arg(*list, unsigned int);

    my_putnbr_oct(nbr);
}

void wrapper_putnbr_hexalow(va_list *list)
{
    unsigned int nbr = va_arg(*list, unsigned int);

    my_putnbr_hexalow(nbr);
}
