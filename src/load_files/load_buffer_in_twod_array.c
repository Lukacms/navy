/*
** EPITECH PROJECT, 2021
** load_buffer_in_twod_array
** File description:
** load_buffer_in_twod_array
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "navy.h"
#include "my.h"

char **load_buffer_in_twod_array(void)
{
    char *buff = load_file_in_mem("./assets/map.txt");
    char **navy_map = malloc(sizeof(char *) * 10);
    int count = 0;

    for (int i = 0; i <= 10; i += 1) {
        navy_map[i] = malloc(sizeof(char) * 17);
        for (int j = 0; buff[count] != '\n' && buff[count] != '\0'; j += 1) {
            navy_map[i][j] = buff[count];
            count += 1;
        }
        count += 1;
    }
    return navy_map;
}
