#ifndef VECTOR_H
#define VECTOR_H

#include <raylib.h>

#define rgba(r,g,b,a) {r,g,b,a}
#define rgb(r,g,b) {r,g,b,255}

typedef struct ColorTheme {
	struct {
		Color bg;
		Color bg2;
		Color bg3;
	} bg;

	struct {
		Color primary;
		Color secondary;
		Color tertiary;
	} main;

	struct {
		Color accent;
		Color accent2;
	} accent;
} theme_t;

// https://github.com/morhetz/gruvbox
static Color va_gruvbox_colors[] = {
	rgb(40, 40, 40),		// bg		0
	rgb(235, 219, 178),	// fg		1

	/*
	 * Colors
	 */
	// darker
	rgb(204, 36, 29),	// red		2
	rgb(152, 151, 26),	// green	3
	rgb(215, 153, 33),	// yellow	4
	rgb(69, 133, 136),	// blue		5
	rgb(177, 98, 134),	// purple	6
	rgb(104, 157, 106),	// aqua		7
	rgb(168, 153, 132),	// gray		8
	rgb(214, 93, 14),	// orange	9
	// lighter
	rgb(251, 73, 52),	// red		10
	rgb(184, 187, 38),	// green	11
	rgb(250, 189, 47),	// yellow	12
	rgb(131, 165, 152),	// blue		13
	rgb(211, 134, 155),	// purple	14
	rgb(142, 192, 124),	// aqua		15
	rgb(146, 131, 116),	// gray		16
	rgb(254, 128, 25),	// orange	17


	/*
	 * Backgrounds and Foregrounds
	 */
	// dark
	rgb(29, 32, 33),		//			18
	rgb(40, 40, 40),		//			19
	rgb(50, 48, 47),		//			20
	rgb(60, 56, 54),		//			21
	rgb(80, 73, 69),		//			22
	rgb(102, 92, 84),	//			23
	rgb(124, 111, 100),	//			24
	// light
	rgb(168, 153, 132),	//			27
	rgb(189, 174, 147),	//			28
	rgb(213, 196, 161),	//			29
	rgb(235, 219, 178),	//			30
	rgb(251, 241, 199)	//			31
};


static theme_t default_theme = {
	.bg = {
		.bg = rgb(40, 40, 40),
		.bg2 = {0x3c, 0x38, 0x36, 255},
		.bg3 = {0x50, 0x49, 0x45, 255},
	},
	.main = {
		.primary = {0x4b, 0xdb, 0xb2, 255},
		.secondary = {0xbd, 0xae, 0x93, 255},
		.tertiary = {0x83, 0xa5, 0x98, 255},
	},
	.accent = {
		.accent = {0x98, 0x97, 0x1a, 255},
		.accent2 = {0xd7, 0x99, 0x21, 255},
	},
};

typedef struct VectorAppInfo {
	int x,     y;
	int width, height;

	float scale;

	theme_t* _theme;
} VectorInfo;


void CreateVectorInfo(VectorInfo* vector_info, theme_t* theme);


void InitVector();

void VectorUpdate(VectorInfo*);

void ShutdownVector();

#undef rgba
#undef rgb
#endif //VECTOR_H
