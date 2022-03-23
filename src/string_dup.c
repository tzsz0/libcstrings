#include<cstrings.h>
#include<string.h>



cstring_t
string_dup(cstring_t const src)
{
    if(src.valid != CSTRING_VALID)
        return (cstring_t) { .valid = src.valid };

    cstring_t new = {
        .valid = CSTRING_VALID,
        .size = src.size,
        .buffer = calloc(src.size, sizeof *src.buffer)
    };

    if(new.buffer != NULL) {
        memcpy(new.buffer, src.buffer, new.size);
        return new;
    } else {
        return (cstring_t) { .valid = CSTRING_OUT_OF_MEMORY };
    }

}

