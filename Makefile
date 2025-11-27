CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror
EXE = aqualand
FILES = src/*.cpp


$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ -lsimlib

all: clean $(EXE)

clean: 
	rm -f $(EXE)

.PHONY: clean all run