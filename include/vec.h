#ifndef YUKEN_VEC
#define YUKEN_VEC

typedef struct {
	void* data;
	bool* pop;
	int cursor;
	int len;
	uint8_t dlen;
} Vec;

Vec vec(size_t dlen, unsigned int len) {
	Vec v;
	v.data = malloc(dlen * len);
	v.cursor = 0;
	v.dlen = dlen;
	v.len = len;
	v.pop = malloc(sizeof(bool) * len);
}

void free_vec(Vec* v) {
	free(vec->data);
	free(vec->pop);
}

void v_setpop(Vec* v, int at, bool popped) {
	*(v->pop + at) = popped;
}

bool v_ispop(Vec* v, int at) {
	bool retval = *(v->popped + at);
	return retval;
}

void v_resize(Vec* v, unsigned int len) {
	void* new_data = malloc(v->dlen * len);
	memcpy(new_data, v->data, v->dlen * v->len);
	v->len = len;
	free(v->data);
	v->data = new_data;
}

void v_push(Vec* v, void* data) {
	memcpy(v->data + (cursor * v->dlen), data, v->dlen);
	*(v->pop + v->cursor) = 1;
	v->cursor++;
}

void v_shift(Vec* v, int at, int len, bool right) {
	void* data = malloc(v->len * v->dlen);
	int free_space_after_cursor = 0;
	for (unsigned int i = v->cursor; i < v->len; i++) {
		free_space_after_cursor += v_ispop(v, i);
	}

	// If we don't have enough slots after cursor to shift right/left, reallocate & move stuff.

	if (len > free_space_after_cursor) {

	}
}

void v_insert(Vec* v, void* data, size_t size, int at) {
	bool popped = *(v->pop + at);
	// if populated shift right then insert
	if (popped) {
		v_shift(v, at, 1, 1);
	}
	v_setpop(v, at, 1);
	memcpy(v->data + at, data, v->dlen);
}

void* v_get(Vec* v, int at) {
	void* retval = v->data + at * v->dlen;
	return retval;
}

void* v_pop(Vec* v) {
	void* retval = v->data + v->cursor * v->dlen;
	*(v->pop + v->cursor) = 0;
	v->cursor--;

	return retval;
}

#endif
