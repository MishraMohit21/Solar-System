#pragma once
#include "Planet.h"


class System
{

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode windowSize;
	std::string windowTitle;
	sf::ContextSettings settings;

	Planet Sun;


	void initVariables();
	void initWindow();
	

	void pollEvent();


public:

	System();
	~System();

	const bool isRunning() const;

	void Update();


	void Render();

};

