#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[] = "lmfao";
    char str2[]="";

    printf("%lu", strlcpy(str2, str1, 0));
    exit(0);

}