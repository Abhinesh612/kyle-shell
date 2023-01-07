#ifndef __CONFIG_H
#define __CONFIG_H

#define PROMPT "[Kyle]$ "

//balck background color

#define bgBlack "\e[40m"
#define bgRed "\e[41m"
#define bgGreen "\e[42m"
#define bgYellow "\e[43m"
#define bgBlue "\e[44m"
#define bgMagenta "\e[45m"
#define bgCyan "\e[46m"
#define bgWhite "\e[47m"

//bright background colours

#define bgbBlack "\e[40;1m"
#define bgbRed "\e[41;1m"
#define bgbGreen "\e[42;1m"
#define bgbYellow "\e[43;1m"
#define bgbBlue "\e[44;1m"
#define bgbMagenta "\e[45;1m"
#define bgbCyan "\e[46;1m"
#define bgbWhite "\e[47;1m"

// foreground light colours

#define fgBlack "\e[30m"
#define fgRed "\e[31m"
#define fgGreen "\e[32m"
#define fgYellow "\e[33m"
#define fgBlue "\e[34m"
#define fgMagenta "\e[35m"
#define fgCyan "\e[36m"
#define fgWhite "\e[37m"

//foreground bright colors

#define fgbBlack "\e[30;1m"
#define fgbRed "\e[31;1m"
#define fgbGreen "\e[32;1m"
#define fgbYellow "\e[33;1m"
#define fgbBlue "\e[34;1m"
#define fgbMagenta "\e[35;1m"
#define fgbCyan "\e[36;1m"
#define fgbWhite "\e[37;1m"

//reset foreground and background to normal colours

#define Reset "\e[0m"

void printPrompt(const char *str);

#endif //__CONFIG_H
