#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *file1, *file2;
    if(!(file1 = fopen("b.out","r+"))) {
        perror("open file1\n");
        exit(1);
    }
    if(!(file2 = fopen("dir2/file2","w+"))) {
        perror("open file2\n");
        exit(1);
    }

    char *s = (char*)malloc(100);
    fgets(s, 100, file1);
    fputs(s, stdout);

    fclose(file1);
    fclose(file2);
    return 0;
}
