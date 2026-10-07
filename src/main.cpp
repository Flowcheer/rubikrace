#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(800, 600, "Rubik's Race");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	
	// define the game board, each number represents a color
	int squares[] = {
	        4,4,4,4,3,
			2,1,3,5,6,
			2,1,0,5,6,
			2,1,3,5,6,
			2,1,3,5,6
	};
	// define the sizes of the board, looks irrelevant but i dont know how to get array sizes so this way its easier and more flexible ig
	const int TILES_WIDTH = 5;
	const int TILES_HEIGHT = 5;

	// define each color in an array so i can access it with the numbers in the board
	Color colors[] = { BLANK, WHITE, RED, BLUE, GREEN, YELLOW, ORANGE };
	Texture square = LoadTexture("square.png");

	// Set fps to 60
	SetTargetFPS(60);

	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);
		// draw our texture to the screen
		for(int i = 0, length = TILES_HEIGHT * TILES_HEIGHT; i < length;i++)
		{
		    // define columns and rows to position each square depending on it
		    int col = i % TILES_WIDTH;
			int row = i / TILES_HEIGHT;
		    Rectangle dest = {
						col * 100.0f,
						row * 100.0f,
						100.0f,
						100.0f
			};
		    DrawTexturePro(square, {0.0f,0.0f,360.0f,360.0f}, dest, {0.0f,0.0f}, 0.0f, colors[squares[i]]);
		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(square);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
