CPPFLAGS = # -DGENERATE
CFLAGS   = -g -ansi -pedantic -Wextra -Wall ${CPPFLAGS}
LDFLAGS  =

SRC = hello.c
OBJ = ${SRC:.c=.o}

all: options hello

options:
	@echo hello build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

hello: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f hello ${OBJ}

.PHONY: all options clean
