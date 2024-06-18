#include "Game.h"
#include <ctime>
#include <iostream>

using namespace std;

void Game::OnInit()
{
	m_guessedMask = 0;
	srand(std::time(NULL));
	m_word = m_wordsPool[rand() % m_wordsPool.size()];
	m_gameState = GameState::START;
	m_guessedLetter = NULL;
	OnRender();

}

void Game::OnInput()
{
	cout << "Podaj litere: ";
	cin >> m_guessedLetter;
}

void Game::OnUpdate()
{

	if (m_guessedLetter != NULL)
		for (int i = 0; i < m_word.size(); ++i) {
			if (m_word[i] == m_guessedLetter) {
				m_guessedMask |= (1 << i);
			}
		}
	m_guessedLetter = NULL;
}

void Game::OnRender()
{
	system("cls");
	for (int i = 0; i < m_word.size(); i++) {
		if (m_guessedMask & (1ULL << i)) {
			cout << m_word[i] << " ";
		}
		else {
			cout << "_ ";
		}
	}
	cout << endl;
}

void Game::OnShutdown()
{
	m_guessedMask = 0;
	m_gameState = GameState::FINISH;
}