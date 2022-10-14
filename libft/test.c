#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long *p;

    p = malloc(0);
    printf("%p", p);
    exit(0);
}