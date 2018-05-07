#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <TicTac.h> 
#include<algorithm>
#include<SFML/Audio.hpp>

using namespace std;
using namespace sf;


const int windowWidth = 500, windowHeight = 700;

Color HiddenWhite(255, 255, 255, 0);
Color White(255, 255, 255, 255);
Color BackgroundColor(255, 228, 181);
Color onclickColor(238, 73, 73);


TicTac::TicTac(RenderWindow& win) : window(win) {

	font.loadFromFile("Files\\Kristen ITC.ttf");

	loadScoreBoard();

     #pragma region loadSound
	backgroundsoundBuffer.loadFromFile("Sound\\background.ogg");
	clicksoundBuffer.loadFromFile("Sound\\click.wav");
	playsoundBuffer.loadFromFile("Sound\\play.wav");
#pragma endregion

     #pragma region loadFiles
	squareTexture.loadFromFile("Images\\TicTac\\Square.png");
	oTexture.loadFromFile("Images\\TicTac\\PlayO.png");
	xTexture.loadFromFile("Images\\TicTac\\PlayX.png");
	squarewinTexture.loadFromFile("Images\\TicTac\\SquareWin.png");
	playbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\playButton.png");
	quitbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\quitButton.png");
	scorebuttonTexture.loadFromFile("Images\\TicTac\\Menu\\scoreButton.png");
	creditsbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\creditsButton.png");
	logoTexture.loadFromFile("Images\\TicTac\\Menu\\logo.png");
	easybuttonTexture.loadFromFile("Images\\TicTac\\Menu\\easyButton.png");
	mediumbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\mediumButton.png");
	hardbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\HardButton.png");
	pcbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\pcButton.png");
	versusbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\versusButton.png");
	backbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\backButton.png");
	menubuttonTexture.loadFromFile("Images\\TicTac\\Menu\\menuButton.png");
	retrybuttonTexture.loadFromFile("Images\\TicTac\\Menu\\retryButton.png");
	p1wonTexture.loadFromFile("Images\\TicTac\\p1won.png");
	p2wonTexture.loadFromFile("Images\\TicTac\\p2won.png");
	p1turnTexture.loadFromFile("Images\\TicTac\\p1turn.png");
	p2turnTexture.loadFromFile("Images\\TicTac\\p2turn.png");
	pcwonTexture.loadFromFile("Images\\TicTac\\pcwon.png");
	soundbuttonTexture.loadFromFile("Images\\TicTac\\Menu\\sound.png");
	muteuttonTexture.loadFromFile("Images\\TicTac\\Menu\\mute.png");
	abdullahTexture.loadFromFile("Images\\TicTac\\credits\\Abdullah.png");
	martinoTexture.loadFromFile("Images\\TicTac\\credits\\Martino.png");
	salahTexture.loadFromFile("Images\\TicTac\\credits\\Salah.png");
	beshoyTexture.loadFromFile("Images\\TicTac\\credits\\Beshoy.png");
	textboxTexture.loadFromFile("Images\\TicTac\\textBox.png");
#pragma endregion

     #pragma region Menu 
	 

#pragma region  logo
	logo.setTexture(logoTexture);
	logo.scale(0.7f, 0.7f);
	logo.setPosition(windowWidth / 2 - logo.getGlobalBounds().width / 2, 30.0f);
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

#pragma region modes buttons

	versusButton.setTexture(versusbuttonTexture);
	versusButton.scale(0.8f, 0.8f);
	versusButton.setPosition(windowWidth / 2 - versusButton.getGlobalBounds().width / 2, 360.0f);

	pcButton.setTexture(pcbuttonTexture);
	pcButton.scale(0.8f, 0.8f);
	pcButton.setPosition(windowWidth / 2 - pcButton.getGlobalBounds().width / 2, 570.0f);

#pragma endregion

#pragma region onGame buttons


	menuButton.setTexture(menubuttonTexture);
	menuButton.scale(0.8f, 0.8f);
	menuButton.setPosition(windowWidth / 2 - menuButton.getGlobalBounds().width / 2, 500.0f);

	retryButton.setTexture(retrybuttonTexture);
	retryButton.scale(0.8f, 0.8f);
	retryButton.setPosition(windowWidth / 2 - retryButton.getGlobalBounds().width / 2, 600.0f);
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

#pragma region set first move button (x/o)
	p1Play.setTexture(squareTexture);
	p1Move.setTexture(squareTexture);

	p1Play.scale(0.06f, 0.06f);
	p1Move.scale(0.05f, 0.05f);
#pragma endregion

#pragma region  text boxes 

	p1TextBox.setTexture(textboxTexture);
	p1TextBox.scale(logo.getGlobalBounds().width / p1TextBox.getGlobalBounds().width, 0.4f);

	p2TextBox.setTexture(textboxTexture);
	p2TextBox.scale(logo.getGlobalBounds().width / p2TextBox.getGlobalBounds().width, 0.4f);
#pragma endregion


#pragma endregion

     #pragma region load squares and virtual xos
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			squareSprite[i][j].setTexture(squareTexture);
			squareSprite[i][j].scale(0.08f, 0.08f);
			squareSprite[i][j].setPosition(107 + i * 100, 175 + j * 100);

			XO[i][j].setTexture(xTexture);
			XO[i][j].setPosition(113 + i * 100, 180 + j * 100);
			XO[i][j].setScale(0.065f, 0.065f);
			Hide(XO[i][j]);
		}
	}

