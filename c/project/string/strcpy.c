#include <stdio.h>

char *my_strcpy(char *dest, char *src)
{
    char *p = dest;

    while((*dest++ = *src++) != '\0');

    return p;
}

int main(int argc, char *argv[])
{
    char str1[16] = { '\0' };
    char *name = "cocojiang";
    
    my_strcpy(str1, name);
    printf("%s\n", str1);

    return 0;
}
