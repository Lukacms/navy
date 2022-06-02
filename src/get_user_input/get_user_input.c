/*
** EPITECH PROJECT, 2021
** get_user_input
** File description:
** get_user_input
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

char *get_user_input(void)
{
    char *line = NULL;
    size_t len_line = 0;
    int flag = 0;

    while (flag != 1) {
        my_printf("attack: ");
        if (getline(&line, &len_line, stdin) == -1)
            return NULL;
        if (my_strlen(line) - 1 == 2 && line[0] >= 'A' && line[0] <= 'H'
            && line[1] >= '1' && line[1] <= '8')
            flag = 1;
        else
            my_printf("wrong position\n");
    }
    return line;
}
