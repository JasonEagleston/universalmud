#include <enet/enet.h>
#include <stdio.h>

#define DEBUG 1

struct GameState {
	Vec clients;
	Vec maps;
	Vec objects;
};

struct UniqueIDGenerator {

};

uint32_t get_available_id() {

}

void client_connect();
void client_disconnect();
void client_receive();

void init_game_state() {
	GameState.clients = vec(sizeof(Client), 64);
	GameState.maps = vec(sizeof(Map), 4);
	GameState.objects = vec(sizeof(Obj), 1024);
}

int main(int argc, char** argv) {

	if (DEBUG) printf("%d\n", argc);



	if (enet_initialize() != 0) {
		fprintf(stderr, "Error occurred initializing ENet.\n");
		return EXIT_FAILURE;
	}

	ENetAddress address;
	ENetHost* host;

	address.host = ENET_HOST_ANY;
	address.port = 5515;
	server = enet_host_create(&address, 64, 2, 0, 0);

	if (server == NULL) {
		fprintf(stderr, "Error occurred creating ENet server.\n");
		return EXIT_FAILURE;
	}

	bool quit = 0;

	ENetEvent event;

	init_game_state();

	while(!quit) {

		while(enet_host_service(server, &event, 0) > 0) {
			switch(event.type) {
				case ENET_EVENT_TYPE_RECEIVE:
					break;
				case ENET_EVENT_TYPE_CONNECT:
					break;
				case ENET_EVENT_TYPE_DISCONNECT:
					break;
			}
		}

		enet_host_flush(server);
		sleep_ms(20);
	}


	enet_host_destroy(server);
	enet_deinitialize();

	return 0;
}
