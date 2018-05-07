#include<Menu.h>
using namespace std;
using namespace sf;

const int windowWidth = 1024, windowHeight = 700;


Menu::Menu(RenderWindow& win) : window(win) {

	tictacLogoTexture.loadFromFile("Images\\Menu\\tictac.png");
	sudokulogoTexture.loadFromFile("Images\\Menu\\sudoku.png");
	tictactextTexture.loadFromFile("Images\\Menu\\tictactext.png");
	sudokutextTexture.loadFromFile("Images\\Menu\\sudokutext.png");

	line.setSize(Vector2f(5, 0));
	line.setFillColor(Color::Black);
	line.setPosition(windowWidth / 2 - line.getGlobalBounds().width / 2, windowHeight / 2 - line.getGlobalBounds().height / 2);

	tictacLogo.setTexture(tictacLogoTexture);
	tictacLogo.scale(ticlogoscaleX, ticlogoscaleY);
	tictacLogo.setPosition(windowWidth / 4 - tictacLogo.getGlobalBounds().width / 2, windowHeight / 2 - tictacLogo.getGlobalBounds().height / 2);

	sudokoLogo.setTexture(sudokulogoTexture);
	sudokoLogo.scale(sudokulogoscaleX, sudokulogoscaleY);
	sudokoLogo.setPosition(((windowWidth / 2) + windowWidth / 4) - sudokoLogo.getGlobalBounds().width / 2, windowHeight / 2 - sudokoLogo.getGlobalBounds().height / 2);

	tictacText.setTexture(tictactextTexture);

	sudokuText.setTexture(sudokutextTexture);
}

void Menu::Open() {

}

void Menu::OnWindow(int& game) {
	window.clear(Color(255, 228, 181));
	
	if (line.getSize().y < 500) {
		lineStarter += linescaler;
		linescaler += 0.1;
		line.setSize(Vector2f(line.getSize().x, line.getSize().y + lineStarter));
		line.setPosition(windowWidth / 2 - line.getGlobalBounds().width / 2, windowHeight / 2 - line.getGlobalBounds().height / 2);
		lineDelay.restart();
	}
	else {
		lineDrawed = true;
	}

	if (lineDrawed) {
		if (ticlogoscaleX <= 0.8f && ticlogoscaleY <= 0.8f) {
			tictacLogo.setScale(ticlogoscaleX, ticlogoscaleY);
			tictacLogo.setPosition(windowWidth / 4 - tictacLogo.getGlobalBounds().width / 2, windowHeight / 2 - tictacLogo.getGlobalBounds().height / 2);
			ticlogoscaleX += 0.1;
			ticlogoscaleY += 0.1;
		}
		else {
			ticlogoDrawed = true;
			tictacText.setScale(0.7f, 0.8f);
			tictacText.setPosition((tictacLogo.getPosition().x + tictacLogo.getGlobalBounds().width / 2) - tictacText.getGlobalBounds().width / 2,
				tictacLogo.getPosition().y + tictacLogo.getGlobalBounds().height);
		}
	}


	if (ticlogoDrawed) {
		if (sudokulogoscaleX <= 1.1 && sudokulogoscaleY <= 1.1) {
			sudokoLogo.setScale(sudokulogoscaleX, sudokulogoscaleY);
			sudokoLogo.setPosition(((windowWidth / 2) + windowWidth / 4) - sudokoLogo.getGlobalBounds().width / 2, windowHeight / 2 - sudokoLogo.getGlobalBounds().height / 2);
			sudokulogoscaleX += 0.1;
			sudokulogoscaleY += 0.1;
		}

		else {
			sudokologoDrawed = true;
			sudokuText.setScale(0.8f, 0.8f);
			sudokuText.setPosition((sudokoLogo.getPosition().x + sudokoLogo.getGlobalBounds().width / 2) - sudokuText.getGlobalBounds().width / 2,
				sudokoLogo.getPosition().y + sudokoLogo.getGlobalBounds().height);
		}
	}
	if (ticlogoDrawed) {
		Vector2f mousePos = getmousePos();
		
		if (tictacText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			changeColor(tictacText, Color(238, 73, 73));
			if (Mouse::isButtonPressed(Mouse::Left)) {
				window.create(VideoMode(500, 700), "tic tac toe!");
				game = 2;
			}
		}
		else
			changeColor(tictacText, Color::White);
		window.draw(tictacText);
	}
	if (sudokologoDrawed) {
		Vector2f mousePos = getmousePos();

		if (sudokuText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			changeColor(sudokuText, Color(238, 73, 73));
			if (Mouse::isButtonPressed(Mouse::Left)) {
				window.create(VideoMode(500, 700), "Sodoku!");
				game = 1;
			}

		}
		else
			changeColor(sudokuText, Color::White);
		window.draw(sudokuText);
	}
	window.draw(line);
	window.draw(tictacLogo);
	window.draw(sudokoLogo);
}

void Menu::drawWindow() {
}

void Menu::changeColor(Sprite& s, Color c) {
	s.setColor(c);
}

Vector2f Menu::getmousePos() {
	Vector2i mousePos = Mouse::getPosition(window);
	return Vector2f((float)mousePos.x, (float)mousePos.y);
}