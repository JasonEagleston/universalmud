#include "map.h"

Map create_map(int width, int height) {
	Map map;
	map.id = get_usable_id();
	map.width = width;
	map.height = height;
	map.tiles = malloc(sizeof(Tile) * width * height);
	return map;
}

Map* get_map(GameState* state, uint32_t map) {
	Map* retval = find_by_uint32_id(state->maps, map);
	return retval;
}

Tile* get_tile(GameState* state, uint32_t map, Vec2 pos) {
	Map* map = get_map(map);
	Tile* retval = map->tiles + ((pos.x - 1) + (pos.y - 1) * map->width);

	return retval;
}
