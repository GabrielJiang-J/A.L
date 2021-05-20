#include <stdio.h>
#include <string.h>

void *my_memset(void *s, int c, size_t count)
{
    char *sc = (char *)s;

    while(count--)
        *sc++ = (char)c;

    return s;
}

int main(int argc, char *argv[])
{
    int i = 0;
    char str1[16] = { '\0' };
    
    my_memset(str1, 0, 16);
    for (i = 0; i < 16; i++)
        printf("%c\n", str1[i]);

    return 0;
}
