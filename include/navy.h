/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <sys/stat.h>
    #include <signal.h>
    #include <ucontext.h>
    #include <sys/types.h>

typedef struct ship_s {
    char len;
    char *start;
    char *end;
} ship_t;

typedef struct boat_maps_s {
    char **player_map;
    char **enemy_map;
} boat_maps_t;

typedef struct user_info_s {
    unsigned int packet;
    pid_t pid;
    int signals_left_to_receive;
    unsigned int health_points;
    unsigned int enemy_health;
    int enemy_touched;
} user_info_t;

extern user_info_t user_info;

int launch(int argc, char **argv);
int is_file_valid(const char *filepath);
int managing_h(char **argc);
int launch_second_player(char **argv);
int launch_first_player(char **argv);
char *load_file_in_mem(char const *filepath);
char **load_buffer_in_twod_array(void);
char **parsing_position(char **navy_map, char *position);
char **write_pos_in_map(char **navy_map, ship_t *ship);
int get_position_signal(void);
char *my_get_nbr_binary(char nbr);
char *get_user_input(void);
int send_position(char *position);
void displaying_map(boat_maps_t *boat);
int game_player_one(boat_maps_t *boat);
int game_player_two(boat_maps_t *boat);
void packet_to_coordinates(boat_maps_t *boat);
void is_enemy_touched(boat_maps_t *boat, char *position);

#endif /* !NAVY_H_ */
