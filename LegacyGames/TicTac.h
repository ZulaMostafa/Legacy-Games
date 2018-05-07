#include <SFML/Graphics.hpp>
#include<time.h>
#include<SFML/Audio.hpp>
#include<vector>
#include<fstream>
#include<string>
using namespace sf;
using namespace std;
class TicTac {
private:
	RenderWindow& window;

	void botMove();
	void playerMove();
	void newGame();
	void Hide(Sprite& sp);
	void Show(Sprite& sp);
	void checkforWin();
	void loadMenu();
	void changeColor(Sprite& s, Color c);

	Texture squareTexture;
	Texture squarewinTexture;
	Sprite squareSprite[3][3];

	Texture oTexture;
	Texture xTexture;
	Sprite XO[3][3];

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

	Texture easybuttonTexture, mediumbuttonTexture, hardbuttonTexture;
	Sprite easyButton, mediumButton, hardButton;

	Texture versusbuttonTexture, pcbuttonTexture;
	Sprite versusButton, pcButton;

	Texture backbuttonTexture;
	Sprite backButton;

	Texture p1wonTexture, p2wonTexture, p1turnTexture, p2turnTexture, pcwonTexture;
	Sprite playText;

	Texture menubuttonTexture;
	Sprite menuButton;

	Texture retrybuttonTexture;
	Sprite retryButton;

	Texture soundbuttonTexture, muteuttonTexture;
	Sprite soundButton;

	Texture beshoyTexture, martinoTexture, abdullahTexture, salahTexture;
	Sprite Beshoy, Martino, Abdullah, Salah;

	Texture textboxTexture;
	Sprite p1TextBox, p2TextBox, p1Play, p1Move;

	enum CurrentMove { X, O };
	CurrentMove currMove = X;

	enum Modes { VersusMode, AIMode, WonMode, MenuMode };
	Modes mode = VersusMode;

	enum MenuModes{ MainMenuMode, DifficultiesMode, OptionsMode, CreditsMode, ModeChooser, PlayMode, scoreboardMode, VersusSet, PCSet};
	MenuModes menuMode = MainMenuMode;

	enum GameDifficulties {Easy, Medium, Hard};
	GameDifficulties currDifficulty = Easy;

	int Turn = 0;
	
	bool soundOn = true;
	
	char Grid[3][3];

	Vector2f getmousePos();
	
	Clock clickDelay, soundbuttonDelay;
	Time clickTime;

	Clock AIDelay;
	Time AITime;

	SoundBuffer backgroundsoundBuffer, clicksoundBuffer, playsoundBuffer;
	Sound backgoundSound, clickSound, playSound;

	struct Square { int x, y; };

	int consecutiveSquares[8][6]{
		{0, 0, 1, 0, 2, 0},
		{0, 1, 1, 1, 2, 1},
		{0, 2, 1, 2, 2, 2},

		{0, 0, 0, 1, 0, 2},
		{1, 0, 1, 1, 1, 2},
		{2, 0, 2, 1, 2, 2},

		{0, 0, 1, 1, 2, 2},
		{2, 0, 1, 1, 0, 2}
	};
	int prioritySquares[9][2]{
		{1, 1}, // middle

		{0, 0},
		{2, 0},
		{0, 2}, //corners
		{2, 2},

		{1, 0},
		{0, 1},  
		{2, 1},
		{1, 2}
	};
	char winner;
	bool AI = false;
	bool checkConsecutive(Square s1, Square s2, Square s3);
	bool checkMove(Square s1, Square s2, Square s3, char move, Square& toModify);
	bool checkEmpty(Square s, Square& toModify);

	struct Player {
		int wins;
		string playerName;
		bool operator < (const Player &P2) const
		{
			return wins > P2.wins;
		}
	};
	Font font;
	fstream fileStream;
	bool scoreboardLoaded = false;
	void loadScoreBoard();
	void saveFile();
	bool Compare(const Player& p1, const Player& p2);

	char currchosenMove = 'x', opponentMove = 'o';

	void editPlayer(string playerName);
	bool playerExists(string playerName);

	int minimax(char arr[3][3], char move);
	bool virtualWin(char arr[3][3], char& vWinner);
	bool TicTac::virtualConsecutive(char arr[3][3], Square s1, Square s2, Square s3);
	bool filledBoard(char arr[3][3]);
	Square getbestMove(char arr[3][3]);

public:
	TicTac(RenderWindow& win);
	void OnGame(bool& menu);
	bool textbox1On = false, textbox2On = false;
	string p1Name = "", p2Name = "";
	int indexStarter = 0;
	vector<Player> Players;
};
