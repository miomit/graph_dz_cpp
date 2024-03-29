#include "MySTL.hpp"
#include <cstring>

int my_stl::str_to_hash(const char* str)
{
    int hash = str[0];
    while (*str) hash += *(++str);
    return hash;
}

int my_stl::two_str_to_hash(const char* str1, const char* str2)
{
    int hash1 = str_to_hash(str1);
    int hash2 = str_to_hash(str2);

    hash1 *= pow(10, count_num(hash2));

    return hash1 + hash2;
}

int my_stl::two_str_to_hash_sort(const char* str1, const char* str2)
{
    int hash1 = str_to_hash(str1);
    int hash2 = str_to_hash(str2);

    int hash = max(hash1, hash2);

    hash *= pow(10, count_num(min(hash1, hash2)));

    return hash + min(hash1, hash2);
}

int my_stl::count_num(int n)
{
    int count = 1;

    while (pow(10, count) <= abs(n)) count++;

    return count;
}

int my_stl::abs(int n)
{
    if (n < 0) return -n;
    else return n;
}

int my_stl::pow(int n, int exp)
{
    int res = 1;

    for (int i = 0; i < exp; i++) res *= n;

    return res;
}

int my_stl::max(int a, int b)
{
    return a >= b ? a : b;
}

int my_stl::min(int a, int b)
{
    return a <= b ? a : b;
}

char** my_stl::split(char* str, char delim, int* count)
{
    *count = 0;
    char* p = str;

    for (char* p = str; *p; p++)
    {
        if (*p == delim) (*count)++;
    }

    (*count)++;

    char** tokens = new char*[(*count) * sizeof(char*)];

    int token_index = 0;
    char* next_token1 = NULL;

    char* token = strtok_r(str, &delim, &next_token1);

    while (token != NULL)
    {
        tokens[token_index++] = token;
        token = strtok_r(NULL, &delim, &next_token1);
    }

    tokens[token_index] = NULL;

    return tokens;
}

