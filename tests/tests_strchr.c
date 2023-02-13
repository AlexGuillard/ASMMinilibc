/*
** EPITECH PROJECT, 2023
** tests_strlen.c
** File description:
** tests_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strchr(const char *s, int c);

// Test(strchr, len_3)
// {
//     cr_assert_eq(strchr("OUI", 'I'), my_strchr("OUI", 'I'));
// }

// Test(strchr, len_1)
// {
//     cr_assert_eq(strchr("O", 'O'), my_strchr("O", 'O'));
// }

// Test(strchr, len_1_2)
// {
//     cr_assert_eq(strchr("OUI et NON", 'O'), my_strchr("OUI et NON", 'O'));
// }

// Test(strchr, len_5)
// {
//     cr_assert_eq(strchr("OUI et NON", 'e'), my_strchr("OUI et NON", 'e'));
// }


// Test(strchr, len_0)
// {
//     cr_assert_eq(strchr("OUI et NON", 'Z'), my_strchr("OUI et NON", 'Z'));
// }

// Test(strchr, len_void)
// {
//     cr_assert_eq(strchr("OUI et NON", '\0'), my_strchr("OUI et NON", '\0'));
// }


// Test(strchr, len_void_1)
// {
//     cr_assert_eq(strchr("\0", 'a'), my_strchr("\0", 'a'));
// }

// Test(strchr, len_void_2)
// {
//     cr_assert_eq(strchr("\0", '\0'), my_strchr("\0", '\0'));
// }