#include "launch.h"
#include "kyle.h"

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

void runLoop(void) {
	int status;
	char *line;
	char **cmd;
	
	do {
		printf(PROMPT);
		line = readline();
		cmd = parser(line);
		status = kyle(cmd);
	}while(status);
}
