#include <unistd.h>
#include <stdio.h>

int main()
{
    int fdarr[2];
    int rslt = pipe(fdarr);

    printf("read end: %d\nwrite end: %d", fdarr[0], fdarr[1]);
    return 0;
}