#pragma endregion

     #pragma region set defaults


	newGame();
	mode = MenuMode;
#pragma endregion

     #pragma region Music
	backgoundSound.setBuffer(backgroundsoundBuffer);
	backgoundSound.play();
	backgoundSound.setLoop(true);

	clickSound.setBuffer(clicksoundBuffer);
	playSound.setBuffer(playsoundBuffer);


	playSound.setVolume(100);
	clickSound.setVolume(100);
	backgoundSound.setVolume(100);
#pragma endregion

	
}




void TicTac::OnGame(bool& menu) {
	window.clear(BackgroundColor); //clear the background and set its color

	if (menuMode != PlayMode) // check if the the game state is not on play mode then load the menu
		loadMenu();
	else if (mode == VersusMode || (mode == AIMode && (currchosenMove == 'x' && currMove == X || currchosenMove == 'o' && currMove == O)))  {
		//check if the current state is versus mode or bot mode and it's player turn
		//if true wait for the player to input a play
		playerMove();
	}
	if (mode == AIMode && ((currMove == O && opponentMove == 'o') || (currMove == X && opponentMove == 'x')))
		// check if the current state is play mode and it's pc turn
		// if true search for the best move
		botMove();

	if (mode == VersusMode || mode == AIMode || mode == WonMode) { //check if the state is on play
		checkforWin(); //check if there is a winner
        #pragma region XOS buttons on Hover

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Vector2f mousePos = getmousePos();
				if (squareSprite[i][j].getGlobalBounds().contains(mousePos.x, mousePos.y) && Grid[i][j] == '-') {
					if (currMove == X)
						XO[i][j].setTexture(xTexture);
					else
						XO[i][j].setTexture(oTexture);
					Show(XO[i][j]);
				}
				else if (Grid[i][j] == '-')
					Hide(XO[i][j]);
				window.draw(squareSprite[i][j]), window.draw(XO[i][j]);
			}
		}
#pragma endregion
	}

	//draw the back button
	window.draw(backButton);

    #pragma region back button handling
	Vector2f mousePos = getmousePos();
	Time time = clickDelay.getElapsedTime();
	if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		changeColor(backButton, onclickColor);
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() > 0.7) {
			if (menuMode == ModeChooser || menuMode == CreditsMode || menuMode == OptionsMode || menuMode == scoreboardMode)
				menuMode = MainMenuMode, clickSound.play();
			else if (menuMode == DifficultiesMode)
				menuMode = ModeChooser, clickSound.play();
			else if (menuMode == MainMenuMode) {
				menu = true;
				window.create(VideoMode(1024, 700), "Legacy Games!");
			}
			else if (menuMode == VersusSet)
				menuMode = ModeChooser;
			else if (menuMode == PCSet)
				menuMode = ModeChooser;
			else if (menuMode == CreditsMode)
				menuMode = MainMenuMode, clickSound.play();
			else if (mode == AIMode)
				menuMode = DifficultiesMode, mode = MenuMode, clickSound.play();
			else if (mode == VersusMode)
				menuMode = ModeChooser, mode = MenuMode, clickSound.play();
			else if (mode == WonMode && AI)
				menuMode = DifficultiesMode, mode = MenuMode, clickSound.play();
			else if (mode == WonMode && !AI)
				menuMode = VersusSet, mode = MenuMode, clickSound.play();
			clickDelay.restart();
		}
	}
	else
		Show(backButton);
