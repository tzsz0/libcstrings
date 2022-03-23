#include<cstrings.h>
#include<string.h>



cstring_t
string_from_chars(char const * const chars)
{
    size_t len = strlen(chars);
    cstring_t new = {
        .valid = CSTRING_OUT_OF_MEMORY,
        .size = len,
        .buffer = calloc(len + 1, sizeof *new.buffer)
    };

    if(new.buffer != NULL) {
        new.valid = CSTRING_VALID;
        strcpy(new.buffer, chars);
    }

    return new;
}

