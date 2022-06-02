/*
** EPITECH PROJECT, 2021
** launch_first_player_navy
** File description:
** launch_first_player_navy
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void ping(int sig, siginfo_t *info, void *unused_ptr)
{
    my_printf("successfully connected\n\n");
    user_info.pid = info->si_pid;
}

static void create_map(char *filepath, boat_maps_t *player)
{
    player->player_map = load_buffer_in_twod_array();
    player->enemy_map = load_buffer_in_twod_array();
    player->player_map = parsing_position(player->player_map, filepath);
    if (player->player_map == NULL)
        return;
}

int launch_second_player(char **argv)
{
    pid_t pid_second = getpid();
    struct sigaction act;
    boat_maps_t second_player;
    char *file = NULL;

    if ((file = load_file_in_mem(argv[2])) == NULL)
        return 84;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &ping;
    my_printf("my_pid: %d\n", pid_second);
    kill(my_getnbr(argv[1]), SIGUSR2);
    sigaction(SIGUSR1, &act, NULL);
    pause();
    create_map(file, &second_player);
    if (second_player.player_map == NULL)
        return 84;
    displaying_map(&second_player);
    return game_player_two(&second_player);
}
