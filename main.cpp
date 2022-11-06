#include "headers/main.h"

using namespace std;

const int width = 1000, height = 1000;

// Default Settings
#define _DEFAULT 			0

// Animations
#define ANIMATION_PARROT	1

// Games
#define SUDOKU				2 // Fundle this infernal(hellish)  
#define SNAKE				3
#define PONG				4
#define _R2048				5
#define GAME_OF_LIFE		6
#define CLOCK				7
#define CROSSHARES			8
// Example of a square
#define Object				-1

// Current STATE
#define STATE CROSSHARES 




int main()
{
	Window window("Box Simulator", width, height);

	Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl", "shaders/geometric_shader.glsl");

	float x, y; 
	float _x = 0.0f, _y = 0.0f, _z = -80.65f; 

	shader.enable();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(_x, _y, _z)));

	glViewport(0, 0, width, height);

	TileLayer layer(&shader);

#if STATE == _DEFAULT 
	Grid grid;
	grid.update();

	vector<Renderable2D *> sprites = grid.getRenderables();

#else STATE == CROSSHARES
	CrossHares crosshare(width, height);
	crosshare.update();

	vector<Renderable2D *> sprites = crosshare.getRenderables();

#endif

	for (int i = 0; i < sprites.size(); i++)
		layer.add(sprites.at(i));

	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	chrono::steady_clock::time_point end = begin;

	double elapsed_secs = 0.0f;

	while (!window.closed())
	{
		window.clear();

		if (window.isKeyPressed(GLFW_KEY_ESCAPE))
			break;

		// clear();
		// printf("x = %f, y = %f\n", x, y);

		// printf("time = %f\n", elapsed_secs);

		if (elapsed_secs >= 94000.0f) {
			layer.clean_slate();

#if STATE == _DEFAULT 
			// grid.Default_State();
			// grid.Random();
			grid.alpha_numeric_test();
			grid.update();

			vector<Renderable2D *> sprites = grid.getRenderables();

#elif STATE == CROSSHARES
			crosshare.update();

			vector<Renderable2D *> sprites = crosshare.getRenderables();
			
			if (window.isKeyPressed(GLFW_KEY_Q)) _z += 3.0f;
			if (window.isKeyPressed(GLFW_KEY_E)) _z -= 3.0f;
			
			if (window.isKeyPressed(GLFW_KEY_W)) _y += 1.5f;
			if (window.isKeyPressed(GLFW_KEY_S)) _y -= 1.5f;
			
			if (window.isKeyPressed(GLFW_KEY_A)) _x -= 1.5f;
			if (window.isKeyPressed(GLFW_KEY_D)) _x += 1.5f;
			
			shader.enable();
			shader.setUniformMat4("ml_matrix", mat4::translation(vec3(_x, _y, _z)));

			cout << "x = " << _x << ", y = " << _y << ", z = " << _z << endl;

#elif STATE == _R2048
			if (window.isKeyPressed(GLFW_KEY_Q)) r2048.q_key_pressed();
			if (window.isKeyPressed(GLFW_KEY_W)) r2048.w_key_pressed();
			if (window.isKeyPressed(GLFW_KEY_A)) r2048.a_key_pressed();
			if (window.isKeyPressed(GLFW_KEY_S)) r2048.s_key_pressed();
			if (window.isKeyPressed(GLFW_KEY_D)) r2048.d_key_pressed();

			r2048.printUI(); // Used to be a thing, but now deprecated
			r2048.Draw();
			r2048.update();

			vector<Renderable2D *> sprites = r2048.getRenderables();


#endif

			for (int i = 0; i < sprites.size(); i++)
				layer.add(sprites.at(i));

			begin = chrono::steady_clock::now();
		}

		shader.enable();

		end = chrono::steady_clock::now();
		elapsed_secs = chrono::duration_cast<chrono::microseconds>(end - begin).count() * 1.0f;

		window.getMousePosition(x, y);

		shader.enable();
		layer.render();

		window.update();
	}

	return 0;
}
