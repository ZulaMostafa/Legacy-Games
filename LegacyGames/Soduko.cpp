#include<SFML\Graphics.hpp>
#include<iostream>
#include <Soduko.h>

using namespace std;
using namespace sf;
const int windowWidth = 500, windowHeight = 700, clickDelayS = 0.9;
Color background(255, 228, 181);
Color HoverColor(238, 73, 73);

Sodoku::Sodoku(RenderWindow& win) : window(win) {
	Loadtemplates();
	loadscoreBoard();

	font.loadFromFile("Files\\Kristen ITC.ttf");

    #pragma region loadFiles

	abdullahTexture.loadFromFile("Images\\TicTac\\credits\\Abdullah.png");
	martinoTexture.loadFromFile("Images\\TicTac\\credits\\Martino.png");
	salahTexture.loadFromFile("Images\\TicTac\\credits\\Salah.png");
	beshoyTexture.loadFromFile("Images\\TicTac\\credits\\Beshoy.png");
	squareclickedTexture.loadFromFile("Images\\TicTac\\SquareWin.png");
	squareTexture.loadFromFile("Images\\TicTac\\Square.png");
	playbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\playButton.png");
	quitbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\quitButton.png");
	scorebuttonTexture.loadFromFile("Images\\TicTac\\Menu\\scoreButton.png");
	easybuttonTexture.loadFromFile("Images\\TicTac\\Menu\\easyButton.png");
	mediumbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\mediumButton.png");
	hardbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\HardButton.png");
	creditsbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\creditsButton.png");
	logoTexture.loadFromFile("Images\\Menu\\sudoku.png");
	textboxTexture.loadFromFile("Images\\TicTac\\textBox.png");
	backbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\backButton.png");
	soundbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\sound.png");
	muteuttonTexture.loadFromFile("Images\\TicTac\\Menu\\mute.png");
#pragma endregion
    #pragma region Menu

#pragma region  logo
	logo.setTexture(logoTexture);
	logo.scale(0.9f, 1.1f);
	logo.setPosition(windowWidth / 2 - logo.getGlobalBounds().width / 2, 30.0f);
#pragma endregion
#pragma region text box
	nameTextBox.setTexture(textboxTexture);
	nameTextBox.scale(logo.getGlobalBounds().width / nameTextBox.getGlobalBounds().width, 0.4f);
#pragma endregion
#pragma region difficulties buttons
	easyButton.setTexture(easybuttonTexture);
	easyButton.scale(0.8f, 0.8f);
	easyButton.setPosition(windowWidth / 2 - easyButton.getGlobalBounds().width / 2, 360.0f);

	mediumButton.setTexture(mediumbuttonTexture);
	mediumButton.scale(0.8f, 0.8f);
	mediumButton.setPosition(windowWidth / 2 - mediumButton.getGlobalBounds().width / 2, 490.0f);

	hardButton.setTexture(hardbuttonTexture);
	hardButton.scale(0.8f, 0.8f);
	hardButton.setPosition(windowWidth / 2 - hardButton.getGlobalBounds().width / 2, 600.0f);
#pragma endregion
#pragma region Main Menu Sprites
	playButton.setTexture(playbuttonTexture);
	playButton.scale(0.8f, 0.8f);
	playButton.setPosition((windowWidth / 2) - (playButton.getGlobalBounds().width / 2), logo.getPosition().y + logo.getGlobalBounds().height + 20.0f);

	scoreButton.setTexture(scorebuttonTexture);
	scoreButton.scale(0.8f, 0.8f);
	scoreButton.setPosition((windowWidth / 2) - (scoreButton.getGlobalBounds().width / 2), playButton.getPosition().y + playButton.getLocalBounds().height - 20);

	creditsButton.setTexture(creditsbuttonTexture);
	creditsButton.scale(0.8f, 0.8f);
	creditsButton.setPosition((windowWidth / 2) - (creditsButton.getGlobalBounds().width / 2), scoreButton.getPosition().y + scoreButton.getGlobalBounds().height - 10);

	quitButton.setTexture(quitbuttonTexture);
	quitButton.scale(0.8f, 0.8f);
	quitButton.setPosition((windowWidth / 2) - (quitButton.getGlobalBounds().width / 2), creditsButton.getPosition().y + creditsButton.getGlobalBounds().height);
#pragma endregion
#pragma region credits Sprites
	Martino.setTexture(martinoTexture);
	Martino.scale(0.8f, 0.8f);
	Martino.setPosition((windowWidth / 2) - (Martino.getGlobalBounds().width / 2), logo.getPosition().y + logo.getGlobalBounds().height);

	Beshoy.setTexture(beshoyTexture);
	Beshoy.scale(0.8f, 0.8f);
	Beshoy.setPosition((windowWidth / 2) - (Beshoy.getGlobalBounds().width / 2), Martino.getPosition().y + Martino.getLocalBounds().height - 5);

	Abdullah.setTexture(abdullahTexture);
	Abdullah.scale(0.8f, 0.8f);
	Abdullah.setPosition((windowWidth / 2) - (Abdullah.getGlobalBounds().width / 2), Beshoy.getPosition().y + Beshoy.getGlobalBounds().height + 20);

	Salah.setTexture(salahTexture);
	Salah.scale(0.8f, 0.8f);
	Salah.setPosition((windowWidth / 2) - (Salah.getGlobalBounds().width / 2), Abdullah.getPosition().y + Abdullah.getGlobalBounds().height + 20);
#pragma endregion
#pragma region settings buttons
	backButton.setTexture(backbuttonTexture);
	backButton.scale(0.1f, 0.1f);
	backButton.setPosition(windowWidth - backButton.getGlobalBounds().width - 10, windowHeight - backButton.getGlobalBounds().height - 10);

	soundButton.setTexture(soundbuttonTexture);
	soundButton.scale(0.1f, 0.1f);
	soundButton.setColor(Color(255, 255, 255));
	soundButton.setPosition(0.f, windowHeight - soundButton.getGlobalBounds().height);
#pragma endregion
#pragma region Load squares 

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int itoAdd = 0, jtoAdd = 0;
			if (i >= 3)
				itoAdd = 20;
			if (i >= 6)
				itoAdd = 40;
			if (j >= 3)
				jtoAdd = 20;
			if (j >= 6)
				jtoAdd = 40;
			squareSprites[i][j].setTexture(squareTexture);
			squareSprites[i][j].scale(0.055f, 0.055f);
			squareSprites[i][j].setPosition(50 + j * 75 + jtoAdd, 50 + i * 75 + itoAdd);
		}
	}

