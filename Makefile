CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror
EXE = aqualand
FILES = src/*.cpp

.PHONY: all clean

$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ -lsimlib

clean: 
	rm -f $(EXE)