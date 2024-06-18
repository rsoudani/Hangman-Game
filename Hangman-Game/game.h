#pragma once
#include <string>
#include <vector>

class Game {

	enum class GameState {
		START,
		UPDATE,
		FINISH,
	};
public:
	void OnInit();
	void OnInput();
	void OnUpdate();
	void OnRender();
	void OnShutdown();
private:
	std::string m_word;
	std::vector<std::string> m_wordsPool = { "kolor", "kanapka", "pancernik", "silnia", "autobus" };
	std::vector<bool> m_guessedLetters;
	GameState m_gameState = GameState::START;

};