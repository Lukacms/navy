/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-navy-chloe.camus
** File description:
** tests_basic_functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

void redirect(void);

Test(manging_h, test_managing_h_return)
{
    int argc = 2;
    char *argv[] = {"oui", "-h"};

    cr_assert_eq(launch(argc, argv), 0);
    cr_assert_eq(managing_h(argv), 0);
}
