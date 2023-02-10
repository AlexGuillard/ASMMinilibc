/*
** EPITECH PROJECT, 2023
** main test
** File description:
** main
*/

#include <unistd.h>
#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern size_t strlen(const char *str);
extern char *strchr(const char *s, int c);
extern char *strrchr(const char *s, int c);

int main()
{

    void *handle;
    handle = dlopen("./libmy.so", RTLD_LAZY);

    int total = 14;
    int passed = 0;
    int failed = 0;

    printf ("\nEXECUTING TEST\n");
    fflush(stdout);

/// strlen ///
    size_t(*_strlen)(const char*);
    *(void**)(&_strlen) = dlsym(handle, "strlen");
    int strlen_passed = 0;

    if (_strlen("OUI") == 3)
        strlen_passed += 1;
    if (_strlen("O") == 1)
        strlen_passed += 1;
    if (_strlen("OUI et NON") == 10)
        strlen_passed += 1;
    if (_strlen("") == 0)
        strlen_passed += 1;

    printf("Strlen: %i/4\n", strlen_passed);
    fflush(stdout);

    passed += strlen_passed;

/// strchr ///
    void *(*_strchr)(const char *, int);
    *(void**)(&_strchr) = dlsym(handle, "strchr");
    int strchr_passed = 0;

    char *strchr1 = strdup("OUI");
    char *strchr2 = strdup("O");
    char *strchr3 = strdup("OUI et NON");
    char *strchr4 = strdup("OUI et NON");
    char *strchr5 = strdup("OUI et NON");

    if (strcmp(_strchr(strchr1, 'I'), "I") == 0);
        strchr_passed += 1;
    if (strcmp(_strchr(strchr2, 'O'), "O") == 0);
        strchr_passed += 1;
    if (strcmp(_strchr(strchr3, 'O'), "OUI et NON") == 0);
        strchr_passed += 1;
    if (strcmp(_strchr(strchr4, 'e'), "et NON") == 0);
        strchr_passed += 1;
    if (strcmp(_strchr(strchr5, 'Z'), "") == 0);
        strchr_passed += 1;

    free(strchr1);
    free(strchr2);
    free(strchr3);
    free(strchr4);
    free(strchr5);

    printf("Strchr: %i/5\n", strchr_passed);
    fflush(stdout);

    passed += strchr_passed;

/// strrchr ///
    void *(*_strrchr)(const char *, int);
    *(void**)(&_strrchr) = dlsym(handle, "strrchr");
    int strrchr_passed = 0;

    char *strrchr1 = strdup("OUI");
    char *strrchr2 = strdup("O");
    char *strrchr3 = strdup("OUI et NON");
    char *strrchr4 = strdup("OUI et NON");
    char *strrchr5 = strdup("OUI et NON");

    if (strcmp(_strrchr(strrchr1, 'I'), "I") == 0)
        strrchr_passed += 1;
    if (strcmp(_strrchr(strrchr2, 'O'), "O") == 0)
        strrchr_passed += 1;
    if (strcmp(_strrchr(strrchr3, 'O'), "ON") == 0)
        strrchr_passed += 1;
    if (strcmp(_strrchr(strrchr4, 'e'), "et NON") == 0)
        strrchr_passed += 1;
    if (_strrchr(strrchr5, 'Z') == NULL)
        strrchr_passed += 1;

    free(strrchr1);
    free(strrchr2);
    free(strrchr3);
    free(strrchr4);
    //free(strrchr5);

    printf("Strrchr: %i/5\n", strrchr_passed);
    fflush(stdout);

    passed += strrchr_passed;

/// Total ///

    printf("TOTAL: %i   |   PASSED: %i   |   FAILED: %i\n\n", total, passed, total - passed);
    fflush(stdout);
    return 0;
    //return 0;
}