#pragma endregion
#pragma endregion


}
void Sodoku::LoadMenu(bool& menu) {
	window.draw(logo);
 
    #pragma region back button handling

	Vector2f mousePos = getmousePos();
	elapsedclickDelay = clickDelay.getElapsedTime();
	if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		backButton.setColor(HoverColor);
		if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= 0.8f) {
			if (CurrMode == setName || CurrMode == CreditsMode || CurrMode == ScoreBoard)
				CurrMode = MainMenuMode, clickDelay.restart();
			else if (CurrMode == DifficlutiesChooser)
				CurrMode = setName, clickDelay.restart();
			else if (CurrMode == MainMenuMode) {
				menu = true;
				//clickDelay.restart();
				window.create(VideoMode(1024, 700), "Legacy Games");
			}
		}
	}
	else
		backButton.setColor(Color::White);
	window.draw(backButton);
#pragma endregion
    #pragma region main menu buttons

	if (CurrMode == MainMenuMode) {
		Vector2f mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS)
				CurrMode = setName, clickDelay.restart();
			playButton.setColor(HoverColor);
		}
		else
			playButton.setColor(Color::White);
		if (quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS)
				window.close();
			quitButton.setColor(HoverColor);
		}
		else
			quitButton.setColor(Color::White);
		if (scoreButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS)
				CurrMode = ScoreBoard, clickDelay.restart();
			scoreButton.setColor(HoverColor);
		}
		else
			scoreButton.setColor(Color::White);
		if (creditsButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS)
				CurrMode = CreditsMode, clickDelay.restart();
			creditsButton.setColor(HoverColor);
		}
		else
			creditsButton.setColor(Color::White);
		window.draw(playButton);
		window.draw(quitButton);
		window.draw(scoreButton);
		window.draw(creditsButton);
	}
