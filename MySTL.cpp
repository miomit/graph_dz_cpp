#include "MySTL.hpp"

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

