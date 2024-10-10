PROGS = t1
CC = gcc
CFLAGS = -Wall -g
objects = main.o pilha.o fila.o grafo.o aux.o

t1: $(objects)
	$(CC) $(CFLAGS) $(objects) -o $(PROGS)

main.o: main.c ./Fila/libfila.h ./Pilha/libpilha.h ./Grafo/listaAdj.h ./Pilha/aux.h
	$(CC) $(CFLAGS) -c main.c

fila.o: ./Fila/libfila.c ./Fila/libfila.h
	$(CC) $(CFLAGS) -c ./Fila/libfila.c -o fila.o

pilha.o: ./Pilha/libpilha.c ./Pilha/libpilha.h
	$(CC) $(CFLAGS) -c ./Pilha/libpilha.c -o pilha.o

grafo.o: ./Grafo/listaAdj.c ./Grafo/listaAdj.h
	$(CC) $(CFLAGS) -c ./Grafo/listaAdj.c -o grafo.o

aux.o: ./Pilha/aux.c ./Pilha/aux.h
	$(CC) $(CFLAGS) -c ./Pilha/aux.c -o aux.o

clean:
	-rm -f *~ *.o

purge: clean
	-rm -f $(PROGS)