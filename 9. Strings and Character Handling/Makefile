CC = gcc
CFLAGS = -Wall -Wextra

Makefile: ;

FORCE:
	@true

%: FORCE
	$(CC) $(CFLAGS) "$@.c" -o "$@.exe"
	"./$@.exe"
	@echo

%.c: FORCE
	$(CC) $(CFLAGS) "$@" -o "$(@:.c=).exe"
	"./$(@:.c=).exe"
	@echo

.PHONY: clean

clean:
	rm -f *.exe 2>nul
