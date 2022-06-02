/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** My_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

static const modifier_t characters_flags[] = {
    {.flag = '#', .fptr = &display_hashtag},
    {.flag = ' ', .fptr = &display_space},
    {.flag = '1', .fptr = &get_nbr_for_spaces},
    {.flag = '2', .fptr = &get_nbr_for_spaces},
    {.flag = '3', .fptr = &get_nbr_for_spaces},
    {.flag = '4', .fptr = &get_nbr_for_spaces},
    {.flag = '5', .fptr = &get_nbr_for_spaces},
    {.flag = '6', .fptr = &get_nbr_for_spaces},
    {.flag = '7', .fptr = &get_nbr_for_spaces},
    {.flag = '8', .fptr = &get_nbr_for_spaces},
    {.flag = '9', .fptr = &get_nbr_for_spaces},
    {.flag = '\0', .fptr = NULL}
};

static const flags_t convertion_flags[] = {
    {.flag = 'd', .fptr = &wrapper_putnbr},
    {.flag = 'i', .fptr = &wrapper_putnbr},
    {.flag = 's', .fptr = &wrapper_putstr},
    {.flag = 'c', .fptr = &wrapper_putchar},
    {.flag = 'b', .fptr = &wrapper_putnbr_bin},
    {.flag = 'x', .fptr = &wrapper_putnbr_hexalow},
    {.flag = 'X', .fptr = &wrapper_putnbr_hexaup},
    {.flag = 'o', .fptr = &wrapper_putnbr_oct},
    {.flag = 'u', .fptr = &wrapper_putnbr_dec},
    {.flag = 'S', .fptr = &wrapper_uppercase_s},
    {.flag = '%', .fptr = &wrapper_put_percentage},
    {.flag = 'p', .fptr = &wrapper_put_pointer},
    {.flag = '\0', .fptr = NULL},
};

flags_t const *cross_convertion_flags(va_list *list, char ch)
{
    for (int j = 0; convertion_flags[j].flag != '\0'; j += 1) {
        if (convertion_flags[j].flag == ch)
            return &convertion_flags[j];
    }
    return NULL;
}

modifier_t const *cross_characters_flags(va_list *list, char ch)
{
    for (int j = 0; characters_flags[j].flag != '\0'; j += 1) {
        if (characters_flags[j].flag == ch)
            return &characters_flags[j];
    }
    return NULL;
}

int conditions(int *i, char const *format, va_list *list, va_list *temp)
{
    const modifier_t *chara_f = NULL;
    const flags_t *convert_f = NULL;
    void *arguments = NULL;

    if (format[i[0]] == '%') {
        i[0] += 1;
        chara_f = cross_characters_flags(list, format[i[0]]);
        if (!(chara_f == NULL)) {
            chara_f->fptr(format, i, va_arg(*temp, void *));
            i[0] += 1;
        }
        convert_f = cross_convertion_flags(list, format[i[0]]);
        if (!(convert_f == NULL))
            convert_f->fptr(list);
    } else {
        my_putchar(format[i[0]]);
    }
}

int my_printf(char const *format, ...)
{
    va_list list;
    va_list temp;
    int err = 0;

    va_copy(temp, list);
    va_start(list, format);
    va_start(temp, format);
    for (int i = 0; format[i] != '\0'; i += 1) {
        err = conditions(&i, format, &list, &temp);
        if (err == 84)
            return 84;
    }
    va_end(list);
    va_end(temp);
    return 0;
}
