/*
** EPITECH PROJECT, 2021
** launch_first_player_navy
** File description:
** launch_first_player_navy
*/

#include <signal.h>
#include <ucontext.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void pong(int sig, siginfo_t *info, void *unused_ptr)
{
    my_printf("enemy connected\n\n");
    user_info.pid = info->si_pid;
    kill(info->si_pid, SIGUSR1);
}

static void create_map(char *filepath, boat_maps_t *player)
{
    player->player_map = NULL;
    player->enemy_map = NULL;
    player->player_map = load_buffer_in_twod_array();
    player->enemy_map = load_buffer_in_twod_array();
    player->player_map = parsing_position(player->player_map, filepath);
    if (player->player_map == NULL)
        return;
}

int launch_first_player(char **argv)
{
    pid_t pid_first = getpid();
    struct sigaction act;
    char *file = NULL;
    boat_maps_t first_player;

    if ((file = load_file_in_mem(argv[1])) == NULL)
        return 84;
    my_printf("my_pid: %d\n", pid_first);
    my_printf("waiting for enemy connection...\n\n");
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &pong;
    sigaction(SIGUSR2, &act, NULL);
    create_map(file, &first_player);
    if (first_player.player_map == NULL)
        return 84;
    pause();
    displaying_map(&first_player);
    return game_player_one(&first_player);
}
