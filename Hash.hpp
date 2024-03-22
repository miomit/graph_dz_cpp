namespace hash 
{
    unsigned int str_to_hash(const char* str)
    {
        unsigned int hash = 0;
        while (*str) hash += *(++str);
        return hash;
    }
}