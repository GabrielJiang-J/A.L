#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t count)
{
    char *p = (char *)dest, *s = (char *)src;

    while (count--)
        *p++ = *s++;

    return dest;
}

int main(int argc, char *argv[])
{
    int i = 0;
    char str1[16] = "cocojiang";
    char str2[16] = { '\0' };
    
    my_memcpy(str2, str1, 16);

    printf("%s\n", str1);
    printf("%s\n", str2);

    return 0;
}
