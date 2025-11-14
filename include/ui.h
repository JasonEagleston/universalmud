#ifndef UNIVERSAL_MUD_UI
#define UNIVERSAL_MUD_UI


enum ElementType {
	WINDOW = 0,
	LINE_EDIT = 1,
	BUTTON = 2,
}

typedef struct {
	short element_type;
	void* rawdata;
	Vec2 pos;
	Vec2 bounds;
} UIElement;


#endif
