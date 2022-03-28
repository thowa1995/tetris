CC = gcc
CFLAGS = -Wall
LDFLAGS = -lncurses
TARGET = tetris
OBJFILES = main.o board.o pieces.o

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~

