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
extern void *memset(void *pointer,int value, size_t count);
extern void *memcpy(void *dest, const void *src, size_t n);

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
    if (_strlen("AA") == 2)
        strlen_passed += 1;

    printf("Strlen: %i/5\n", strlen_passed);
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

    if (strcmp(_strchr(strchr1, 'I'), "I") == 0) {
        strchr_passed += 1;
        //printf("1: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strchr(strchr2, 'O'), "O") == 0) {
        strchr_passed += 1;
        //printf("2: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strchr(strchr3, 'O'), "OUI et NON") == 0) {
        strchr_passed += 1;
        //printf("3: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strchr(strchr4, 'e'), "et NON") == 0) {
        strchr_passed += 1;
        //printf("4: Oui ");
        //fflush(stdout);
    }
    if (_strchr(strchr5, 'Z') == NULL) {
        strchr_passed += 1;
        //printf("5: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strchr(strchr5, '\0'), "\0") == 0) {
        strchr_passed += 1;
        //printf("6: Oui ");
        //fflush(stdout);
    }
    if (_strchr("", 'a') == NULL) {
        strchr_passed += 1;
        //printf("7: Oui ");
        //fflush(stdout);
    }
    if (_strchr("\0", '\0') != NULL) {
        strchr_passed += 1;
        //printf("8: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strchr("\0", '\0'), "\0") == 0) {
        strchr_passed += 1;
        //printf("9: Oui ");
        //fflush(stdout);
    }
    if (strcmp(strchr("ABCD", '\0'), "\0") == 0) {
        strchr_passed += 1;
        //printf("10: Oui ");
        //fflush(stdout); 
    }

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

    if (strcmp(_strrchr(strrchr1, 'I'), "I") == 0) {
        strrchr_passed += 1;
        //printf("1: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strrchr(strrchr2, 'O'), "O") == 0) {
        strrchr_passed += 1;
        //printf("2: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strrchr(strrchr3, 'O'), "ON") == 0) {
        strrchr_passed += 1;
        //printf("3: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strrchr(strrchr4, 'e'), "et NON") == 0) {
        strrchr_passed += 1;
        //printf("4: Oui ");
        //fflush(stdout);
    }
    if (_strrchr(strrchr5, 'Z') == NULL) {
        strrchr_passed += 1;
        //printf("5: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strrchr(strrchr5, '\0'), "\0") == 0) {
        strrchr_passed += 1;
        //printf("6: Oui ");
        //fflush(stdout);
    }
    if (_strrchr("", 'a') == NULL) {
        strrchr_passed += 1;
        //printf("7: Oui ");
        //fflush(stdout);
    }
    if (_strrchr("\0", '\0') != NULL) {
        strrchr_passed += 1;
        //printf("8: Oui ");
        //fflush(stdout);
    }
    if (strcmp(_strrchr("\0", '\0'), "\0") == 0) {
        strrchr_passed += 1;
        //printf("9: Oui ");
        //fflush(stdout);
    }
    if (strcmp(strrchr("ABCD", '\0'), "\0") == 0) {
        strrchr_passed += 1;
        //printf("10: Oui ");
        //fflush(stdout); 
    }

    free(strrchr1);
    free(strrchr2);
    free(strrchr3);
    free(strrchr4);
    free(strrchr5);

    printf("Strrchr: %i/10\n", strrchr_passed);
    fflush(stdout);

    return strrchr_passed;
}

int memset_fonction(void *handle)
{
    void *(*_memset)(void *, int, size_t);
    *(void**)(&_memset) = dlsym(handle, "memset");
    int memset_passed = 0;

    char *strmemset1 = strdup("AAAAAA");
    _memset(strmemset1, 'B', 9);
    if (strcmp(strmemset1, "BBBBBBBBB") == 0) {
        memset_passed += 1;
    }
    _memset(strmemset1, 'C', 1);
    if (strcmp(strmemset1, "CBBBBBBBB") == 0) {
        memset_passed += 1;
    }
    _memset(strmemset1, 'D', 3);
    if (strcmp(strmemset1, "DDDBBBBBB") == 0) {
        memset_passed += 1;
    }
    _memset(strmemset1, 'E', 0);
    if (strcmp(strmemset1, "DDDBBBBBB") == 0) {
        memset_passed += 1;
    }
    _memset(strmemset1, 'F', 6);
    if (strcmp(strmemset1, "FFFFFFBBB") == 0) {
        memset_passed += 1;
    }

    free(strmemset1);

    printf("Memset: %i/5\n", memset_passed);
    fflush(stdout);

    return memset_passed;
}

