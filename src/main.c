#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>

#include "vector.h"

int main()
{
	printf("Hello, World!\n");

	InitWindow(800, 450, "raylib [core] example - basic window");
	SetTargetFPS(60);
	SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

	InitVector();

	VectorInfo vi;
	CreateVectorInfo(&vi, NULL);

	vi.height = GetScreenHeight();
	vi.width  = GetScreenWidth();
	vi.x = 10;
	vi.y = 10;

	while (!WindowShouldClose())
	{
		vi.height = GetScreenHeight() - 10;
		vi.width  = GetScreenWidth() - 10;

		BeginDrawing();
		ClearBackground(vi._theme->bg.bg);
		VectorUpdate(&vi);
		EndDrawing();
	}

	ShutdownVector();
	CloseWindow();

	return 0;
}
