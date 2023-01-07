#include "errhandle.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void err_fsys_(const char *str, const char *file, int line) {
	fprintf(stderr, "%s, %d : %s : %s\n", file, line, str, strerror(errno));
	exit(1);
}


void err_sys_(const char *str, const char *file, int line) {
	fprintf(stderr, "%s, %d: %s\n", file, line, str);
	exit(1);
}

void nerr_fsys_(const char *str, const char *file, int line) {
	fprintf(stderr, "%s, %d : %s : %s\n", file, line, str, strerror(errno));
}