int memcpy_fonction(void *handle)
{
    void *(*_memcpy)(void *, void *, size_t);
    *(void**)(&_memcpy) = dlsym(handle, "memcpy");
    int memcpy_passed = 0;

    char *strmemcpy1 = strdup("ABCDEF");

    _memcpy(strmemcpy1, "GHIJKLMNO", 9);
        printf("| %s | %i\n", strmemcpy1, strcmp(strmemcpy1, "GHIJKLMNO"));
    if (strcmp(strmemcpy1, "GHIJKLMNO") == 0) {
        memcpy_passed += 1;
    }
    _memcpy(strmemcpy1, "QRST", 1);
        printf("| %s | %i\n", strmemcpy1, strcmp(strmemcpy1, "QHIJKLMNO"));
    if (strcmp(strmemcpy1, "QHIJKLMNO") == 0) {
        memcpy_passed += 1;
    }
    _memcpy(strmemcpy1, "WXYZ", 3);
        printf("| %s | %i\n", strmemcpy1, strcmp(strmemcpy1, "WXYJKLMNO"));
    if (strcmp(strmemcpy1, "WXYJKLMNO") == 0) {
        memcpy_passed += 1;
    }
    _memcpy(strmemcpy1, "0123456789", 0);
        printf("| %s | %i\n", strmemcpy1, strcmp(strmemcpy1, "WXYJKLMNO"));
    if (strcmp(strmemcpy1, "WXYJKLMNO") == 0) {
        memcpy_passed += 1;
    }
    _memcpy(strmemcpy1, "ABCDEFGHIJ", 10);
        printf("| %s | %i\n", strmemcpy1, strcmp(strmemcpy1, "ABCDEFGHIJ"));
    if (strcmp(strmemcpy1, "ABCDEFGHIJ") == 0) {
        memcpy_passed += 1;
    }

    free(strmemcpy1);

    char *strmemcpy2 = strdup("AAAABBAAAAAAAAAAAAAAAAA");

    printf("%s", _memcpy(&strmemcpy2[3], &strmemcpy2[5], 2));
        printf("| %s | %i\n", strmemcpy2, strcmp(strmemcpy2, "AAABABAAAAAAAAAAAAAAAAA"));
    if (strcmp(strmemcpy2, "AAABABAAAAAAAAAAAAAAAAA") == 0) {
        memcpy_passed += 1;
    }

    free(strmemcpy2);

    char *strmemcpy3 = NULL;
    char *strmemcpy4 = strdup("AAAA");

    printf("%s", _memcpy(strmemcpy3, strmemcpy4, 0));
        printf("| %s |\n", strmemcpy3);
    if (strmemcpy3 == 0) {
        memcpy_passed += 1;
    }

    free(strmemcpy3);
    free(strmemcpy4);

    char *strmemcpy5 = strdup("AAAA");
    char *strmemcpy6 = NULL;

    printf("%s", _memcpy(strmemcpy5, strmemcpy6, 0));
        printf("| %s |\n", strmemcpy3);
    if (strmemcpy3 == 0) {
        memcpy_passed += 1;
    }

    free(strmemcpy5);
    free(strmemcpy6);

    char *strmemcpy7 = strdup("AAAABBAAAAAAAAAAAAAAAAA");

    printf("| %s |", _memcpy(&strmemcpy7[2], &strmemcpy7[4], 2));
        printf("| %s | %i\n", strmemcpy7, strcmp(strmemcpy7, "AABBBBAAAAAAAAAAAAAAAAA"));
    if (strcmp(strmemcpy7, "AABBBBAAAAAAAAAAAAAAAAA") == 0) {
        memcpy_passed += 1;
    }

    free(strmemcpy7);

    char *strmemcpy8 = strdup("AAAA");
    char *strmemcpy9 = NULL;

    printf("%s", _memcpy(strmemcpy8, strmemcpy9, 0));
        printf("| %s |\n", strmemcpy8);
    if (strmemcpy3 == 0) {
        memcpy_passed += 1;
    }

    free(strmemcpy5);
    free(strmemcpy6);

    printf("Memcpy: %i/10\n", memcpy_passed);
    fflush(stdout);

    return memcpy_passed;
}

int strcmp_fonction(void *handle)
{
    int (*_strcmp)(char *, char *);
    *(void **)(&_strcmp) = dlsym(handle, "strcmp");
    int strcmp_passed = 0;

    if (_strcmp("AAA", "AAA") == 0) {
        strcmp_passed += 1;
    }
    if (_strcmp("", "ui") == -1) {
        strcmp_passed += 1;
    }
    if (_strcmp("dfrety", "ui") == -1) {
        strcmp_passed += 1;
    }
    if (_strcmp("AAAAAA", "a") == -1) {
        strcmp_passed += 1;
    }
    if (_strcmp("abe", "abc") == 1) {
        strcmp_passed += 1;
    }
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
    int (*_strncmp)(char *, char *, size_t);
    *(void **)(&_strncmp) = dlsym(handle, "strncmp");
    int strncmp_passed = 0;

    if (_strncmp("AAA", "AAAB", 3) == 0) {
        strncmp_passed += 1;
    }
    if (_strncmp("", "ui", 0) == 0) {
        strncmp_passed += 1;
    }
    if (_strncmp("dfrety", "ui", 2) == -17) {
        strncmp_passed += 1;
    }
    if (_strncmp("AAAAAAa", "a", 5) == -32) {
        strncmp_passed += 1;
    }
    if (_strncmp("abe", "abc", 3) == 2) {
        strncmp_passed += 1;
    }
    printf("Strncmp: %i/5\n", strncmp_passed);
    fflush(stdout);

    return strncmp_passed;
}

