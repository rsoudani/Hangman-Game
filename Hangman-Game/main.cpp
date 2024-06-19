#include <iostream>
#include "game.h"

using namespace std;

void Initialize();
void GetInput();
bool Update();
void Render();
void Shutdown();

bool g_exitGame = false;
Game g_game;
int main() {
	Initialize();
	while (!g_exitGame) {
		GetInput();
		g_exitGame = Update();
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

bool Update()
{
	return g_game.OnUpdate();
}

void Render()
{
	g_game.OnRender();
}

void Shutdown()
{
	g_game.OnShutdown();
}
