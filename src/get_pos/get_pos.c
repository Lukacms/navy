/*
** EPITECH PROJECT, 2021
** get_pos_by_signal
** File description:
** get_pos
*/

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "navy.h"
#include "my.h"

static void add_nbr(int sig, siginfo_t *info, void *unused_ptr)
{
    if (info->si_pid == user_info.pid) {
        if (sig == SIGUSR1) {
            user_info.packet <<= 1;
            user_info.packet |= 0;
        } else if (sig == SIGUSR2) {
            user_info.packet <<= 1;
            user_info.packet |= 1;
        } else
            return;
        user_info.signals_left_to_receive -= 1;
    }
}

int get_position_signal(void)
{
    struct sigaction act;

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &add_nbr;
    if (sigaction(SIGUSR1, &act, NULL) == -1)
        return 84;
    if (sigaction(SIGUSR2, &act, NULL) == -1)
        return 84;
    user_info.signals_left_to_receive = 7;
    user_info.packet = 0;
    my_printf("waiting for enemy's attack...\n");
    while (user_info.signals_left_to_receive > 0) {
        pause();
    }
    return 0;
}
