#include "../../../../Include/Trambo/Utilities/utility.h"
#include "../../../../Include/Trambo/Animations/animation.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cassert>
#include <cmath>
#include <ctime>
#include <random>
#include <Windows.h>


namespace
{
	std::random_device	randomDevice;				// ALW - Obtain random number from hardware
	std::mt19937		generator(randomDevice());	// ALW - Seed the generator
} // anonymous namespace

namespace trmb
{

std::string toString(sf::Keyboard::Key key)
{
	#define KEYTOSTRING_CASE(KEY) case sf::Keyboard::KEY: return #KEY;

	switch (key)
	{
		KEYTOSTRING_CASE(Unknown)
		KEYTOSTRING_CASE(A)
		KEYTOSTRING_CASE(B)
		KEYTOSTRING_CASE(C)
		KEYTOSTRING_CASE(D)
		KEYTOSTRING_CASE(E)
		KEYTOSTRING_CASE(F)
		KEYTOSTRING_CASE(G)
		KEYTOSTRING_CASE(H)
		KEYTOSTRING_CASE(I)
		KEYTOSTRING_CASE(J)
		KEYTOSTRING_CASE(K)
		KEYTOSTRING_CASE(L)
		KEYTOSTRING_CASE(M)
		KEYTOSTRING_CASE(N)
		KEYTOSTRING_CASE(O)
		KEYTOSTRING_CASE(P)
		KEYTOSTRING_CASE(Q)
		KEYTOSTRING_CASE(R)
		KEYTOSTRING_CASE(S)
		KEYTOSTRING_CASE(T)
		KEYTOSTRING_CASE(U)
		KEYTOSTRING_CASE(V)
		KEYTOSTRING_CASE(W)
		KEYTOSTRING_CASE(X)
		KEYTOSTRING_CASE(Y)
		KEYTOSTRING_CASE(Z)
		KEYTOSTRING_CASE(Num0)
		KEYTOSTRING_CASE(Num1)
		KEYTOSTRING_CASE(Num2)
		KEYTOSTRING_CASE(Num3)
		KEYTOSTRING_CASE(Num4)
		KEYTOSTRING_CASE(Num5)
		KEYTOSTRING_CASE(Num6)
		KEYTOSTRING_CASE(Num7)
		KEYTOSTRING_CASE(Num8)
		KEYTOSTRING_CASE(Num9)
		KEYTOSTRING_CASE(Escape)
		KEYTOSTRING_CASE(LControl)
		KEYTOSTRING_CASE(LShift)
		KEYTOSTRING_CASE(LAlt)
		KEYTOSTRING_CASE(LSystem)
		KEYTOSTRING_CASE(RControl)
		KEYTOSTRING_CASE(RShift)
		KEYTOSTRING_CASE(RAlt)
		KEYTOSTRING_CASE(RSystem)
		KEYTOSTRING_CASE(Menu)
		KEYTOSTRING_CASE(LBracket)
		KEYTOSTRING_CASE(RBracket)
		KEYTOSTRING_CASE(SemiColon)
		KEYTOSTRING_CASE(Comma)
		KEYTOSTRING_CASE(Period)
		KEYTOSTRING_CASE(Quote)
		KEYTOSTRING_CASE(Slash)
		KEYTOSTRING_CASE(BackSlash)
		KEYTOSTRING_CASE(Tilde)
		KEYTOSTRING_CASE(Equal)
		KEYTOSTRING_CASE(Dash)
		KEYTOSTRING_CASE(Space)
		KEYTOSTRING_CASE(Return)
		KEYTOSTRING_CASE(BackSpace)
		KEYTOSTRING_CASE(Tab)
		KEYTOSTRING_CASE(PageUp)
		KEYTOSTRING_CASE(PageDown)
		KEYTOSTRING_CASE(End)
		KEYTOSTRING_CASE(Home)
		KEYTOSTRING_CASE(Insert)
		KEYTOSTRING_CASE(Delete)
		KEYTOSTRING_CASE(Add)
		KEYTOSTRING_CASE(Subtract)
		KEYTOSTRING_CASE(Multiply)
		KEYTOSTRING_CASE(Divide)
		KEYTOSTRING_CASE(Left)
		KEYTOSTRING_CASE(Right)
		KEYTOSTRING_CASE(Up)
		KEYTOSTRING_CASE(Down)
		KEYTOSTRING_CASE(Numpad0)
		KEYTOSTRING_CASE(Numpad1)
		KEYTOSTRING_CASE(Numpad2)
		KEYTOSTRING_CASE(Numpad3)
		KEYTOSTRING_CASE(Numpad4)
		KEYTOSTRING_CASE(Numpad5)
		KEYTOSTRING_CASE(Numpad6)
		KEYTOSTRING_CASE(Numpad7)
		KEYTOSTRING_CASE(Numpad8)
		KEYTOSTRING_CASE(Numpad9)
		KEYTOSTRING_CASE(F1)
		KEYTOSTRING_CASE(F2)
		KEYTOSTRING_CASE(F3)
		KEYTOSTRING_CASE(F4)
		KEYTOSTRING_CASE(F5)
		KEYTOSTRING_CASE(F6)
		KEYTOSTRING_CASE(F7)
		KEYTOSTRING_CASE(F8)
		KEYTOSTRING_CASE(F9)
		KEYTOSTRING_CASE(F10)
		KEYTOSTRING_CASE(F11)
		KEYTOSTRING_CASE(F12)
		KEYTOSTRING_CASE(F13)
		KEYTOSTRING_CASE(F14)
		KEYTOSTRING_CASE(F15)
		KEYTOSTRING_CASE(Pause)
	}

	return "";
}

std::string toString(sf::Mouse::Button button)
{
	switch (button)
	{
		case sf::Mouse::Button::Left:
			return "Mouse Left";
		case sf::Mouse::Button::Right:
			return "Mouse Right";
		case sf::Mouse::Button::Middle:
			return "Mouse Middle";
		case sf::Mouse::Button::XButton1:
			return "Mouse Extra One";
		case sf::Mouse::Button::XButton2:
			return "Mouse Extra Two";
		default:
			return "";
	}
}

void centerOrigin(sf::Sprite& sprite, bool centerXAxis, bool centerYAxis)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	float xAxis = 0.0f;
	float yAxis = 0.0f;

