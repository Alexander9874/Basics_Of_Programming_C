#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rm_spaces1(const char *s) {
	int len = 0;
	int i = 0;
	char *res = calloc(strlen(s) + 1, sizeof(char));
	while (s[i] == ' ') { ++i; }
	while (s[i]) {
		int j = i;
		while (s[j] && s[j] != ' ') { ++j; }
		strncat(res, &s[i], j - i);
		len += j - i;
		i = j;
		while (s[j] == ' ') { ++j; }
		if (s[j]) {
			strncat(res, " ", 1);
			len++;
		}
		i = j;
	}
	res = realloc(res, len + 1);
	res[len] = '\0';
	return res;
}

char *rm_spaces2(const char *s) {
	int i = 0;
	char *res = calloc(strlen(s) + 1, sizeof(char));
	char *r = res;
	while (*s == ' ') { ++s; }
	while (*s) {
		const char *s1 = s;
		while (*s1 && *s1 != ' ') { ++s1; }
		memcpy(r, s, s1 - s);
		r += s1 - s;
		s = s1;
		while (*s1 == ' ') { ++s1; }
		if (*s1) {
			*r++ = ' ';
		}
		s = s1;
	}
	int len = r - res;
	res = realloc(res, len + 1);
	*(res + len) = '\0';
	return res;
}

int main() {
	const char *tests[] = {
		"Per aspera ad astra",
		"     Per aspera    ad     astra     ",
		"Perasperaadastra",
		"       ",
	};
	for (int i = 0; i < sizeof(tests) / sizeof(char *); ++i) {
		char *res = NULL;
		printf("***\n");
		printf("Input: \"%s\"\n", tests[i]);
		printf("Output 1: \"%s\"\n", res = rm_spaces1(tests[i]));
		free(res);
		printf("Output 2: \"%s\"\n", res = rm_spaces2(tests[i]));
		free(res);
		res = NULL;
	}
	return 0;
}
