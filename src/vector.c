#include "vector.h"

#include <assert.h>
#include <raylib.h>
#include <raymath.h>

#include <stdlib.h>

#define VECTOR_CAPACITY 10

void CreateVectorInfo(VectorInfo* vector_info, theme_t* theme) {
	vector_info->_theme = theme ? theme : &default_theme;
	vector_info->x      = 0;
	vector_info->y      = 0;
	vector_info->width  = 0;
	vector_info->height = 0;
}

static struct {
	Vector2* data;
	size_t   count;
	size_t   capacity;
} VectorData;

void resize_VectorData(size_t new_capacity) {
	Vector2* data = realloc(VectorData.data, new_capacity * sizeof(Vector2));
	assert(data || "Could not allocate enougth data");
	VectorData.data     = data;
	VectorData.capacity = new_capacity;
}

void push_VectorData(Vector2 v) {
	if (VectorData.count >= VectorData.capacity)
		resize_VectorData(VectorData.capacity + VECTOR_CAPACITY);
	VectorData.data[VectorData.count++] = v;
}

void pop_VectorData() {
	assert(VectorData.count > 0);
	VectorData.count--;
}

void clear_VectorData() { VectorData.count = 0; }

void destroy_VectorData() {
	free(VectorData.data);
	VectorData.data     = NULL;
	VectorData.capacity = 0;
	VectorData.count    = 0;
}

void erase_VectorData(size_t index) {
	assert(index < VectorData.count);
	VectorData.count--;
	for (size_t i          = index; i < VectorData.count; i++)
		VectorData.data[i] = VectorData.data[i + 1];
}


void InitVector() {
	VectorData.data = calloc(VECTOR_CAPACITY, sizeof(Vector2));
	assert(VectorData.data || "Could not allocate enougth data");
	VectorData.count    = 0;
	VectorData.capacity = VECTOR_CAPACITY;
}

bool Vector2InBounds(Vector2 v, Rectangle r) {
	return	v.x >= r.x				&&
			v.x <= r.x + r.width	&&
			v.y >= r.y				&&
			v.y <= r.y + r.height;
}

void VectorUpdate(VectorInfo* vi) {
	const float dwidth = 40;
	const Vector2 mouse = GetMousePosition();
	static bool clicked = false;

	const Rectangle b1 = (Rectangle){
		.x		= (float)vi->x,
		.y		= (float)vi->y,
		.width	= dwidth,
		.height	= dwidth
	};
	DrawRectangleRounded(
		b1,
		.5f,
		5,
		clicked? va_gruvbox_colors[23] : va_gruvbox_colors[21]
	);
	DrawRectangleRoundedLinesEx(
		b1,
		.5f,
		5,
		2.f,
		clicked? va_gruvbox_colors[17] : va_gruvbox_colors[9]
	);
	if (!IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) return;
	if (Vector2InBounds(mouse, b1)) {
		clicked = !clicked;
	} else {
		clicked = false;
	}
}


void ShutdownVector() { destroy_VectorData(); }
