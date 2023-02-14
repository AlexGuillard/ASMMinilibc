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
void *memset(void *pointer,int value,size_t count);

int strlen_fonction(void *handle)
{
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

    return strlen_passed;
}

int strchr_fonction(void *handle)
{
    char *(*_strchr)(const char *, int);
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
    if (_strchr(strchr5, 'Z') == NULL);
        strchr_passed += 1;
    if (_strchr(strchr5, 0) == NULL);
        strchr_passed += 1;
    if (_strchr("", 'a') == NULL);
        strchr_passed += 1;
    if (_strchr("", 0) == NULL);
        strchr_passed += 1;
    if ((*_strchr)("\0", '\0') == strchr("\0", '\0'));
        strchr_passed += 1;
    if ((*_strchr)("ABCD", '\0') == NULL);
        strchr_passed += 1;

    free(strchr1);
    free(strchr2);
    free(strchr3);
    free(strchr4);
    free(strchr5);

    printf("Strchr: %i/10\n", strchr_passed);
    fflush(stdout);

    return strchr_passed;
}

int strrchr_fonction(void *handle)
{
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
    free(strrchr5);

    printf("Strrchr: %i/5\n", strrchr_passed);
    fflush(stdout);

    return strrchr_passed;
}

int memset_fonction(void *handle)
{
    void *(*_memset)(void *, int, size_t);
    *(void**)(&_memset) = dlsym(handle, "memset");
    int memset_passed = 0;

    char *strmemset1 = strdup("AAAAAA");
    (*_memset)(strmemset1, 'B', 3);
    printf("%s\n", strmemset1);
    //if (strcmp(_memset(strmemset1, )))
    printf("Memset: %i/5\n", memset_passed);
    fflush(stdout);

    return memset_passed;
}

int memcpy_fonction(void *handle)
{
    int memcpy_passed = 0;

    printf("Memcpy: %i/5\n", memcpy_passed);
    fflush(stdout);

    return memcpy_passed;
}

int strcmp_fonction(void *handle)
{
    int strcmp_passed = 0;

    printf("Strcmp: %i/5\n", strcmp_passed);
    fflush(stdout);

    return strcmp_passed;
}

int memmove_fonction(void *handle)
{
    int memmove_passed = 0;

    printf("Memmove: %i/5\n", memmove_passed);
    fflush(stdout);

    return memmove_passed;
}

int strncmp_fonction(void *handle)
{
    int strncmp_passed = 0;

    printf("Strncmp: %i/5\n", strncmp_passed);
    fflush(stdout);

    return strncmp_passed;
}

int strcasecmp_fonction(void *handle)
{
    int strcasecmp_passed = 0;

    printf("Strcasecmp: %i/5\n", strcasecmp_passed);
    fflush(stdout);

    return strcasecmp_passed;
}

int strstr_fonction(void *handle)
{
    int strstr_passed = 0;

    printf("Strstr: %i/5\n", strstr_passed);
    fflush(stdout);

    return strstr_passed;
}

int strpbrk_fonction(void *handle)
{
    int strpbrk_passed = 0;

    printf("Strpbrk: %i/5\n", strpbrk_passed);
    fflush(stdout);

    return strpbrk_passed;
}

int strcspn_fonction(void *handle)
{
    int  strcspn_passed = 0;

    printf("Strcspn: %i/5\n",  strcspn_passed);
    fflush(stdout);

    return  strcspn_passed;
}

int main()
{

    void *handle;
    handle = dlopen("./libmy.so", RTLD_LAZY);

    int total = 19;
    int passed = 0;
    int failed = 0;

    printf ("\nEXECUTING TEST\n");
    fflush(stdout);

/// strlen ///
    passed += strlen_fonction(handle);

/// strchr ///
    passed += strchr_fonction(handle);

/// strrchr ///
    passed += strrchr_fonction(handle);

/// memset ///
    passed += memset_fonction(handle);

/// memcpy ///
    passed += memcpy_fonction(handle);

/// strcmp ///
    passed += strcmp_fonction(handle);

/// memmove ///
    passed += memmove_fonction(handle);

/// strncmp ///
    passed += strncmp_fonction(handle);

/// strcasecmp ///
    passed += strcasecmp_fonction(handle);

/// strstr ///
    passed += strstr_fonction(handle);

/// strpbrk ///
    passed += strpbrk_fonction(handle);

/// strcspn ///
    passed += strcspn_fonction(handle);

/// Total ///

    printf("TOTAL: %i   |   PASSED: %i   |   FAILED: %i\n\n", total, passed, total - passed);
    fflush(stdout);
    return 0;
}