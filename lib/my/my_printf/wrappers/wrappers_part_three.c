/*
** EPITECH PROJECT, 2021
** Wrappers
** File description:
** Wrappers for struct
*/

#include <stdarg.h>
#include "my.h"

void my_putnbr_hexalow_unsigned_long(unsigned long nbr)
{
    char *base = "0123456789abcdef";
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_hexalow_unsigned_long(nbr / len);
        my_putchar(base[nbr % len]);
    }
    if (nbr < len)
        my_putchar(base[nbr % len]);
}

void my_put_pointer(unsigned long nbr)
{
    if (nbr == 0)
        my_putstr("(nil)");
    else {
        my_putstr("0x");
        my_putnbr_hexalow_unsigned_long(nbr);
    }
}

void wrapper_put_pointer(va_list *list)
{
    unsigned long data = va_arg(*list, unsigned long);

    my_put_pointer(data);
}
