##
## EPITECH PROJECT, 2021
## B-PSU-100-BDX-1-1-bsmyls-chloe.camus
## File description:
## Makefile
##

SRC	=	src/get_pos/get_pos.c	\
		src/managing_h/managing_h.c	\
		src/is_file_valid.c	\
		src/displaying/displaying.c	\
		src/second_player/game_player_two.c	\
		src/first_player/game_player_one.c	\
		src/load_files/load_file_in_mem.c	\
		src/get_user_input/get_user_input.c	\
		src/send_position/send_position.c	\
		src/position_parsing/position_parsing.c	\
		src/position_parsing/write_pos_in_map.c	\
		src/first_player/launch_first_player_navy.c	\
		src/second_player/launch_second_player.c	\
		src/load_files/load_buffer_in_twod_array.c	\
		src/check_if_boat_is_touch/is_enemy_touched.c	\
		src/check_if_boat_is_touch/check_if_boat_is_touch.c	\
		src/launch.c

SRC_MAIN	=	src/main.c

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

SRC_TESTS	=	tests/tests_navy_errors.c	\
				tests/tests_basic_functions.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

NAME_TESTS	=	unit_test

NAME	=	navy

LIBMY	=	lib/libmy.a

$(LIBMY)	=	make re -C lib/my

CFLAGS	=	-W -Wall -Wextra -Wpedantic

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./lib

LDLIBS	=	-lmy

all:	$(NAME)

$(LIBMY):
	make -C lib/my

$(NAME):	$(OBJ) $(OBJ_MAIN) $(LIBMY)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

debug: fclean
debug: CFLAGS += -g
debug: $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_MAIN) $(OBJ_TESTS)
	make clean -C lib/my
	rm -f src/*.gc*
	rm -f src/managing_h/*.gc*
	rm -f src/check_if_boat_is_touch/*.gc*
	rm -f src/displaying/*.gc*
	rm -f src/first_player/*.gc*
	rm -f src/get_pos/*.gc*
	rm -f src/get_user_input/*.gc*
	rm -f src/load_files/*.gc*
	rm -f src/position_parsing/*.gc*
	rm -f src/second_player/*.gc*
	rm -f src/send_position/*.gc*
	rm -f tests/*.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

tests_run:	CPPFLAGS	+=	--coverage
tests_run:	CFLAGS	+=	-fprofile-arcs -ftest-coverage
tests_run:	LDLIBS	+=	-lcriterion -lgcov -lmy
tests_run:	fclean $(OBJ) $(OBJ_TESTS) $(LIBMY)
	gcc -o $(NAME_TESTS) $(OBJ) $(OBJ_TESTS) $(LDFLAGS) $(LDLIBS)
	-./$(NAME_TESTS)

coverage:
	gcovr --exclude tests
	gcovr --exclude tests --branches
.PHONY:	tests_run coverage

re:	fclean all clean

.PHONY:	fclean all clean re
