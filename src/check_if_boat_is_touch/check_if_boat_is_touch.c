/*
** EPITECH PROJECT, 2021
** packet_to_coordinates
** File description:
** packet_to_coordinates
*/

#include <signal.h>
#include <ucontext.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void check_if_boat_is_touched(int x, int y, boat_maps_t *boat)
{
    char letter = x + 65;
    char number = y + 49;

    x = (x * 2) + 2;
    y = y + 2;
    usleep(1000);
    if (boat->player_map[y][x] >= '1' && boat->player_map[y][x] <= '5') {
        my_printf("%c%c: hit", letter, number);
        kill(user_info.pid, SIGUSR1);
        boat->player_map[y][x] = 'x';
        user_info.health_points -= 1;
    } else {
        my_printf("%c%c: missed", letter, number);
        kill(user_info.pid, SIGUSR2);
        boat->player_map[y][x] = 'o';
    }
}

void packet_to_coordinates(boat_maps_t *boat)
{
    int x = user_info.packet % 8;
    int y = user_info.packet / 8;

    check_if_boat_is_touched(x, y, boat);
    my_printf("\n");
}