#pragma endregion

    #pragma region menu button and retry button handling
	mousePos = getmousePos();
	time = clickDelay.getElapsedTime();
	if ((mode == AIMode || mode == VersusMode || mode == WonMode) && menuMode == PlayMode) {
		if (menuButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			changeColor(menuButton, onclickColor);
			if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7)
				menuMode = MainMenuMode, mode = MenuMode, clickDelay.restart();
		}
		else
			Show(menuButton);
		if (retryButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			changeColor(retryButton, onclickColor);
			if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
				newGame();
				clickDelay.restart();
				clickSound.play();
				if (AI)
					mode = AIMode;
				else
					mode = VersusMode;
			}
		}
		else
			Show(retryButton);
		window.draw(menuButton);
		window.draw(retryButton);
#pragma endregion

	
	}


#pragma region sound button handling
	mousePos = getmousePos();
	time = soundbuttonDelay.getElapsedTime();
	if (soundButton.getGlobalBounds().contains(mousePos.x, mousePos.y) && Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() > 0.7) {
		if (soundOn) {
			playSound.setVolume(0);
			clickSound.setVolume(0);
			backgoundSound.setVolume(0);
			soundButton.setTexture(muteuttonTexture);
			soundOn = false;
			soundbuttonDelay.restart();
		}
		else {
			playSound.setVolume(100);
			clickSound.setVolume(100);
			backgoundSound.setVolume(100);
			soundButton.setTexture(soundbuttonTexture);
			soundOn = true;
			soundbuttonDelay.restart();
		}
	}
	window.draw(soundButton);
#pragma endregion

	
#pragma region  win texts
	if (mode == WonMode) {

		if (winner == 'x' && currchosenMove == 'x' || winner == 'o' && currchosenMove == 'o') {
			playText.setTexture(p1wonTexture);
			playText.setScale(0.8f, 0.8f);
			playText.setPosition(windowWidth / 2 - playText.getGlobalBounds().width / 2, 50.0f);
			playText.setColor(Color(0, 255, 0));
			window.draw(playText);
		}
		else {
			if (!AI && (opponentMove == 'x' && winner == 'x' || opponentMove == 'o' && winner == 'o')) {
				playText.setTexture(p2wonTexture);
				playText.setScale(0.8f, 0.8f);
				playText.setPosition(windowWidth / 2 - playText.getGlobalBounds().width / 2, 50.0f);
				playText.setColor(Color(255, 0, 0));
				window.draw(playText);
			}
			if (AI) {
				playText.setTexture(pcwonTexture);
				playText.setScale(0.8, 0.8f);
				playText.setPosition(windowWidth / 2 - playText.getGlobalBounds().width / 2, 50.0f);
				playText.setColor(Color(0, 0, 255));
				window.draw(playText);
			}
		}
	}
#pragma endregion

}

void TicTac::Hide(Sprite& sp) {
	sp.setColor(HiddenWhite);
}

void TicTac::Show(Sprite& sp) {
	sp.setColor(White);
}


void TicTac::playerMove() {
#pragma region turn texts
	if (currMove == X && currchosenMove == 'x' || currMove == O && currchosenMove == 'o') { // player 1
		playText.setTexture(p1turnTexture);
		playText.setScale(0.8f, 0.8f);
		playText.setPosition(windowWidth / 2 - playText.getGlobalBounds().width / 2, 50.0f);
		playText.setColor(Color(0, 255, 0));
		window.draw(playText);
	}
	else { // player 2
		playText.setTexture(p2turnTexture);
		playText.setScale(0.8f, 0.8f);
		playText.setPosition(windowWidth / 2 - playText.getGlobalBounds().width / 2, 50.0f);
		playText.setColor(Color(255, 0, 0));
		window.draw(playText);
	}
#pragma endregion

#pragma region input move
	clickTime = clickDelay.getElapsedTime();
	if (Mouse::isButtonPressed(Mouse::Left) && clickTime.asSeconds() >= 0.7) {
		Vector2f mousePos = getmousePos();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (squareSprite[i][j].getGlobalBounds().contains(mousePos.x, mousePos.y) && Grid[i][j] == '-') {
					if (currMove == X) {
						Grid[i][j] = 'x';
						XO[i][j].setTexture(xTexture);
						currMove = O;
					}
					else {
						Grid[i][j] = 'o';
						XO[i][j].setTexture(oTexture);
						currMove = X;
					}
					Show(XO[i][j]);
					clickDelay.restart();
					AIDelay.restart();
				}
			}
		}
		playSound.play();
	}
