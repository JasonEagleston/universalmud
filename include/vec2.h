#ifndef YUKEN_VEC2
#define YUKEN_VEC2

#include <stdint.h>

enum VecType {
	int_vec = 0b00000001,
	float_vec = 0b00000010,
	double_vec = 0b00000100,
};

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
	uint8_t type;
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

union PositionVec add_vec(void* a, void* b) {
	union PositionVec new_vec;

	if (*(uint8_t*)a != *(uint8_t*)b) return ERR_MISMATCHED_TYPE;




	switch (new_vec.type) {
		case int_vec:
			Vec2* ia, ib;
			ia = a;
			ib = b;
			new_vec.ivec = new_vec2(ia->x + ib->x, ia->y + ib->y);
			break;
		case float_vec:
			Vec2f* fa, fb;
			fa = a;
			fb = b;
			new_vec.fvec = new_vec2f(fa->x + fb->x, fa->y + fb->y);
			break;
		case double_vec:
			Vec2d* da, db;
			da = a;
			db = b;
			new_vec.dvec = new_vec2d(da->x + db->x, da->y + db->y);
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

union PositionVec sub_vec(void* a, void* b) {
	return add_vec(a, flip_vec(b));
}

#endif
