CC= clang
CFLAGS = -Iinclude 
LDFLAGS = -lluajit -lraylib

OBJ = map.o obj.o packet.o
CLIENT_OBJ = client.o
SERVER_OBJ = main.o 

%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
bin/client: $(OBJ) $(CLIENT_OBJ)
	$(CC) -o $^ $(CFLAGS) $(LDFLAGS)
bin/server: $(OBJ) $(SERVER_OBJ)
	$(CC) -o $^ $(CFLAGS) $(LDFLAGS)
.PHONY: clean all

clean:
	rm -f obj/* bin/*

all: client server