	if (centerXAxis)
		xAxis = std::floor(bounds.width / 2.0f);

	if (centerYAxis)
		yAxis = std::floor(bounds.height / 2.0f);

	sprite.setOrigin(xAxis, yAxis);
}

void centerOrigin(sf::Text& text, bool centerXAxis, bool centerYAxis)
{
	sf::FloatRect bounds = text.getLocalBounds();
	float xAxis = 0.0f;
	float yAxis = 0.0f;

	if (centerXAxis)
		xAxis = std::floor(bounds.left + bounds.width / 2.f);

	if (centerYAxis)
		yAxis = std::floor(bounds.top + bounds.height / 2.f);

	text.setOrigin(xAxis, yAxis);
}

void centerOrigin(sf::RectangleShape& rectangleShape, bool centerXAxis, bool centerYAxis)
{
	sf::FloatRect bounds = rectangleShape.getLocalBounds();
	float xAxis = 0.0f;
	float yAxis = 0.0f;

	if (centerXAxis)
		xAxis = std::floor(bounds.width / 2.0f);

	if (centerYAxis)
		yAxis = std::floor(bounds.height / 2.0f);

	rectangleShape.setOrigin(xAxis, yAxis);
}

void centerOrigin(Animation& animation, bool centerXAxis, bool centerYAxis)
{
	sf::FloatRect bounds = animation.getLocalBounds();
	float xAxis = 0.0f;
	float yAxis = 0.0f;

	if (centerXAxis)
		xAxis = std::floor(bounds.width / 2.0f);

	if (centerYAxis)
		yAxis = std::floor(bounds.height / 2.0f);

	animation.setOrigin(xAxis, yAxis);
}

float toDegree(float radian)
{
	return 180.f / 3.141592653589793238462643383f * radian;
}

float toRadian(float degree)
{
	return 3.141592653589793238462643383f / 180.f * degree;
}

int randomInt(int exclusiveMax)
{
	std::uniform_int_distribution<> distr(0, exclusiveMax - 1);
	return distr(generator);
}

float length(sf::Vector2f vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f unitVector(sf::Vector2f vector)
{
	assert(vector != sf::Vector2f(0.f, 0.f));
	return vector / length(vector);
}

bool isWindowFocused(const sf::RenderWindow &window)
{
	// ALW - Warning: code is not cross platform
	// ALW - A SFML window like any other window is not guarenteed to be opened with focus.  In SFML 2.1
	// ALW - there is no way to keep track of the focus state from the beginning. Only after the focus state
	// ALW - changes for the first time can it be tracked by the programmer.  This function allows for
	// ALW - direct querying.

	sf::WindowHandle handle = window.getSystemHandle();
	bool isFocus = handle == GetFocus();
	bool isForeground = handle == GetForegroundWindow();

	return isFocus && isForeground;
}

} // trmb namespace
