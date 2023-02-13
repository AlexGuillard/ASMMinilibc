/*
** EPITECH PROJECT, 2023
** fonction.c
** File description:
** fonction
*/

#include <unistd.h>
#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char *strchr(const char *s, int c);

char *my_strchr(const char *s, int c)
{
    void *handle;
    handle = dlopen("./libmy.so", RTLD_LAZY);
    void *(*_strchr)(const char *, int);
    *(void**)(&_strchr) = dlsym(handle, "strchr");
    return (_strchr(s, c));
}