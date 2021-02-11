#include <stdio.h>

const char *MSGS[] = {"0. Quit", "1. Blah-blah", "2. Blah-blah-blah"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
	puts(error);
	error = "You're wrong. Try again!";
	for (int i = 0; i < n; ++i) {
	    puts(msgs[i]);
	}
	puts("Make your choice: ");
	choice = getchar() - '0';
	while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}

int main() {
    int c = 0;
    do {
	c = dialog(MSGS, MSGS_SIZE);
	switch(c) {
	case 0:
	    break;
	case 1:
	    printf("***\nOption 1\n***\n");
	    break;
	case 2:
	    printf("***\nOption 2\n***\n");
	    break;
	}
    } while (c != 0);
    return 0;
}
