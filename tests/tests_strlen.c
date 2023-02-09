/*
** EPITECH PROJECT, 2023
** tests_strlen.c
** File description:
** tests_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern size_t strlen(const char *str);

Test(strlen, len_3)
{
    cr_assert_eq(strlen("OUI"), 3);
}

Test(strlen, len_1)
{
    cr_assert_eq(strlen("O"), 1);
}


Test(strlen, len_10)
{
    cr_assert_eq(strlen("OUI et NON"), 10);
}

Test(strlen, len_0)
{
    cr_assert_eq(strlen(""), 0);
}