int strcasecmp_fonction(void *handle)
{
    int (*_strcasecmp)(char *, char *);
    *(void **)(&_strcasecmp) = dlsym(handle, "strcasecmp");
    int strcasecmp_passed = 0;

        // printf("%i\n", _strcasecmp("AAA", "AAAB"));
        // fflush(stdout);
    if (_strcasecmp("AAA", "AAAB") == -98) {
        strcasecmp_passed += 1;
    }
        // printf("%i\n", _strcasecmp("", "ui"));
        // fflush(stdout);
    if (_strcasecmp("", "ui") == -117) {
        strcasecmp_passed += 1;
    }
        // printf("%i\n", _strcasecmp("dfrety", "DFRETY"));
        // fflush(stdout);
    if (_strcasecmp("dfrety", "DFRETY") == 0) {
        strcasecmp_passed += 1;
    }
        // printf("%i\n", _strcasecmp("AAAAAAa", "aa"));
        // fflush(stdout);
    if (_strcasecmp("AAAAAAa", "a") == 97) {
        strcasecmp_passed += 1;
    }
        // printf("%i\n", _strcasecmp("abe", "abc"));
        // fflush(stdout);
    if (_strcasecmp("abe", "abc") == 2) {
        strcasecmp_passed += 1;
    }

    printf("Strcasecmp: %i/5\n", strcasecmp_passed);
    fflush(stdout);

    return strcasecmp_passed;
}

int strstr_fonction(void *handle)
{
    char  *(*_strstr)(char *, char *);
    *(void **)(&_strstr) = dlsym(handle, "strstr");
    int strstr_passed = 0;

    //char *str = strdup ("Oui et Non");
    printf("| %s |\n", _strstr("", ""));
    if (strcmp(_strstr("lihilhadfpjom", "adf"), "adfpjom") == 0)
        strstr_passed += 1;
    if (_strstr("", "adf") == NULL)
        strstr_passed += 1;
    if (_strstr("", "adf\0") == NULL)
        strstr_passed += 1;
    if (_strstr("", "ad") == NULL)
        strstr_passed += 1;
    if (_strstr("ui", "adf") == NULL)
        strstr_passed += 1;

    printf("Strstr: %i/5\n", strstr_passed);
    fflush(stdout);

    return strstr_passed;
}

int strpbrk_fonction(void *handle)
{
    char* (*_strpbrk)(char *, char *);
    *(void **)(&_strpbrk) = dlsym(handle, "strpbrk");
    int strpbrk_passed = 0;

    char *str = strdup ("Oui et Non et");
    printf("| %s |\n", _strpbrk(str, "wzt"));

    printf("Strpbrk: %i/5\n", strpbrk_passed);
    fflush(stdout);

    return strpbrk_passed;
}

int strcspn_fonction(void *handle)
{
    size_t (*_strcspn)(char *, char *);
    *(void **)(&_strcspn) = dlsym(handle, "strcspn");
    int  strcspn_passed = 0;

    if (_strcspn("OUI", "OUI") == 0) {
        strcspn_passed += 1;
        //printf("1 ");
    }
    if (_strcspn("O", "U") == 1) {
        strcspn_passed += 1;
        //printf("2 ");
    }
    if (_strcspn("OUI et NON", "OUIe") == 0) {
        strcspn_passed += 1;
        //printf("3 ");
    }
    if (_strcspn("", "A") == 0) {
        strcspn_passed += 1;
        //printf("4 ");
    }
    if (_strcspn("AA", "") == 2) {
        strcspn_passed += 1;
        //printf("5 ");
    }
    if (_strcspn("frgtrynfvvreg", "fdz") == 0) {
        strcspn_passed += 1;
        //printf("6 ");
    }
    if (_strcspn("frgtrynfvvreg", "ayn") == 5) {
        strcspn_passed += 1;
        //printf("7 ");
    }
    if (_strcspn("efgrthyjhgzq0", "am0") == 12) {
        strcspn_passed += 1;
        //printf("8 ");
    }
    if (_strcspn("ui", "ad\0") == 2) {
        strcspn_passed += 1;
        //printf("9 ");
    }
    if (_strcspn("frgtrynfvvreg", "am") == 13) {
        strcspn_passed += 1;
        //printf("10 ");
    }

    printf("Strcspn: %i/10\n",  strcspn_passed);
    fflush(stdout);

    return  strcspn_passed;
}

int main()
{

    void *handle;
    handle = dlopen("./libmy.so", RTLD_LAZY);

    int total = 70;
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
