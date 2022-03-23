#include<cstrings.h>
#include<string.h>
#include<safe_lib.h>

static int
min_size_t(size_t a, size_t b)
{
    return a < b ? a : b;
}

int
string_cmp(cstring_t fst, cstring_t snd)
{
    //int ret = strcmp(fst.buffer, snd.buffer);
    int ret = 0;
    strcmp_s(fst.buffer, min_size_t(fst.size, snd.size), snd.buffer, &ret);

    free(fst.buffer);
    free(snd.buffer);
    return ret;
};

