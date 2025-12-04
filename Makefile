CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror -g
EXE = aqualand
FILES = src/*.cpp
ARCHIVE = 04_xvcelaa00_xskovaj00.zip

$(EXE): $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ -lsimlib

all: clean $(EXE)

run: $(EXE)
	./$(EXE) $(ARGS)

pack:
	rm -f $(ARCHIVE)
	make clean
	zip -r $(ARCHIVE) src/ Makefile README.md study.pdf -x "src/.clang-format"

clean: 
	rm -f $(EXE)

.PHONY: clean all run