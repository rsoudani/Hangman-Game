#include <iostream>
#include "game.h"

using namespace std;

void Initialize();
void GetInput();
void Update();
void Render();
void Shutdown();

bool g_exitGame = false;
Game g_game;
int main() {
	Initialize();
	while (!g_exitGame) {
		GetInput();
		Update();
		Render();
	}
	Shutdown();

}

void Initialize()
{
	g_game.OnInit();
}

void GetInput()
{
	g_game.OnInput();
}

void Update()
{
	g_game.OnUpdate();
}

void Render()
{
	g_game.OnRender();
}

void Shutdown()
{
	g_game.OnShutdown();
}
