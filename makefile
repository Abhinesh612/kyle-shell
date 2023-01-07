CC=gcc
CFLAG=-g -Wall -Wextra
EXEC=main

SOURCES=$(wildcard ./scr/*.c)
OBJECTS=$(SOURCES:.c=.o)

$(EXEC) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o : %.c
	$(CC) -c $(CFLAG) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
