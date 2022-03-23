#include<cstrings.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>


cstring_t
string_cat(cstring_t fst, cstring_t snd)
{
    if(fst.valid != CSTRING_VALID)
        return fst;
    else if(snd.valid != CSTRING_VALID)
        return snd;

    if(fst.size == 0 && snd.size == 0) {
        /* TODO this needs special treatment
         * or does it?
         * the +1 might save us? */
    }

    if(fst.size > SIZE_MAX - snd.size) {
        /* check if fst.size + snd.size > SIZE_T
         * without actually producing an overflow */
        return (cstring_t) { .valid = CSTRING_SIZET_TOO_SMALL };
    }

    /* TODO BUG, technically the +1 could case an overflow which is not
     * detected by the check above. should probably adjust it */
    char * new_buffer = calloc(fst.size + snd.size + 1 /* \0 term. */, sizeof *new_buffer);

    if(new_buffer == NULL) {
        free(fst.buffer);
        free(snd.buffer);
        return (cstring_t) { .valid = CSTRING_OUT_OF_MEMORY };
    }

    cstring_t new_str = {
        .valid = CSTRING_VALID,
        .size = fst.size + snd.size,
        .buffer = new_buffer
    };

    memcpy(new_str.buffer, fst.buffer, fst.size);
    memcpy(new_str.buffer+fst.size, snd.buffer, snd.size);
    new_str.buffer[new_str.size] = '\0'; /* just to be sure, should not be req. */



    /* TODO CLEANUP!!! */
FREE_AND_RETURN:
    free(fst.buffer);
    free(snd.buffer);
    return new_str;
}