#pragma endregion
    #pragma region set name menu
	if (CurrMode == setName) {
		Text playerNametext;
		playerNametext.setFont(font);
		playerNametext.setCharacterSize(40);
		playerNametext.setString("Player Name:");
		playerNametext.setPosition(logo.getPosition().x, logo.getPosition().y + logo.getGlobalBounds().height + 100);
		window.draw(playerNametext);

		Vector2f mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (nameTextBox.getGlobalBounds().contains(mousePos.x, mousePos.y)
			&& Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS) {
			istextboxON = true;
		}
		else if (!nameTextBox.getGlobalBounds().contains(mousePos.x, mousePos.y))
			istextboxON = false;

		Text name;
		name.setFont(font);
		name.setCharacterSize(35);
		name.setString(playerName);
		name.setPosition(nameTextBox.getPosition().x + 5, nameTextBox.getPosition().y);

		Text goText;
		goText.setFont(font);
		goText.setCharacterSize(50);
		goText.setString("GO!!");
		goText.setPosition(windowWidth / 2 - goText.getGlobalBounds().width / 2, windowHeight - goText.getGlobalBounds().height - 20);

		mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (goText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			goText.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS && playerName.size() > 0) {
				CurrMode = DifficlutiesChooser;
				clickDelay.restart();
				if (!playerExists(playerName))
					Players.push_back(Player{ playerName, 0 });
				savescoreBoard();
			}
		}
		else
			goText.setColor(Color::White);


		nameTextBox.setPosition(logo.getPosition().x, playerNametext.getPosition().y + playerNametext.getGlobalBounds().height + 15);
		window.draw(nameTextBox);
		window.draw(name);
		window.draw(goText);
	}
#pragma endregion 
    #pragma region Difficulties choosing buttons

	if (CurrMode == DifficlutiesChooser) {
		Vector2f mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (easyButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			easyButton.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS) {
				CurrDiff = EasyMode; 
				clickDelay.restart();
				CurrMode = PlayMode;
				window.create(VideoMode(800, 840), "Sudoku!");
				loadrandomTemplate();
			}
		}
		else
			easyButton.setColor(Color::White);
		mousePos = getmousePos();
		if (mediumButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			mediumButton.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS) {
				CurrDiff = MediumMode;
				clickDelay.restart();
				CurrMode = PlayMode; 
				window.create(VideoMode(800, 840), "Sudoku!");
				loadrandomTemplate();
			}
		}
		else
			mediumButton.setColor(Color::White);

		mousePos = getmousePos();
		if (hardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			hardButton.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= 0.9) {
				CurrDiff = HardMode;
				clickDelay.restart();
				CurrMode = PlayMode;
				window.create(VideoMode(800, 840), "Sudoku!");
				loadrandomTemplate();
			}
		}
		else
			hardButton.setColor(Color::White);
		window.draw(easyButton);
		window.draw(mediumButton);
		window.draw(hardButton);
	}
#pragma endregion
    #pragma region credits 
	if (CurrMode == CreditsMode) {
		window.draw(Salah);
		window.draw(Abdullah);
		window.draw(Beshoy);
		window.draw(Martino);
	}
#pragma endregion
    #pragma region ScoreBoard
	if (CurrMode == ScoreBoard) {
		sort(Players.begin(), Players.end());

		Text winsText;
		winsText.setFont(font);
		winsText.setCharacterSize(40);
		winsText.setFillColor(HoverColor);
		winsText.setString("wins");
		winsText.setPosition(windowWidth - (winsText.getGlobalBounds().width * 1.5), logo.getPosition().y + logo.getGlobalBounds().height);


		Text nameText;
		nameText.setFont(font);
		nameText.setCharacterSize(40);
		nameText.setFillColor(HoverColor);
		nameText.setString("Name");
		nameText.setPosition((winsText.getPosition().x - winsText.getGlobalBounds().width / 2) / 3, logo.getPosition().y + logo.getGlobalBounds().height);

		for (int i = indexStarter; i < indexStarter + min(5, (int)Players.size()); i++) {
			Text playerName;
			playerName.setFont(font);
			playerName.setCharacterSize(40);
			playerName.setString(Players[i].name);
			playerName.setPosition(nameText.getPosition().x + nameText.getGlobalBounds().width / 2 - playerName.getGlobalBounds().width / 2,
				nameText.getPosition().y + nameText.getGlobalBounds().height + 30 + ((i - indexStarter) * 50));
			playerName.setFillColor(Color::Black);

			Text playerScore;
			playerScore.setFont(font);
			playerScore.setCharacterSize(40);
			playerScore.setString(to_string(Players[i].wins));
			playerScore.setPosition(winsText.getPosition().x + winsText.getGlobalBounds().width / 2 - playerScore.getGlobalBounds().width / 2,
				nameText.getPosition().y + nameText.getGlobalBounds().height + 30 + ((i - indexStarter) * 50));
			playerScore.setFillColor(Color::Black);

			window.draw(playerName);
			window.draw(playerScore);
		}

		window.draw(nameText);
		window.draw(winsText);


	}