#pragma endregion
}

void TicTac::botMove() {
	Square toModify;
	Time time = AIDelay.getElapsedTime();
	if (time.asSeconds() >= 0.5) {
    #pragma region Easy
		if (currDifficulty == Easy) {
			bool found = false;

			for (int i = 0; i < 9; i++) {
				Square s{ prioritySquares[i][0], prioritySquares[i][1] };
				if (found)
					break;

				found = checkEmpty(s, toModify);
			}
		}
#pragma endregion
    #pragma region Medium
		else if (currDifficulty == Medium) {
			bool found = false;

			for (int i = 0; i < 8; i++) {
				if (found)
					break;
				Square s1 = { consecutiveSquares[i][0], consecutiveSquares[i][1] };
				Square s2 = { consecutiveSquares[i][2], consecutiveSquares[i][3] };
				Square s3 = { consecutiveSquares[i][4], consecutiveSquares[i][5] };
				found = checkMove(s1, s2, s3, opponentMove, toModify);
			}
			for (int i = 0; i < 8; i++) {
				if (found)
					break;
				Square s1 = { consecutiveSquares[i][0], consecutiveSquares[i][1] };
				Square s2 = { consecutiveSquares[i][2], consecutiveSquares[i][3] };
				Square s3 = { consecutiveSquares[i][4], consecutiveSquares[i][5] };
				found = checkMove(s1, s2, s3, currchosenMove, toModify);

			}

			for (int i = 0; i < 9; i++) {
				Square s{ prioritySquares[i][0], prioritySquares[i][1] };
				if (found)
					break;

				found = checkEmpty(s, toModify);
			}
		}
#pragma endregion
    #pragma region Hard

		else if (currDifficulty == Hard) {
			toModify = getbestMove(Grid);
		}
#pragma endregion
    #pragma region Change move

		if (!filledBoard(Grid)) {
			if (currMove == O)
				XO[toModify.x][toModify.y].setTexture(oTexture), Grid[toModify.x][toModify.y] = 'o', currMove = X;
			else
				XO[toModify.x][toModify.y].setTexture(xTexture), Grid[toModify.x][toModify.y] = 'x', currMove = O;
			Show(XO[toModify.x][toModify.y]);
			AIDelay.restart();
			playSound.play();
		}
#pragma endregion

	}
}


#pragma region Win checker
void TicTac::checkforWin() {
	for (int i = 0; i < 8; i++) {
		if (mode == WonMode)
			break;
		Square s1 = { consecutiveSquares[i][0], consecutiveSquares[i][1] };
		Square s2 = { consecutiveSquares[i][2], consecutiveSquares[i][3] };
		Square s3 = { consecutiveSquares[i][4], consecutiveSquares[i][5] };
		if (checkConsecutive(s1, s2, s3)) {
			mode = WonMode;
			squareSprite[s1.x][s1.y].setTexture(squarewinTexture);
			squareSprite[s2.x][s2.y].setTexture(squarewinTexture);
			squareSprite[s3.x][s3.y].setTexture(squarewinTexture);
			winner = Grid[s1.x][s1.y];
			if (winner == currchosenMove) {
				editPlayer(p1Name);
			}
			else if (winner == opponentMove && !AI)
				editPlayer(p2Name);
			saveFile();
		}
	}
}

bool TicTac::checkConsecutive(Square s1, Square s2, Square s3) {
	if (Grid[s1.x][s1.y] == Grid[s2.x][s2.y] && Grid[s2.x][s2.y] == Grid[s3.x][s3.y] && Grid[s1.x][s1.y] != '-')
		return true;
	return false;
}

#pragma endregion




