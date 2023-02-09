/*
** EPITECH PROJECT, 2023
** main test
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>

extern size_t strlen(const char *str);
extern char *strchr(const char *s, int c);

int main()
{
    int total = 9;
    int passed = 0;
    int failed = 0;

/// strlen ///
    int strlen_passed = 0;

    if (strlen("OUI") == 3)
        strlen_passed += 1;
    if (strlen("O") == 1)
        strlen_passed += 1;
    if (strlen("OUI et NON") == 10)
        strlen_passed += 1;
    if (strlen("") == 0)
        strlen_passed += 1;

    if (strlen_passed == 4)
        printf("Strlen: %i/4\n", strlen_passed);

    passed += strlen_passed;

/// strchr ///
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

    if (strchr_passed == 5)
        printf("Strchr: %i/5\n", strchr_passed);

    passed += strchr_passed;

/// Total ///

    printf("TOTAL: %i   |   PASSED: %i   |   FAILED: %i\n", total, passed, total - passed);
    return 0;
}
