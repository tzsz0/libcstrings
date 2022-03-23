#pragma once
#include<stdlib.h>

enum cstring_errno_t
{
    CSTRING_VALID,
    CSTRING_INVALID,
    CSTRING_OUT_OF_MEMORY,
    CSTRING_NOT_FOUND,
    CSTRING_SIZET_TOO_SMALL,
    CSTRING_NULL,
};

struct cstring
{
    enum cstring_errno_t valid;
    size_t size;

    /* actual buffer size should always be size+1
     * size refers to the string length _inside_
     * the buffer */
    char * buffer;
};

struct cstring_builder
{
    enum cstring_errno_t valid;
    /* TODO */
};


typedef struct cstring cstring_t;
typedef struct cstring_builder cstring_builder_t;



/*
 * TODO: add func decl here
 *
 * */

