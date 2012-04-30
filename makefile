# Variaveis

CC = gcc
CFLAGS = -Wall -ansi -pedantic

COMMON_INTEREST = common_interest

# Regras
all: clean ${COMMON_INTEREST} cleanobj

${COMMON_INTEREST}.o: ${COMMON_INTEREST}.h

clean:
	rm -f *.o ${COMMON_INTEREST}
