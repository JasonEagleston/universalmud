#ifndef UNIVERSAL_MUD_VEC
#define UNIVERSAL_MUD_VEC
typedef struct {
	void* data;
	int cursor;
	int len;
	uint8_t dlen;
	bool* pop;
} Vec;

Vec vec(size_t dlen, unsigned int len) {
	Vec v;
	v.data = malloc(dlen * len);
	v.cursor = 0;
	v.dlen = dlen;
	v.len = len;
	v.pop = malloc(sizeof(bool) * len);
}

void free_vec(Vec v) {
	free(vec.data);
	free(vec.pop);
}

void v_resize(Vec v, unsigned int len) {
	void* new_data = malloc(v.dlen * len);
	memcpy(new_data, v.data, v.dlen * v.len);
	v.len = len;
	free(v.data);
	v.data = new_data;
}

void v_push(Vec v, void* data, size_t size) {
	memcpy(v.data + (cursor * size), data, size);
	v.cursor++;
}
void v_insert(Vec v, void* data, size_t size, int at);
void* v_get(Vec v, int at);
void* v_pop(Vec v) {
	void* retval = v.data + v.cursor * v.dlen;
	v.cursor--;

	return retval;
}

#endif
