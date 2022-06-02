/*
** EPITECH PROJECT, 2021
** Wrappers
** File description:
** Wrappers for struct
*/

#include <stdarg.h>
#include "my.h"

void wrapper_putnbr_hexaup(va_list *list)
{
    int unsigned nbr = va_arg(*list, unsigned int);

    my_putnbr_hexaup(nbr);
}

void wrapper_putnbr_dec(va_list *list)
{
    unsigned int nbr = va_arg(*list, unsigned int);

    my_putnbr_dec(nbr);
}

void wrapper_uppercase_s(va_list *list)
{
    char *str = va_arg(*list, char *);

    uppercase_s(str);
}

void wrapper_putnbr_bin(va_list *list)
{
    unsigned int nbr = va_arg(*list, unsigned int);

    my_putnbr_bin(nbr);
}

void wrapper_put_percentage(va_list *list)
{
    put_percentage();
}
