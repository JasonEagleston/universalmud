CC = clang
CFLAGS = -Iinclude -O0 -I/usr/local/include
LDFLAGS = -lluajit-5.1 -lraylib

OBJ = map.o obj.o packet.o
CLIENT_OBJ = client.o
SERVER_OBJ = main.o 

%.o: src/%.c
	mkdir -p obj
	$(CC) -c -o obj/$@ $< $(CFLAGS)
client: $(OBJ) $(CLIENT_OBJ)
	mkdir -p bin
	$(CC) -o bin/$^ $(CFLAGS) $(LDFLAGS)
server: $(OBJ) $(SERVER_OBJ)
	mkdir -p bin
	$(CC) -o bin/$^ $(CFLAGS) $(LDFLAGS)
.PHONY: clean all

clean:
	rm -f obj/*.o bin/*

all: client server
