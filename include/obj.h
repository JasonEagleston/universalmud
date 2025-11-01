#ifndef UNIVERSAL_MUD_OBJ
#define UNIVERSAL_MUD_OBJ

#include "map.h"
#include "vec2.h"

typedef struct {
	void* rawdata;
	uint32_t id;
	Vec2f pos;
} Obj;

Obj new_obj(GameState*);

void set_pos(GameState*, Obj*, Vec2f);
void set_pos_tile(Obj*, Tile*);
Vec2f get_pos(Obj*);

#endif
