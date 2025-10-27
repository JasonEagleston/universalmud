#include "map.h"

Map* get_map(GameState* state, uint32_t map) {
	for (unsigned int i = 0; i < state->maps.len; i++) {
		Map* map = &((Map*)state->maps)[i];
		if map->id == map return map;
	}
	return NULL;
}

Tile get_tile(GameState* state, uint32_t map, Vec2 pos) {
	Map* map = get_map(map);
	Tile retval = map->tiles[(pos.x - 1) + (pos.y - 1) * map->width];

	return retval;
}
