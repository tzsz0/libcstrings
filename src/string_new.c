#include<cstrings.h>




cstring_t
string_empty()
{
    return (cstring_t) {
        .valid = CSTRING_VALID,
        .size = 0,
        .buffer = NULL
    };
}

