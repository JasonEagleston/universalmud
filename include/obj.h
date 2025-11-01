#ifndef UNIVERSAL_MUD_OBJ
#define UNIVERSAL_MUD_OBJ

#include "map.h"
#include "vec2.h"

typedef struct {
	void* rawdata;
	uint32_t id;
	uint32_t map;
	Vec2f pos;
} Obj;

Obj new_obj(GameState*);

void set_pos(GameState*, Obj*, Vec2f);
void set_pos_tile(Obj*, Tile*);
void set_map(Obj*, Map*);
Vec2f get_pos(Obj*);

#endif