#pragma endregion

}
void Sodoku::whilePlaying(bool& menu) {
	window.clear(background); 

	bool toPass = false;
	if (CurrMode != PlayMode)
		LoadMenu(toPass);
	menu = toPass;

	Vector2f mousePos = getmousePos();
	elapsedclickDelay = clickDelay.getElapsedTime();

    #pragma region in game buttons


	if (CurrMode == PlayMode) {
		Text checkButton, retryButton, menuButton;
		checkButton.setFont(font);
		checkButton.setCharacterSize(50);
		checkButton.setString("Check");
		checkButton.setPosition(squareSprites[0][0].getPosition().x, window.getSize().y - checkButton.getGlobalBounds().height - 40);

		Vector2f mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (checkButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			checkButton.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS)
				checkCurrent(), clickDelay.restart();
		}
		else
			checkButton.setColor(Color::White);


		window.draw(checkButton);

		menuButton.setFont(font);
		menuButton.setCharacterSize(50);
		menuButton.setString("Menu");
		menuButton.setPosition(squareSprites[0][0].getPosition().x + (squareSprites[0][8].getPosition().x - squareSprites[0][0].getPosition().x) / 2 - menuButton.getGlobalBounds().width /2 + 20
			, window.getSize().y - checkButton.getGlobalBounds().height - 40);

		mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (menuButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			menuButton.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= clickDelayS)
				CurrMode = MainMenuMode, window.create(VideoMode(500, 700), "Sudoku!");
		}
		else
			menuButton.setColor(Color::White);

		window.draw(menuButton);

		retryButton.setFont(font);
		retryButton.setCharacterSize(50);
		retryButton.setString("Retry");
		retryButton.setPosition(squareSprites[0][8].getPosition().x + squareSprites[0][8].getGlobalBounds().width - retryButton.getGlobalBounds().width, window.getSize().y - checkButton.getGlobalBounds().height - 40);
		
		mousePos = getmousePos();
		elapsedclickDelay = clickDelay.getElapsedTime();
		if (retryButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			retryButton.setColor(HoverColor);
			if (Mouse::isButtonPressed(Mouse::Left) && elapsedclickDelay.asSeconds() >= 0.4f)
				loadrandomTemplate(), clickDelay.restart();
		}
		else
			retryButton.setColor(Color::White);
		
		window.draw(retryButton);

#pragma endregion

    #pragma region wait for input
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (Mouse::isButtonPressed(Mouse::Left) && squareSprites[i][j].getGlobalBounds().contains(mousePos.x, mousePos.y) && elapsedclickDelay.asSeconds() >= clickDelayS) {
					if (templates[index][i][j] == 0) {
						clickedSquare = Square{ i, j };
						squareclicked = true;
						clickDelay.restart();
					}
				}

				numberTexts[i][j].setCharacterSize(50);
				numberTexts[i][j].setFont(font);

				if (templates[index][i][j] == 0 && numberTexts[i][j].getColor() != Color::Green &&  numberTexts[i][j].getColor() != Color::Red)
					numberTexts[i][j].setFillColor(Color::Yellow);
				else if (numberTexts[i][j].getColor() != Color::Green &&  numberTexts[i][j].getColor() != Color::Red)
					numberTexts[i][j].setFillColor(Color::White);

				if (Board[i][j] == 0)
					numberTexts[i][j].setString("");
				else
					numberTexts[i][j].setString(to_string(Board[i][j]));
				numberTexts[i][j].setPosition(squareSprites[i][j].getPosition().x + squareSprites[i][j].getGlobalBounds().width / 2 - numberTexts[i][j].getGlobalBounds().width / 2
					, squareSprites[i][j].getPosition().y + squareSprites[i][j].getGlobalBounds().height / 2 - numberTexts[i][j].getGlobalBounds().height / 2 - 14);


				if (squareclicked)
					if (i == clickedSquare.x && j == clickedSquare.y)
						squareSprites[i][j].setTexture(squareclickedTexture);
					else
						squareSprites[i][j].setTexture(squareTexture);

				mousePos = getmousePos();
				if (squareSprites[i][j].getGlobalBounds().contains(mousePos.x, mousePos.y) && templates[index][i][j] == 0)
					squareSprites[i][j].setTexture(squareclickedTexture);
				else if (i != clickedSquare.x && j != clickedSquare.y)
					squareSprites[i][j].setTexture(squareTexture);

				window.draw(squareSprites[i][j]);
				window.draw(numberTexts[i][j]);
			}
		}
