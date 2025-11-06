#ifndef YUKEN_VEC2
#define YUKEN_VEC2

enum VecType {
	int_vec = 0b00000001;
	float_vec = 0b00000010;
	double_vec = 0b00000100;
}

typedef struct {
	uint8_t type;
	int x;
	int y;
} Vec2;

typedef struct {
	uint8_t type;
	float x;
	float y;
} Vec2f;

typedef struct {
	double x;
	double y;
} Vec2d;

union PositionVec {
	Vec2 ivec;
	Vec2f fvec;
	Vec2d dvec;
};

Vec2 new_vec2(int x, int y) {
	Vec2 v;
	v.type = int_vec;
	v.x = x;
	v.y = y;
	return v;
}

Vec2f new_vec2f(float x, float y) {
	Vec2f v;
	v.type = float_vec;
v.x = x;
	v.y = y;
	return v;
}

Vec2d new_vec2d(double x, double y) {
	Vec2d v;
	v.type = double_vec;
	v.x = x;
	v.y = y;
	return v;
}

PositionVec add_vec(void* a, void* b) {
	PositionVec new_vec;

	if (a->type != b->type) return ERR_MISMATCHED_TYPE;

	new_vec.type = a->type;
	switch (new_vec.type) {
		case int_vec:
			new_vec.ivec = new_vec2(a->x + b->x, a->y + b->y);
			break;
		case float_vec:
			new_vec.fvec = new_vec2f(a->x + b->x, a->y + b->y);
			break;
		case double_vec:
			new_vec.dvec = new_vec2d(a->x + b->x, a->y + b->y);
	}

	return new_vec;
}

void flip_vec(void* a) {
	switch (a->type) {
		case int_vec:
			Vec2 v = *a;
			v.x = -v.x;
			v.y = -v.y;
			break;
		case float_vec:
			Vec2f v = *a;
			v.x = -v.x;
			v.y = -v.y;
			break;
		case double_vec:
			Vec2d v = *a;
			v.x = -v.x;
			v.y = -v.y;
	}
}

PositionVec sub_vec(void* a, void* b) {
	return add_vec(a, flip_vec(b));
}

#endif
