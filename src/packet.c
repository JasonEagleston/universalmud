#include "packet.h"

// LE/BE?

void free_packet(Packet* p) {
	free(p.data);
}

Packet packet(size_t len) {
	Packet p;
	p.len = len;
	p.data = vec(sizeof(char), len);
	p.timestamp = now();
	return p;
}

void packet_copy_data(Packet* p, void* data, size_t len) {

}
