#include <stdio.h>

int main() {
    char fname[] = "file.dat";
    char inbuf[] = "data for testing";
    char outbuf[20];
    FILE *fd = fopen(fname, "w+b");
    if (fd == NULL) {
        fprintf(stderr, "Can't open file %s\n", fname);
        return 1;
    }
    printf("Size of data: %d\n", sizeof(inbuf));
    fwrite(inbuf, 1, sizeof(inbuf), fd);
    fseek(fd, 20, SEEK_CUR);
    fwrite(inbuf, 1, sizeof(inbuf), fd);
    fseek(fd, 0, SEEK_END);
    long size = ftell(fd);
    printf("File %s has %ld bytes\n", fname, size);
    rewind(fd);
    printf("Reading from file\n");
    while ((size = fread(outbuf, 1, sizeof(outbuf), fd)) > 0) {
        fwrite(outbuf, 1, size, stdout);
    }
    printf("\n");
    fclose(fd);
    return 0;
}
