#include<SFML\Graphics.hpp>
#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
using namespace sf;

class Sodoku {
private:
	RenderWindow& window;
	enum Difficluties { EasyMode, MediumMode, HardMode};
	void LoadMenu(bool& menu);
	Difficluties CurrDiff;

	Texture beshoyTexture, martinoTexture, abdullahTexture, salahTexture;
	Sprite Beshoy, Martino, Abdullah, Salah;

	Texture backbuttonTexture;
	Sprite backButton;

	Texture soundbuttonTexture, muteuttonTexture;
	Sprite soundButton;

	Texture playbuttonTexture;
	Sprite playButton;

	Texture quitbuttonTexture;
	Sprite quitButton;

	Texture scorebuttonTexture;
	Sprite scoreButton;

	Texture creditsbuttonTexture;
	Sprite creditsButton;

	Texture logoTexture;
	Sprite logo;

	Texture textboxTexture;
	Sprite nameTextBox;

	Texture easybuttonTexture, mediumbuttonTexture, hardbuttonTexture;
	Sprite easyButton, mediumButton, hardButton;

	Texture squareTexture;
	Texture squareclickedTexture;
	Sprite squareSprites[9][9];
	Text numberTexts[9][9];

	Vector2f getmousePos();

	Clock clickDelay;
	Time elapsedclickDelay;

	Font font;

	fstream fileStream;
	vector<vector<vector<int>>> templates;
	vector<vector<vector<int>>> solutions;
	void Loadtemplates();
	void loadrandomTemplate();

	int index;
	
	void checkCurrent();

	struct Player {
		string name;
		int wins;
		bool operator < (const Player &P2) const
		{
			return wins > P2.wins;
		}
	};
	vector<Player> Players;
	void loadscoreBoard();
	void savescoreBoard();
	void editPlayer(string playerName);
	bool playerExists(string playerName);


public:
	Sodoku(RenderWindow& win);
	void whilePlaying(bool& menu);

	bool istextboxON = false;

	string playerName = "";

	struct Square { int x, y; };
	Square clickedSquare;
	bool squareclicked = false;

	int Board[9][9];
	int indexStarter = 0;

	enum GameState { MainMenuMode, CreditsMode, ScoreBoard, PlayMode, DifficlutiesChooser, setName };
	GameState CurrMode = MainMenuMode;
};