#include "launch.h"
#include "kyle.h"

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

void runLoop(void) {
	int status = 1;
	char *line;
	char **cmd;
	
	while(status) {
		printPrompt(PROMPT);
		line = readline();
		cmd = parser(line);
		status = execute(cmd);

		free(line);
		line = NULL;
		free(cmd);
		cmd = NULL;
	};
}
