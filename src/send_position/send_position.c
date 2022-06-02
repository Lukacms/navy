/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-chloe.camus
** File description:
** send_signal
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static unsigned int position_to_number(char *position)
{
    unsigned int pos = 0;

    pos = (position[1] - '1') * 8;
    pos += position[0] - 'A';
    return pos;
}

int send_position(char *position)
{
    unsigned int pos = position_to_number(position);
    unsigned int mask = 0;

    for (int i = 0; i < 7; i += 1) {
        mask = (pos << (32 - 7 + i)) >> (32 - 1);
        if (mask == 0)
            kill(user_info.pid, SIGUSR1);
        else
            kill(user_info.pid, SIGUSR2);
        usleep(1000);
    }
    return 0;
}
