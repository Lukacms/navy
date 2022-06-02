/*
** EPITECH PROJECT, 2021
** position_parsing
** File description:
** position_parsing
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "navy.h"
#include "my.h"

static void get_position(ship_t *ship, char *position, int i)
{
    ship->len = position[i];
    i += 2;
    ship->start = position + i;
    ship->start[2] = '\0';
    i += 3;
    ship->end = position + i;
    ship->end[2] = '\0';
}

char **parsing_position(char **navy_map, char *position)
{
    ship_t ship;
    int count = 0;

    for (int i = 0; count < 4; i += 8) {
        if (position[i] == '\n')
            i += 1;
        get_position(&ship, position, i);
        navy_map = write_pos_in_map(navy_map, &ship);
        if (navy_map == NULL)
            return NULL;
        count += 1;
    }
    return navy_map;
}
