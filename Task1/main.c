#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc <= 2) {
        printf("Usage: %d parameter is not enough\n", argc);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "a+");
    while (fp) {
        fread(stdout, sizeof(int), 8, fp);
    }
    
    return 0;
}