/*
** EPITECH PROJECT, 2021
** game_player_one
** File description:
** game_player_one
*/

#include <signal.h>
#include <ucontext.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

int game_player_one(boat_maps_t *boat)
{
    char *position;

    user_info.health_points = 14;
    user_info.enemy_health = 14;
    while (user_info.health_points > 0 && user_info.enemy_health > 0) {
        position = get_user_input();
        send_position(position);
        is_enemy_touched(boat, position);
        my_printf("\n");
        get_position_signal();
        packet_to_coordinates(boat);
        my_printf("\n");
        displaying_map(boat);
    }
    if (user_info.enemy_health == 0) {
        my_printf("I won\n");
        return 0;
    }
    my_printf("Enemy won\n");
    return 1;
}
