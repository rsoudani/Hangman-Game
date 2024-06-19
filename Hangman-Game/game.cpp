#include "Game.h"
#include <ctime>
#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string> 
#include "HangmanStages.h"

using namespace std;

void Game::OnInit()
{
	srand(std::time(NULL));

	ifstream inputFile("words.txt");
	if (inputFile.is_open()) {
		std::string line;
		vector<string> lines;
		while (std::getline(inputFile, line)) {
			string cell;
			std::stringstream ss(line);
			while (getline(ss, cell, ' ')) {
				lines.push_back(cell);
			}
		}
		m_wordsPool = lines;
	}
	m_word = m_wordsPool[rand() % m_wordsPool.size()];
	m_guessedMask = 0;
	m_gameState = GameState::START;
	m_guessedLetter = NULL;
	m_missedLetters.clear();
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
			m_missedLetters.insert(m_guessedLetter);
		}
		m_guessedLetter = NULL;
	}

	if (m_missedLetters.size() >= HANGMAN_STAGES.size() - 1) {
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
	cout << HANGMAN_STAGES[m_missedLetters.size()] << endl;
	cout << "Nietrafione litery: " << string(m_missedLetters.begin(), m_missedLetters.end());
	cout << endl << endl;

	if (m_gameState == GameState::FINISH) {
		if (m_isWin) {
			cout << "Wygrana, gratulacje!";
		}
		else {
			cout << "Przegrana! Szukane slowo to: " << m_word;
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