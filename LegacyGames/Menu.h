#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
using namespace std;

class Menu {
public: 
	Menu(RenderWindow& win);
	void OnWindow(int& game);
	void Open();
	void drawWindow();
private:
	void changeColor(Sprite& s, Color c);
	Vector2f getmousePos();


	RenderWindow& window;
	Texture ticTexture;
	RectangleShape line;
	bool lineDrawed = false, ticlogoDrawed = false, sudokologoDrawed = false, tictacfirst = false, sudokofirst = false;

	Clock lineDelay;

	Texture tictacLogoTexture, tictactextTexture, sudokulogoTexture, sudokutextTexture;
	Sprite tictacLogo, sudokoLogo, tictacText, sudokuText;

	float linescaler = 0.1, lineStarter = 1;
	float ticlogoscaleX = 0.0, ticlogoscaleY = 0.0;
	float sudokulogoscaleX = 0.0, sudokulogoscaleY = 0.0f;
};