#pragma endregion

	}
}

#pragma region score board
void Sodoku::loadscoreBoard() {
	fileStream.open("Files\\sodokuBoard.txt");
	int count;
	fileStream >> count;
	for (int i = 0; i < count; i++) {
		string name;
		int wins;
		fileStream >> name >> wins;
		Players.push_back(Player{ name, wins });
	}
	fileStream.close();
}

void Sodoku::savescoreBoard() {
	string toWrite = to_string(Players.size());
	toWrite += "\n";
	for (int i = 0; i < Players.size(); i++) {
		toWrite += Players[i].name;
		toWrite += " ";
		toWrite += to_string(Players[i].wins);
		toWrite += "\n";
	}
	fileStream.open("Files\\sodokuBoard.txt");
	fileStream << toWrite;
	fileStream.close();
}
#pragma endregion


#pragma region templates
void Sodoku::Loadtemplates() {
	fileStream.open("Files\\questions.txt");
	int count;
	fileStream >> count;
	for (int i = 0; i < count; i++) {
		vector<vector<int>> board(9, vector<int>(9));
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				int num;
				fileStream >> num;
				board[j][k] = num;
			}
		}
		templates.push_back(board);
	}
	fileStream.close();

	fileStream.open("Files\\solutions.txt");
	count;
	fileStream >> count;
	for (int i = 0; i < count; i++) {
		vector<vector<int>> board(9, vector<int>(9));
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				int num;
				fileStream >> num;
				board[j][k] = num;
			}
		}
		solutions.push_back(board);
	}
	fileStream.close();

}

void Sodoku::loadrandomTemplate() {
	index = rand() % 3;
	if (CurrDiff == MediumMode)
		index += 3;
	else if (CurrDiff == HardMode)
		index += 6;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			squareclicked = false;
			squareSprites[i][j].setTexture(squareTexture);
			numberTexts[i][j].setCharacterSize(50);
			numberTexts[i][j].setFont(font);
			Board[i][j] = templates[index][i][j];
			if (templates[index][i][j] == 0)
				numberTexts[i][j].setString(""), numberTexts[i][j].setFillColor(Color::White);
			else
				numberTexts[i][j].setString(to_string(templates[index][i][j])), numberTexts[i][j].setFillColor(Color::White);;
			numberTexts[i][j].setPosition(squareSprites[i][j].getPosition().x + squareSprites[i][j].getGlobalBounds().width / 2 - numberTexts[i][j].getGlobalBounds().width / 2
				, squareSprites[i][j].getPosition().y + squareSprites[i][j].getGlobalBounds().height / 2 - numberTexts[i][j].getGlobalBounds().height / 2 - 14);
		}
	}
}
#pragma endregion

#pragma region Helping function

Vector2f Sodoku::getmousePos() {
	Vector2i mousePos = Mouse::getPosition(window);
	return Vector2f((float)mousePos.x, (float)mousePos.y);
}

bool Sodoku::playerExists(string playerName) {
	for (int i = 0; i < Players.size(); i++)
		if (Players[i].name == playerName)
			return true;
	return false;
}

void Sodoku::editPlayer(string playerName) {
	for (int i = 0; i < Players.size(); i++) {
		if (Players[i].name == playerName)
			Players[i].wins++;
	}
}


void Sodoku::checkCurrent() {
	bool win = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (templates[index][i][j] == 0) {
				if (Board[i][j] == solutions[index][i][j])
					numberTexts[i][j].setColor(Color::Green);
				else
					numberTexts[i][j].setColor(Color::Red), win = false;
			}
		}
	}
	if (win)
		editPlayer(playerName);
}
#pragma endregion

