#include<cstrings.h>



{

    cstring_t a;
    cstring_t b;
    cstring_t c;



    a = string_new();
    b = string_new();
    c = string_cat(a, b);

    b = string_dub(c);
    a = string_dub(c);



    string_del(c);
    c = string_from_chars("Hello");
    a = string_from_chars(" ");
    b = string_from_chars("World");
    cstring_t d = string_cat(c, string_cat(a, b));
    string_cmp(d, string_from_chars("Hello World"));




}










int main()
{


}



