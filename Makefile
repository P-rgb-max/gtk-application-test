CC=gcc

SRC=main.c
OBJ=libs.o
BIN=gtkapp
INSTALL=/usr/bin

.PHONY: all object binary clean install distclean delete

all: binary clean

object: $(OBJ)
$(OBJ): $(SRC)
	$(CC) -o $@ $^ `pkg-config --cflags --libs gtk+-2.0`

binary: $(BIN)
$(BIN): $(SRC)
	$(CC) -o $@ $^ `pkg-config --cflags --libs gtk+-2.0`

clean:
	rm -rf $(OBJ)

install:
	sudo cp $(BIN) $(/usr/bin)/$(BIN)
	make distclean

distclean:
	rm -rf $(BIN)

delete:
	sudo rm -rf $(/usr/bin)/$(BIN)