void TicTac::loadMenu() {
#pragma region  Logo
	Show(logo);
	window.draw(logo);
#pragma endregion

#pragma region main menu buttons
	Time time = clickDelay.getElapsedTime();
	Vector2f mousePos = getmousePos();
	if (menuMode == MainMenuMode) {
		for (auto button : { playButton, quitButton, scoreButton, creditsButton }) { // to show buttons
			Show(button);
			if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				changeColor(button, Color(238, 73, 73));
			}
			window.draw(button);
		}
		Vector2f mousePos = getmousePos(); // Play Button
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
			if (playButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
				menuMode = ModeChooser, clickSound.play(), clickDelay.restart();
		}

		mousePos = getmousePos(); // Quit Button
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
			if (quitButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
				window.close(), clickSound.play(), clickDelay.restart();
		}

		mousePos = getmousePos(); // Credits Button
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
			if (creditsButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
				menuMode = CreditsMode, clickSound.play(), clickDelay.restart();
		}

		mousePos = getmousePos(); // Score Button
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
			if (scoreButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
				menuMode = scoreboardMode, clickSound.play(), clickDelay.restart();;
		}
	}
#pragma endregion

#pragma region choosing mode buttons
	time = clickDelay.getElapsedTime();
	if (menuMode == ModeChooser) { 
		for (auto button : { pcButton, versusButton }) {
			Show(button);
			if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				changeColor(button, Color(238, 73, 73));
			}
			window.draw(button);
		}
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) { // pc
			cout << time.asSeconds() << endl;
			if (pcButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
				menuMode = PCSet, clickDelay.restart(), clickSound.play();
			if (versusButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) // player vs player
				clickDelay.restart(), menuMode = VersusSet, AI = false, clickSound.play();
		}
	}
#pragma endregion

#pragma region credits mode
	if (menuMode == CreditsMode) {
		for (auto button : { Beshoy, Abdullah, Martino, Salah }) {
			Show(button);
			window.draw(button);
		}
	}
#pragma endregion

