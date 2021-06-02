# change application name here (executable output name)
TARGET=BD
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0 ` `mysql_config --cflags --libs`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic
OBJS= BD.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(GTKLIB) $(GTKLIB2) $(LDFLAGS)
 
BD.o:
	$(CC) -c $(CCFLAGS) BD.c $(GTKLIB) -o BD.o
clean:
	rm -f *.o $(TARGET)
.PHONY: install
	./BD	
run:
	./BD
# Proceso de copia de los ficheros al
# directorio destino
