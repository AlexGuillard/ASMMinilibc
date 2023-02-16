/*
** EPITECH PROJECT, 2023
** tests_memcpy
** File description:
** tests_memcpy
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <dlfcn.h>

Test(memcpy, basic)
{
    // void *handle = NULL;
    // void *(*fptr)(void *, const void *, size_t);
    // char array[] = "fegr";
    // char *copy = malloc(sizeof(char) * 3);

    // handle = dlopen("../libasm.so", RTLD_NOW);
    // *(void **)(&fptr) = dlsym(handle, "memcpy");
    // char *res = (*fptr)(copy, array, sizeof(char) * 2);
    // cr_assert_str_eq("fe", res);
    // cr_assert_str_eq("fe", copy);
}

// Test(memcpy, long_one)
// {
//     void *handle = NULL;
//     void *(*fptr)(void *, const void *, size_t);
//     char array[] = "fegr";
//     char *copy = malloc(sizeof(char) * 4);

//     handle = dlopen("../libasm.so", RTLD_NOW);
//     *(void **)(&fptr) = dlsym(handle, "memcpy");
//     char *res = (*fptr)(copy, array, sizeof(char) * 4);
//     cr_assert_str_eq("fegr", res);
//     cr_assert_str_eq("fegr", copy);
// }

// Test(memcpy, long_int)
// {
//     void *handle = NULL;
//     void *(*fptr)(void *, const void *, size_t);
//     int array [] = { 54, 85, 20, 63, 21 };
//     int length = sizeof( int ) * 5;
//     int *copy = (int *) malloc( length );

//     handle = dlopen("../libasm.so", RTLD_NOW);
//     *(void **)(&fptr) = dlsym(handle, "memcpy");
//     int *res = (*fptr)(copy, array, length);
//     cr_assert_eq(54, res[0]);
//     cr_assert_eq(85, res[1]);
//     cr_assert_eq(20, res[2]);
//     cr_assert_eq(63, res[3]);
//     cr_assert_eq(21, res[4]);
//     cr_assert_eq(54, copy[0]);
//     cr_assert_eq(85, copy[1]);
//     cr_assert_eq(20, copy[2]);
//     cr_assert_eq(63, copy[3]);
//     cr_assert_eq(21, copy[4]);
// }