#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %d parameter is not enough\n", argc);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "a+");
    char buf[20];
    fputs(buf, stdout);
    size_t num;
    while (num = fread(buf, sizeof(int), 8, fp)) {
        printf("%4d\n", num);
        fputs(buf, stdout);
    }
    
    return 0;
}