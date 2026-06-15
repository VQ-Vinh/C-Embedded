CC = gcc
CFLAGS = -Wall -Wextra

FORCE:

%: %.c FORCE
	$(CC) $(CFLAGS) "$<" -o "$@.exe"
	"./$@.exe"
	@echo

.PHONY: clean

clean:
	del /s /q *.exe 2>nul
