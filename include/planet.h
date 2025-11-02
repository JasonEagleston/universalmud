// Planets, Stars in Space. 
#ifndef UNIVERSAL_MUD_PLANET
#define UNIVERSAL_MUD_PLANET
typedef struct {
	uint32_t id;
	void* rawdata;
	Obj obj;
	uint32_t map;
	Weight weight;
	Vec2f size;
} SpaceBody;
#endif
