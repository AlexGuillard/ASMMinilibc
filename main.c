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

extern size_t strlen(const char *str);
extern char *strchr(const char *s, int c);

int main()
{

    void *handle;
    handle = dlopen("./libmy.so", RTLD_LAZY);

    int total = 9;
    int passed = 0;
    int failed = 0;

    printf ("\nEXECUTING TEST\n");
    fflush(stdout);

/// strlen ///
    size_t(*strlen)(const char*);
    *(void**)(&strlen) = dlsym(handle, "strlen");
    int strlen_passed = 0;

    if (strlen("OUI") == 3)
        strlen_passed += 1;
    if (strlen("O") == 1)
        strlen_passed += 1;
    if (strlen("OUI et NON") == 10)
        strlen_passed += 1;
    if (strlen("") == 0)
        strlen_passed += 1;

    printf("Strlen: %i/4\n", strlen_passed);
    fflush(stdout);

    passed += strlen_passed;

/// strchr ///
    char *(*strchr)(const char *, int);
    *(void**)(&strchr) = dlsym(handle, "strchr");
    int strchr_passed = 0;

    if (strchr("OUI", 'I') == "I");
        strchr_passed += 1;
    if (strchr("O", 'O') == "O");
        strchr_passed += 1;
    if (strchr("OUI et NON", 'O') == "OUI et NON");
        strchr_passed += 1;
    if (strchr("OUI et NON", 'e') == "et NON");
        strchr_passed += 1;
    if (strchr("OUI et NON", 'Z') == NULL);
        strchr_passed += 1;

    printf("Strchr: %i/5\n", strchr_passed);
    fflush(stdout);

    passed += strchr_passed;

/// Total ///

    printf("TOTAL: %i   |   PASSED: %i   |   FAILED: %i\n\n", total, passed, total - passed);
    fflush(stdout);
    return 0;
}
