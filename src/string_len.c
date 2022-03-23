#include<cstrings.h>


size_t
string_len(cstring_t const target)
{
    if(target.valid == CSTRING_VALID)
        return target.size;
    else
        return 0;
}


