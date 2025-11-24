CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror
EXE = ims-project
FILES = src/*.cpp

.PHONY: all

$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f $(EXE)