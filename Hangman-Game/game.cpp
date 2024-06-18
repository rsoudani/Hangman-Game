#include "Game.h"
#include <ctime>

void Game::OnInit()
{
	m_guessedLetters.clear();
	srand(std::time(NULL));
	m_word = m_wordsPool[rand() % m_wordsPool.size()];
	m_gameState = GameState::START;
}

void Game::OnInput()
{
}

void Game::OnUpdate()
{
}

void Game::OnRender()
{
}

void Game::OnShutdown()
{
	m_guessedLetters.clear();
	m_gameState = GameState::FINISH;
}
