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
	Tile* tiles;
	int width, height;
} Map;

Map create_map(int, int);
Map get_map(uint32_t);
Tile get_tile(uint32_t, Vec2);


#endif
