/*
** EPITECH PROJECT, 2023
** tests_strlen.c
** File description:
** tests_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern char *strchr(const char *s, int c);

Test(strchr, len_3)
{
    cr_assert_eq(strchr("OUI", 'I'), "I");
}

Test(strchr, len_1)
{
    cr_assert_eq(strchr("O", 'O'), "O");
}


Test(strchr, len_1_2)
{
    cr_assert_eq(strchr("OUI et NON", 'O'), "OUI et NON");
}



Test(strchr, len_5)
{
    cr_assert_eq(strchr("OUI et NON", 'e'), "et NON");
}


Test(strchr, len_0)
{
    cr_assert_eq(strchr("OUI et NON", 'Z'), 0);
}
