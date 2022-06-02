/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-chloe.camus
** File description:
** is_file_valid
*/

#include <stdlib.h>
#include <stdbool.h>
#include "navy.h"
#include "my.h"

static int check_nb_boats(char *buffer)
{
    int count = 0;
    int line_checker = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        for (line_checker = 0; buffer[i] != '\n' && buffer[i] != '\0'; i += 1)
            line_checker += 1;
        if (line_checker != 7)
            return 84;
        count += 1;
    }
    if (count != 4)
        return 84;
    return 0;
}

static int check_placement_validity(char *buffer, int i)
{
    if (buffer[i] < '2' || buffer[i] > '5')
        return 84;
    i += 1;
    for (int j = 0; j < 2; j++) {
        if (buffer[i] != ':')
            return 84;
        i += 1;
        if (buffer[i] < 'A' || buffer[i] > 'H')
            return 84;
        if (buffer[i + 1] < '1' || buffer[i + 1] > '8')
            return 84;
        i += 2;
    }
    return 0;
}

static int check_boats(char *buffer, int i)
{
    int boat_size = buffer[i] - '1';
    int flag = 0;

    i += 2;
    if (buffer[i] != buffer[i + 3]) {
        if (buffer[i] != buffer[i + 3] - boat_size)
            return 84;
        flag += 1;
    }
    i += 1;
    if (buffer[i] != buffer[i + 3]) {
        if (buffer[i] != buffer[i + 3] - boat_size)
            return 84;
        flag += 1;
    }
    if (flag == 2)
        return 84;
    return 0;
}

int is_file_valid(const char *filepath)
{
    char *buffer = load_file_in_mem(filepath);
    bool boat_size[] = {false, false, false, false};

    if (buffer == NULL)
        return 84;
    if (check_nb_boats(buffer) == 84)
        return 84;
    for (int i = 0; i < 4; i += 1) {
        if (boat_size[buffer[i * 8] - '2'] == true)
            return 84;
        else
            boat_size[buffer[i * 8] - '2'] = true;
        if (check_placement_validity(buffer, i * 8) == 84)
            return 84;
        else if (check_boats(buffer, i * 8) == 84)
            return 84;
    }
    free(buffer);
    return 0;
}
