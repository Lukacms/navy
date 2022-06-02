/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-chloe.camus
** File description:
** load_file_in_mem
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "navy.h"

char *load_file_in_mem(char const *filepath)
{
    int fd = -1;
    int status = -1;
    char *buffer = NULL;

    if (filepath == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (180 + 1));
    status = read(fd, buffer, 180);
    if (status < 0)
        return NULL;
    buffer[status] = '\0';
    close(fd);
    return buffer;
}
