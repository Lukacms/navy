/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-chloe.camus
** File description:
** tests_navy_errors
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_file_valid, test_incorrect_boat_size)
{
    const char *filepath = "./tests/incorrect_boat_size";

    cr_assert_eq(is_file_valid(filepath), 84);
}

Test(is_file_valid, test_incorrect_char)
{
    const char *filepath = "./tests/incorrect_char";

    cr_assert_eq(is_file_valid(filepath), 84);
}

Test(is_file_valid, test_incorrect_line_and_col_nb)
{
    const char *filepath = "./tests/incorrect_line_nb";
    const char *filepath2 = "./tests/incorrect_col_nb";

    cr_assert_eq(is_file_valid(filepath), 84);
    cr_assert_eq(is_file_valid(filepath2), 84);
}

Test(is_file_valid, test_incorrect_total_boats_sizes)
{
    const char *filepath = "./tests/incorrect_boat_size";

    cr_assert_eq(is_file_valid(filepath), 84);
}

Test(is_file_valid, test_incorect_filepath)
{
    const char *filepath = "./tests/oui";

    cr_assert_eq(is_file_valid(filepath), 84);
}

Test(is_file_valid, test_return_valid_file)
{
    const char *filepath = "./assets/pos1";

    cr_assert_eq(is_file_valid(filepath), 0);
}

Test(lauch, test_for_not_enough_arg)
{
    int argc = 1;
    char *argv[] = {"oui"};

    cr_assert_eq(launch(argc, argv), 84);
}

Test(lauch, test_for_too_many_arg)
{
    int argc = 5;
    char *argv[] = {"oui", "ok", "encore", "je", "m'amuse"};

    cr_assert_eq(launch(argc, argv), 84);
}
