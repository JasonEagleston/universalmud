#ifndef UNIVERSAL_MUD_MAP
#define UNIVERSAL_MUD_MAP

enum TILE_ID {
	GRASS = 1,
	WATER = 2,
	SAND = 3,
	DIRT = 4
}

typedef struct {
	uint16_t type;
	Vec contents;
} Tile;

typedef struct {
	uint32_t id;
	Tile* tiles;
	int width, height;
} Map;

Map create_map(int, int);
Map* get_map(uint32_t);
Tile* get_tile(uint32_t, Vec2);
void remove_obj_from_map(Map*, Obj*);
void add_obj_to_map(Map*, Obj*);


#endif
