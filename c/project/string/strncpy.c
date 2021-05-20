#include <stdio.h>

char *my_strncpy(char *dest, char *src, int count)
{
    char *p = dest;

    while (count-- && (*dest++ = *src++) != '\0');

    return p;
}

int main(int argc, char *argv[])
{
    char str1[16] = { '\0' };
    char *name = "cocojiang";
    
    my_strncpy(str1, name, 16);
    printf("%s\n", str1);

    return 0;
}
