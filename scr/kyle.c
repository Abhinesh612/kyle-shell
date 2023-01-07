#include "kyle.h"
#include "errhandle.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/wait.h>

/* READLINE FROM STDIN */ 
char *readline(void) {
	char *lineptr = NULL;
	size_t buffer = 0;

    ssize_t n =  getline(&lineptr, &buffer, stdin);
	if ( n == -1) {
		if (feof(stdin))
			exit(0);
		else
			err_fsys("getline");	
	}
	return lineptr;
}

/* CREATING TOKENS FROM THE LINE STDIN TO GET ARGUMENT TO EXCECUTE AS PROCESS */
/* ON THE TERMINAL FROM EXEC */ 
char **parser(char *line) {
	static_assert(BUFFER_TOKEN > 0, "invalid BUFFER_TOKEN");
	size_t buffer = BUFFER_TOKEN;
	char **tokenList = (char**)calloc(buffer, sizeof(char*));
	assert(tokenList != NULL && "couldn't allocate memory");
	
	/* PARSING TOKEN FROM LINE STDIN */
	char *token = strtok(line, DELIMIT);
	
	/* CREATING DYNAMIC ALLOCATED STACK TO STORE TOKEN */
	size_t counter = 0;
	while(token != NULL) {
		tokenList[counter] = token;
		counter += 1;

		if ( counter == buffer) {
			buffer += BUFFER_TOKEN;
			char **temp = (char**)realloc(tokenList, buffer*sizeof(char*));
			assert(temp != NULL && "couldn't re-allocate memory");

			tokenList = temp;
		}
		token = strtok(NULL, DELIMIT);
	}
	/* ADDING NULL TOKEN AT THE TOP OF STACK */ 
	tokenList[counter] = NULL;
	return tokenList;
}

int kyle(char **tokenList) {
	int status;
	pid_t wpid;

	/* CREATEING DUBLICATE PROCESS` */
	pid_t pid = fork();

	if (pid < 0) {
		err_sys("couldn't fork");	
	}
	// CHILD PROCESS
	else if (pid == 0) {
		int n = execvp(tokenList[0], tokenList); 
		if ( n == -1)
			err_sys("execvp failed");
	}
	// PARENT PROCESS
	else{
		do {
		wpid = waitpid(pid, &status, WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status)); // CHECKING SIGNAL STATUS
		if (wpid == -1)
			err_sys("ERROR in waitpid");
	}
	return 1;
}

