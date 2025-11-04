#ifndef UNIVERSAL_MUD_PACKET
#define UNIVERSAL_MUD_PACKET

// eventually we can reuse some common movement packets rather than discarding and cloning but game dev til then

typedef struct {
	void* data;
	size_t len;
	uint64_t timestamp;
} Packet;

void free_packet(Packet*);
Packet* packet(size_t);

void packet_copy_data(Packet*, void*, size_t);


#endif
