CC = gcc
CFLAGS = -I$(HDIR)
CCFLAGS = -Wall -ansi -pedantic

ODIR = obj
HDIR = ../hfiles

PROG=main

_DEPS = common_interest.h serialization.h
DEPS = $(patsubst %, $(HDIR)/%, $(_DEPS))

_OBJ = main.o common_interest.o serialization.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c $(CCFLAGS) -o $@ $< $(CFLAGS)

$(PROG): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(PROG) $(ODIR)/*.o *~ core 