#pragma region set names 

	else if (menuMode == PCSet) {
		Text p1; // player 1 text
		p1.setFont(font);
		p1.setCharacterSize(40);
		p1.setString("Player 1:");
		p1.setPosition(logo.getPosition().x, logo.getPosition().y + logo.getGlobalBounds().height);
		window.draw(p1);

		p1TextBox.setPosition(logo.getPosition().x, p1.getPosition().y + p1.getGlobalBounds().height + 15);

		Text starter;
		starter.setFont(font);
		starter.setCharacterSize(40);
		starter.setString("Starts with:");
		starter.setPosition(logo.getPosition().x, p1TextBox.getPosition().y + p1TextBox.getGlobalBounds().height + 15);

		p1Play.setPosition(starter.getPosition().x + starter.getGlobalBounds().width + 10, p1TextBox.getPosition().y + p1TextBox.getGlobalBounds().height + 15);

		if (currchosenMove == 'x')
			p1Move.setTexture(xTexture);
		else
			p1Move.setTexture(oTexture);

		p1Move.setPosition(p1Play.getPosition().x + p1Play.getGlobalBounds().width / 2 - p1Move.getGlobalBounds().width / 2, p1Play.getPosition().y + p1Play.getGlobalBounds().height / 2 - p1Move.getGlobalBounds().height / 2);


		time = clickDelay.getElapsedTime();
		mousePos = getmousePos();
		if (Mouse::isButtonPressed(Mouse::Left) && p1TextBox.getGlobalBounds().contains(mousePos.x, mousePos.y) && time.asSeconds() >= 0.7) {
			textbox1On = true;
		}
		else if (Mouse::isButtonPressed(Mouse::Left))
			textbox1On = false, textbox2On = false;

		time = clickDelay.getElapsedTime();
		mousePos = getmousePos();
		if (Mouse::isButtonPressed(Mouse::Left) && p1Play.getGlobalBounds().contains(mousePos.x, mousePos.y) && time.asSeconds() >= 0.7) {
			if (currchosenMove == 'x')
				currchosenMove = 'o', p1Move.setTexture(oTexture), currMove = O, opponentMove = 'x';
			else
				currchosenMove = 'x', p1Move.setTexture(xTexture), currMove = X, opponentMove = 'o';
			clickDelay.restart();
		}

		if (currMove == O)
			p1Move.setTexture(oTexture);
		else
			p1Move.setTexture(xTexture);

		time = clickDelay.getElapsedTime();
		mousePos = getmousePos();

		Text p1nameText; // entered name
		p1nameText.setFont(font);
		p1nameText.setCharacterSize(35);
		p1nameText.setString(p1Name);
		p1nameText.setPosition(p1TextBox.getPosition().x + 5, p1TextBox.getPosition().y);

		Text goText;
		goText.setFont(font);
		goText.setCharacterSize(50);
		goText.setString("GO!!");
		goText.setPosition(windowWidth / 2 - goText.getGlobalBounds().width / 2, windowHeight - goText.getGlobalBounds().height - 20);

		if (goText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (p1Name.size() > 0) {
				goText.setFillColor(onclickColor);
				if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
					newGame();
					menuMode = DifficultiesMode;
					clickDelay.restart();

					if (!playerExists(p1Name))
						Players.push_back(Player{ 0, p1Name });
				}
			}
		}
		else
			goText.setFillColor(Color::White);


		window.draw(p1TextBox);

		window.draw(p1Play);
		window.draw(p1Move);

		window.draw(p1);
		window.draw(starter);

		window.draw(p1nameText);

		window.draw(goText);
	}
	else if (menuMode == VersusSet) {
		Text p1;
		p1.setFont(font);
		p1.setCharacterSize(40);
		p1.setString("Player 1:");
		p1.setPosition(logo.getPosition().x, logo.getPosition().y + logo.getGlobalBounds().height);
		window.draw(p1);

		p1TextBox.setPosition(logo.getPosition().x, p1.getPosition().y + p1.getGlobalBounds().height + 15);

		Text p2;
		p2.setFont(font);
		p2.setCharacterSize(40);
		p2.setString("Player 2:");
		p2.setPosition(logo.getPosition().x, p1TextBox.getPosition().y + p1TextBox.getGlobalBounds().height + 10);

		p2TextBox.setPosition(logo.getPosition().x, p2.getPosition().y + p2.getGlobalBounds().height + 15);

		Text p3;
		p3.setFont(font);
		p3.setCharacterSize(40);
		p3.setString("Starts with:");
		p3.setPosition(logo.getPosition().x, p2TextBox.getPosition().y + p2TextBox.getGlobalBounds().height + 15);


		p1Play.setPosition(p3.getPosition().x + p3.getGlobalBounds().width + 10, p2TextBox.getPosition().y + p2TextBox.getGlobalBounds().height + 15);

		if (currchosenMove == 'x')
			p1Move.setTexture(xTexture);
		else
			p1Move.setTexture(oTexture);
		p1Move.setPosition(p1Play.getPosition().x + p1Play.getGlobalBounds().width / 2 - p1Move.getGlobalBounds().width / 2, p1Play.getPosition().y + p1Play.getGlobalBounds().height / 2 - p1Move.getGlobalBounds().height / 2);




		time = clickDelay.getElapsedTime();
		mousePos = getmousePos();
		if (Mouse::isButtonPressed(Mouse::Left) && p1TextBox.getGlobalBounds().contains(mousePos.x, mousePos.y) && time.asSeconds() >= 0.7) {
			textbox1On = true;
		}
		else if (Mouse::isButtonPressed(Mouse::Left) && p2TextBox.getGlobalBounds().contains(mousePos.x, mousePos.y) && time.asSeconds() >= 0.7)
			textbox1On = false, textbox2On = true;
		else if (Mouse::isButtonPressed(Mouse::Left))
			textbox1On = false, textbox2On = false;



		Text p1nameText;
		p1nameText.setFont(font);
		p1nameText.setCharacterSize(35);
		p1nameText.setString(p1Name);
		p1nameText.setPosition(p1TextBox.getPosition().x + 5, p1TextBox.getPosition().y);

		Text p2nameText;
		p2nameText.setFont(font);
		p2nameText.setCharacterSize(35);
		p2nameText.setString(p2Name);
		p2nameText.setPosition(p2TextBox.getPosition().x + 5, p2TextBox.getPosition().y);

		Text goText;
		goText.setFont(font);
		goText.setCharacterSize(50);
		goText.setString("GO!!");
		goText.setPosition(windowWidth / 2 - goText.getGlobalBounds().width / 2, windowHeight - goText.getGlobalBounds().height - 20);

		time = clickDelay.getElapsedTime();
		mousePos = getmousePos();
		if (Mouse::isButtonPressed(Mouse::Left) && p1Play.getGlobalBounds().contains(mousePos.x, mousePos.y) && time.asSeconds() >= 0.7) {
			if (currchosenMove == 'x')
				currchosenMove = 'o', p1Move.setTexture(oTexture), currMove = O, opponentMove = 'x';
			else
				currchosenMove = 'x', p1Move.setTexture(xTexture), currMove = X, opponentMove = 'o';
			clickDelay.restart();
		}

		if (currMove == O)
			p1Move.setTexture(oTexture);
		else
			p1Move.setTexture(xTexture);

		time = clickDelay.getElapsedTime();
		mousePos = getmousePos();

		if (goText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (p1Name.size() > 0 && p2Name.size() > 0) {
				goText.setFillColor(onclickColor);
				if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
					newGame();
					menuMode = PlayMode;
					mode = VersusMode;
					clickDelay.restart();

					if (!playerExists(p1Name))
						Players.push_back(Player{ 0, p1Name });
					if (!playerExists(p2Name))
						Players.push_back(Player{ 0, p2Name });
				}
			}
		}
		else
			goText.setFillColor(Color::White);



		window.draw(p1TextBox);
		window.draw(p2TextBox);

		window.draw(p1Play);
		window.draw(p1Move);

		window.draw(p1);
		window.draw(p2);
		window.draw(p3);

		window.draw(p1nameText);
		window.draw(p2nameText);

		window.draw(goText);
	}
