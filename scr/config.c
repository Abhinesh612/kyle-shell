#include "config.h"

#include <stdio.h>

static inline void txtColor(char *);
static inline void bgColor(char *);

void printPrompt(const char *str) {
	bgColor(fgBlue);
	printf("%s", str);
	bgColor(Reset);
}

static inline void txtColor(char *str) {
	printf("%s", str);
}

static inline void bgColor(char *str) {
	printf("%s", str);
}
