#include "Game.h"
#include <ctime>
#include <iostream>
#include "HangmanStages.h"

using namespace std;

void Game::OnInit()
{
	m_guessedMask = 0;
	srand(std::time(NULL));
	m_word = m_wordsPool[rand() % m_wordsPool.size()];
	m_gameState = GameState::START;
	m_guessedLetter = NULL;
	m_missedLetters = 0;
	m_isWin = false;
}

void Game::OnInput()
{
	if (m_gameState == GameState::UPDATE) {
		cout << "Podaj litere: ";
		cin >> m_guessedLetter;
	}
}

bool Game::OnUpdate()
{
	if (m_guessedLetter != NULL) {
		bool letterFound = false;
		for (int i = 0; i < m_word.size(); ++i) {
			if (m_word[i] == m_guessedLetter) {
				m_guessedMask |= (1 << i);
				letterFound = true;
			}
		}
		if (!letterFound) {
			m_missedLetters++;
		}
		m_guessedLetter = NULL;
	}

	if (m_missedLetters >= HANGMAN_STAGES.size() - 1) {
		m_gameState = GameState::FINISH;
		return true;
	}

	int fullMask = (1 << m_word.size()) - 1;
	if (m_guessedMask == fullMask) {
		m_isWin = true;
		m_gameState = GameState::FINISH;
		return true;
	}

	m_gameState = GameState::UPDATE;
	return false;

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
	cout << endl << endl;
	cout << HANGMAN_STAGES[m_missedLetters];
	cout << endl << endl;

	if (m_gameState == GameState::FINISH) {
		if (m_isWin) {
			cout << "Wygrana, gratulacje!";
		}
		else {
			cout << "Przegrana!";
		}
		cin.ignore(256, '\n');
		cin.ignore();
	}
}

void Game::OnShutdown()
{
	m_guessedMask = 0;
	m_gameState = GameState::FINISH;
}