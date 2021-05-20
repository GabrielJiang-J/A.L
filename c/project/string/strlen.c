#include <stdio.h>

size_t my_strlen(const char *s)
{
    const char * sc = NULL;

    for (sc = s; *sc != '\0'; ++sc);

    return sc -s;
}

int main(int argc, char *argv[])
{
    printf("%d\n", my_strlen("cocojiang"));

    return 0;
}
