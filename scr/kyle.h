#ifndef __KYLE_H
#define __KYLE_H

/* READING LINES FROM STDIN */
char *readline(void);


/* PASERING THE LINE FROM STDIN TO STORE AS TOKEN IN STACK */
#define BUFFER_TOKEN 64
#define DELIMIT " \r\n\t"
char **parser(char *line);

/* CREATING DUBLICATE PROCERSS ON THE TERMINAL */
int kyle(char **tokenList);

#endif // __KYLE_H
