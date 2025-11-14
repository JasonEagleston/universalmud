
#include "raylib.h"

int main() {

	InitWindow(800, 600, "Universal MUD Client");

	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
	
	return 0;
}
