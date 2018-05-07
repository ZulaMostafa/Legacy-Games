#include <SFML/Graphics.hpp>
#include<TicTac.h>
#include<Menu.h>
#include<Soduko.h>
#include<iostream>

using namespace sf;
using namespace std;

enum GameState { menuState, tictacState, SodokuState };
GameState currentState = menuState;

int main()
{
	RenderWindow window(VideoMode(1024, 700), "Legacy Games!");

	TicTac tictac(window);
	Menu menu(window);
	Sodoku sodoku(window);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::TextEntered)
			{
				if (((char)(event.text.unicode) >= 'a' && (char)(event.text.unicode) <= 'z') ||
					((char)(event.text.unicode) >= 'A' && (char)(event.text.unicode) <= 'Z')) {
					if (tictac.textbox1On)
						tictac.p1Name = tictac.p1Name + (char)(event.text.unicode);
					else if (tictac.textbox2On)
						tictac.p2Name = tictac.p2Name + (char)(event.text.unicode);
					if (sodoku.istextboxON)
						sodoku.playerName = sodoku.playerName + (char)(event.text.unicode);
				}
				else if ((char)(event.text.unicode) >= '1' && (char)(event.text.unicode) <= '9') {
					if (sodoku.squareclicked) {
						sodoku.Board[sodoku.clickedSquare.x][sodoku.clickedSquare.y] = ((char)event.text.unicode) - '0';
					}
				}
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::BackSpace) {
					if (tictac.textbox1On && tictac.p1Name.size() > 0)
						tictac.p1Name.erase(tictac.p1Name.size() - 1, 1);
					else if (tictac.textbox2On && tictac.p2Name.size() > 0)
						tictac.p2Name.erase(tictac.p2Name.size() - 1, 1);
					if (sodoku.playerName.size() > 0 && sodoku.istextboxON)
						sodoku.playerName.pop_back();
				}
			}
			if (event.type == Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta > 0) {
					if (tictac.indexStarter - 1 >= 0)
						tictac.indexStarter--;
				}
				else
					if (tictac.indexStarter + 5 < tictac.Players.size())
						tictac.indexStarter++;

				if (sodoku.CurrMode == sodoku.ScoreBoard) {
					if (event.mouseWheelScroll.delta > 0) {
						if (sodoku.indexStarter - 1 >= 0)
							sodoku.indexStarter--;
					}
					else
						if (sodoku.indexStarter + 5 < tictac.Players.size())
							sodoku.indexStarter++;
				}
			}
		}



		int game = 0;
		bool tictacMenu = false, sodokumenu = false;
		if (currentState == tictacState)
			tictac.OnGame(tictacMenu);
		else if (currentState == menuState)
			menu.OnWindow(game);
		else if (currentState == SodokuState)
			sodoku.whilePlaying(sodokumenu);

		if (game == 1)
			currentState = SodokuState;
		else if (game == 2)
			currentState = tictacState;
		if (tictacMenu)
			currentState = menuState;
		if (sodokumenu)
			currentState = menuState;
		window.display();
		//window.clear();
	}

	return 0;
}