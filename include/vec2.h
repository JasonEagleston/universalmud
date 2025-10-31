#ifndef YUKEN_VEC2
#define YUKEN_VEC2

typedef struct {
	int x;
	int y;
} Vec2;

typedef struct {
	float x;
	float y;
} Vec2f;

typedef struct {
	double x;
	double y;
} Vec2d;

Vec2 new_vec2(int x, int y) {
	Vec2 v;
	v.x = x;
	v.y = y;
	return v;
}

Vec2f new_vec2f(float x, float y) {
	Vec2f v;
	v.x = x;
	v.y = y;
	return v;
}

Vec2d new_vec2d(double x, double y) {
	Vec2d v;
	v.x = x;
	v.y = y;
	return v;
}

#endif
