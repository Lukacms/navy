/*
** EPITECH PROJECT, 2021
** displaying
** File description:
** displaying
*/

#include "navy.h"
#include "my.h"

void displaying_map(boat_maps_t *boats)
{
    my_printf("my positions:\n");
    for (int i = 0; i <= 10; i += 1)
        my_printf("%s\n", boats->player_map[i]);
    my_printf("enemy's positions:\n");
    for (int i = 0; i <= 10; i += 1)
        my_printf("%s\n", boats->enemy_map[i]);
}
