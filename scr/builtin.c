#include "builtin.h"
#include "errhandle.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


#define UNUSED
#define UNUSED_T(str) (void) str
#ifdef __GNUC__
#undef UNUSED
#undef UNUSED_T
#define UNUSED __attribute__((unused))
#define UNUSED_T(str) 
#endif

int kyle_exit(char **cmd UNUSED) {
	UNUSED_T(cmd);
	return 0;
}

int kyle_cd(char **cmd) {
	if (cmd[2] != NULL)
		fprintf(stderr, "invaild arguments\n");
	int n = chdir(cmd[1]);
	if (n == -1)
		nerr_fsys("invalid directory");
	return 1;
}

int kyle_kyle(char **cmd UNUSED) {
	UNUSED_T(cmd);
	printf("Kyle: The Holy shell\n----------------------------------------------------------------------\nMade by Abhiensh Sharma\n");
	return 1;
}
