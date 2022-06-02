/*
** EPITECH PROJECT, 2021
** is_enemy_touched
** File description:
** is_enemy_touched
*/

#include <signal.h>
#include <ucontext.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void enemy_touched(boat_maps_t *boat, char *position)
{
    int x = (position[0] - 65) * 2 + 2;
    int y = (position[1] - 48) + 1;

    user_info.enemy_touched -= 1;
    position[2] = '\0';
    my_printf("%s: hit", position);
    boat->enemy_map[y][x] = 'x';
}

static void enemy_not_touched(boat_maps_t *boat, char *position)
{
    int x = (position[0] - 65) * 2 + 2;
    int y = (position[1] - 48) + 1;

    position[2] = '\0';
    my_printf("%s: missed", position);
    boat->enemy_map[y][x] = 'o';
}

static void write_on_enemy_map(int sig)
{
    if (sig == SIGUSR1)
        user_info.enemy_touched = 0;
    else
        user_info.enemy_touched = 1;
}

void is_enemy_touched(boat_maps_t *boat, char *position)
{
    struct sigaction act;

    user_info.enemy_touched = 0;
    act.sa_handler = &write_on_enemy_map;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    pause();
    if (user_info.enemy_touched == 0)
        enemy_touched(boat, position);
    else
        enemy_not_touched(boat, position);
    usleep(1000);
    my_printf("\n");
}
