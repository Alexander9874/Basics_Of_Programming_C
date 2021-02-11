#include <stdio.h>

int main() {
    char fname[] = "/etc/passwd";
    FILE *fd  = fopen(fname, "r");
    if (!fd) {
	fprintf(stderr, "Can't open file \"%s\"\n", fname);
	return 1;
    }
    fseek(fd, 0, SEEK_END);
    long size = ftell(fd);
    printf("File \"%s\" contains %ld bytes of data\n", fname, size);
    fclose(fd);
    return 0;
}