#pragma endregion

#pragma region choosing difficulties buttons
	else if (menuMode == DifficultiesMode) {
		for (auto button : { easyButton, mediumButton, hardButton }) {
			Show(button);
			if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				changeColor(button, Color(238, 73, 73));
			}
			window.draw(button);
		}
		if (Mouse::isButtonPressed(Mouse::Left) && time.asSeconds() >= 0.7) {
			if (easyButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				currDifficulty = Easy;
				mode = AIMode;
				newGame();
				clickDelay.restart();
				menuMode = PlayMode;
				AI = true;
				clickSound.play();
			}
			if (mediumButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				currDifficulty = Medium;
				mode = AIMode;
				newGame();
				clickDelay.restart();
				menuMode = PlayMode;
				AI = true;
				clickSound.play();
			}
			if (hardButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				currDifficulty = Hard;
				mode = AIMode;
				newGame();
				clickDelay.restart();
				menuMode = PlayMode;
				AI = true;
				clickSound.play();
			}
		}
	}
#pragma endregion

#pragma region Scoreboard
	else if (menuMode == scoreboardMode) {

		sort(Players.begin(), Players.end());

		Text winsText;
		winsText.setFont(font);
		winsText.setCharacterSize(40);
		winsText.setFillColor(onclickColor);
		winsText.setString("wins");
		winsText.setPosition(windowWidth - (winsText.getGlobalBounds().width * 1.5), logo.getPosition().y + logo.getGlobalBounds().height);


		Text nameText;
		nameText.setFont(font);
		nameText.setCharacterSize(40);
		nameText.setFillColor(onclickColor);
		nameText.setString("Name");
		nameText.setPosition((winsText.getPosition().x - winsText.getGlobalBounds().width / 2) / 3, logo.getPosition().y + logo.getGlobalBounds().height);

		for (int i = indexStarter; i < indexStarter + min(5, (int)Players.size()); i++) {
			Text playerName;
			playerName.setFont(font);
			playerName.setCharacterSize(40);
			playerName.setString(Players[i].playerName);
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

#pragma region score board files handling
void TicTac::saveFile() {
	string toWrite = to_string(Players.size());
	toWrite += "\n";
	for (int i = 0; i < Players.size(); i++) {
		toWrite += Players[i].playerName;
		toWrite += " ";
		toWrite += to_string(Players[i].wins);
		toWrite += "\n";
	}
	fileStream.open("Files\\ticScoreBoard.txt");
	fileStream << toWrite;
	fileStream.close();
}

void TicTac::loadScoreBoard() {
	if (!scoreboardLoaded) {
		fileStream.open("Files\\ticScoreBoard.txt");
		int count;
		fileStream >> count;
		for (int i = 0; i < count; i++) {
			int wins;
			string name;
			fileStream >> name >> wins;
			Players.push_back(Player{ wins, name });
		}
		fileStream.close();
		scoreboardLoaded = true;
	}
}
#pragma endregion

#pragma region Helping functions
void TicTac::newGame() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Grid[i][j] = '-';
			Hide(XO[i][j]);
			squareSprite[i][j].setTexture(squareTexture);
			Show(squareSprite[i][j]);
		}
	}
	if (currchosenMove == 'x')
		currMove = X;
	else
		currMove = O;
	Turn = 0;
}


