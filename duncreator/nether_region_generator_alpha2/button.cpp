#include"button.h"

Button::Button(sf::Vector2i _position, std::string _text) :
	position(_position),
	text(_text),
	fontName("fonts/IMMORTAL.ttf"),
	yPos(0)
{
	myText.setString(text);
}

Button::Button(const float _yPos, std::string _text, int SCRWIDTH, int SCRHEIGHT) :
	text(_text),
	fontName("fonts/IMMORTAL.ttf"),
	yPos(_yPos)
{
	int fontSize = 32;
	sf::Font font;
	font.loadFromFile(fontName);
	myText.setFont(font);
	myText.setString(text);
	myText.setCharacterSize(fontSize);
	myText.setPosition(sf::Vector2f(0, 0));
	sf::FloatRect textRect = myText.getLocalBounds();
	position.x = SCRWIDTH / 2 - text.length() / 2 * fontSize - 10;
	position.y = SCRHEIGHT * yPos - fontSize / 2 - 3;
	
	size.x = text.length() * fontSize + 20;
	size.y = fontSize + 23;
	end.x = position.x + size.x;
	end.y = position.y + size.y;
}

sf::Vector2i Button::getPosition() const noexcept
{
	return position;
}

sf::Vector2i Button::getEnd() const noexcept
{
	return end;
}

void Button::draw(sf::RenderWindow& window)
{
	sf::RectangleShape contour;
	contour.setSize(sf::Vector2f(size));
	contour.setFillColor(sf::Color::Black);
	contour.setOutlineColor(sf::Color::Red);
	contour.setOutlineThickness(2);

	sf::Font font;
	font.loadFromFile(fontName);
	myText.setFont(font);
	myText.setFillColor(sf::Color::Red);

	if (yPos != 0)
	{
		const int SCRWIDTH = sf::VideoMode::getDesktopMode().width;
		const int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
		sf::FloatRect textRect = myText.getLocalBounds();
		myText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		myText.setPosition(sf::Vector2f(SCRWIDTH / 2.0f, SCRHEIGHT * yPos));
		contour.setOrigin(myText.getOrigin());
		contour.setPosition(sf::Vector2f(SCRWIDTH / 2.0f - 10, SCRHEIGHT * yPos - 3));
		contour.setSize(sf::Vector2f(textRect.width + 20, textRect.height + 23));

		position.x = contour.getPosition().x - (contour.getSize().x / 2 - 10);
		position.y = contour.getPosition().y - (contour.getSize().y / 2 - 3);
		end.x = position.x + contour.getSize().x;
		end.y = position.y + contour.getSize().y;
	}
	else
	{
		const int SCRWIDTH = sf::VideoMode::getDesktopMode().width;
		const int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
		sf::FloatRect textRect = myText.getLocalBounds();
		myText.setPosition(sf::Vector2f(position));
		contour.setOrigin(myText.getOrigin());
		contour.setPosition(sf::Vector2f(position.x - 10, position.y + 3));
		sf::Vector2f contourSize (textRect.width, textRect.height);
		contour.setSize(sf::Vector2f(contourSize.x + 20, contourSize.y + 10));

		position = sf::Vector2i(contour.getPosition());
		size = sf::Vector2i(contour.getSize());
		end.x = position.x + size.x;
		end.y = position.y + size.y;

	}

	window.draw(contour);
	window.draw(myText);
}

bool Button::isClicked(sf::Vector2f mouse) const noexcept
{
	if (mouse.x > position.x && mouse.x < end.x)
	{
		if (mouse.y > position.y && mouse.y < end.y)
			return true;
	}
	return false;
}
