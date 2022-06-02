/*
** EPITECH PROJECT, 2021
** write_pos_in_map
** File description:
** write_pos_in_map
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "navy.h"

static int checking_ship_position(ship_t *ship)
{
    if (ship->start[0] != ship->end[0] && ship->start[1] != ship->end[1])
        return 84;
    return 0;
}

static char **put_boat_in_col(char **navy_map, int col, int line, ship_t *ship)
{
    for (int i = line; i < line + (ship->len - 48); i += 1) {
        if (navy_map[i][col] != '.')
            return NULL;
        navy_map[i][col] = ship->len;
    }
    return navy_map;
}

static char **put_boat_in_line(char **navy_map, int col, int line,
                                ship_t *ship)
{
    for (int i = col; i < col + (ship->len - 48) * 2; i += 2) {
        if (navy_map[line][i] != '.')
            return NULL;
        navy_map[line][i] = ship->len;
    }
    return navy_map;
}

char **write_pos_in_map(char **navy_map, ship_t *ship)
{
    int starter_col = (ship->start[0] - 65) * 2 + 2;
    int starter_line = (ship->start[1] - 48) + 1;

    if (checking_ship_position(ship) != 0)
        return NULL;
    if (ship->start[0] == ship->end[0])
        navy_map = put_boat_in_col(navy_map, starter_col, starter_line, ship);
    else
        navy_map = put_boat_in_line(navy_map, starter_col, starter_line, ship);
    if (navy_map == NULL)
        return NULL;
    return navy_map;
}
