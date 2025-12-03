CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror -g
EXE = aqualand
FILES = src/*.cpp


$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ -lsimlib

all: clean $(EXE)

run: $(EXE)
	./$(EXE) $(ARGS)

clean: 
	rm -f $(EXE)

.PHONY: clean all run