void TicTac::changeColor(Sprite& s, Color c) {
	s.setColor(c);
}

void TicTac::editPlayer(string playerName) {
	for (int i = 0; i < Players.size(); i++) {
		if (Players[i].playerName == playerName)
			Players[i].wins++;
	}
}

bool TicTac::playerExists(string playerName) {
	for (int i = 0; i < Players.size(); i++)
		if (Players[i].playerName == playerName)
			return true;
	return false;
}



Vector2f TicTac::getmousePos() {
	Vector2i mousePos = Mouse::getPosition(window);
	return Vector2f((float)mousePos.x, (float)mousePos.y);
}

bool TicTac::filledBoard(char arr[3][3]) {
	bool filled = true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (arr[i][j] == '-')
				filled = false;
	return filled;
}
#pragma endregion

#pragma region AI
bool TicTac::virtualWin(char arr[3][3], char& vWinner) {
	for (int i = 0; i < 8; i++) {
		Square s1 = { consecutiveSquares[i][0], consecutiveSquares[i][1] };
		Square s2 = { consecutiveSquares[i][2], consecutiveSquares[i][3] };
		Square s3 = { consecutiveSquares[i][4], consecutiveSquares[i][5] };
		if (virtualConsecutive(arr, s1, s2, s3)) {
			vWinner = arr[s1.x][s1.y];
			return true;
		}
	}
	return false;
}

TicTac::Square TicTac::getbestMove(char arr[3][3]) {

	Square currbestmove = Square{ 5, 5 };
	int highestscore = -1000;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == '-') {
				arr[i][j] = opponentMove;
				int Score = minimax(arr, currchosenMove);
				arr[i][j] = '-';
				if (Score > highestscore) {
					highestscore = Score;
					currbestmove = Square{ i, j };
				}
			}
		}
	}
	return currbestmove;
}

int TicTac::minimax(char arr[3][3], char move) {
	int currentScore;
	char vWinner;
	if (virtualWin(arr, vWinner))
		if (vWinner == opponentMove)
			return 10;
		else
			return -10;
	if (filledBoard(arr))
		return 0;

	if (move == opponentMove) {
		int best = -1000;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] == '-') {
					arr[i][j] = opponentMove;
					best = max(best, minimax(arr, currchosenMove));
					arr[i][j] = '-';
				}
			}
		}
		return best;
	}
	else if (move == currchosenMove) {
		int best = 1000;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] == '-') {
					arr[i][j] = currchosenMove;
					best = min(best, minimax(arr, opponentMove));
					arr[i][j] = '-';
				}
			}
		}
		return best;
	}
}

bool TicTac::virtualConsecutive(char arr[3][3], Square s1, Square s2, Square s3) {
	if (arr[s1.x][s1.y] == arr[s2.x][s2.y] && arr[s2.x][s2.y] == arr[s3.x][s3.y] && arr[s1.x][s1.y] != '-')
		return true;
	return false;
}

bool TicTac::checkMove(Square s1, Square s2, Square s3, char move, Square& toModify) {
	if (Grid[s1.x][s1.y] == Grid[s2.x][s2.y] && Grid[s1.x][s1.y] == move && Grid[s3.x][s3.y] == '-') {
		toModify = s3;
		return true;
	}
	if (Grid[s1.x][s1.y] == Grid[s3.x][s3.y] && Grid[s1.x][s1.y] == move && Grid[s2.x][s2.y] == '-') {
		toModify = s2;
		return true;
	}
	if (Grid[s3.x][s3.y] == Grid[s2.x][s2.y] && Grid[s2.x][s2.y] == move && Grid[s1.x][s1.y] == '-') {
		toModify = s1;
		return true;
	}
	return false;
}

bool TicTac::checkEmpty(Square s, Square& toModify) {
	if (Grid[s.x][s.y] == '-') {
		toModify = s;
		return true;
	}
	return false;
}
#pragma endregion


