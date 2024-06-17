#include <iostream>
#include "game.h"

using namespace std;

void Initialize();
void GetInput();
void Update();
void Render();
void Shutdown();

bool g_exitGame = false;
int main() {
	Initialize();
	while (g_exitGame) {
		GetInput();
		Update();
		Render();
	}
	Shutdown();

}

void Initialize()
{
}

void GetInput()
{
}

void Update()
{
}

void Render()
{
}

void Shutdown()
{
}
