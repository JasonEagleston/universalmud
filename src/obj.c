#include "obj.h"

Obj new_obj(GameState* state) {
	Obj obj;
	obj.id = get_id(state);
	obj.pos = new_vec2f(0, 0);
	return obj;
}

void set_pos(GameState* state, Obj* obj, Vec2f pos) { 
	obj.pos.x = pos.x;
	obj.pos.y = pos.y;
	update_map_tile(state, obj);
}

void set_pos_tile(Obj* obj, Map* map, Tile* tile) {
	if (obj->map == map->id) {

	}
}

Vec2f get_pos(Obj* obj) {

}
