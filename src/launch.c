/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "navy.h"

user_info_t user_info = {0};

int launch(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return managing_h(argv);
    if (is_file_valid(argv[argc - 1]) == 84)
        return 84;
    else if (argc == 2)
        return launch_first_player(argv);
    if (argc == 3)
        return launch_second_player(argv);
    return 84;
}
