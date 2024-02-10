#include "System.h"

void System::initVariables()
{
	this->windowSize = { 860, 840 };
	this->windowTitle = "Solar System";
	this->settings.antialiasingLevel = 8;
	
	this->Sun.initVariables(80, 0, 0);
	this->Sun.spawnMoon(5, 1);
	//this->Sun./*setPosition(sf::Vector2f(0 - this->Sun.getRadius(), 0 - this->Sun.getRadius()));*/
}

void System::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), this->windowTitle, sf::Style::Close | sf::Style::Titlebar, this->settings);
	sf::View CenterView(sf::Vector2f(0, 0), sf::Vector2f(4 * this->window->getSize().x, 4 * this->window->getSize().y));
	this->window->setView(CenterView);

	this->window->setVerticalSyncEnabled(true);
	//glEnable(GL_DEPTH_TEST);
	//this->window->setFramerateLimit(3);
}

void System::pollEvent()
{

	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();

		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
		}
	}
}

System::System()
{
	this->initVariables();
	this->initWindow();
}

System::~System()
{
	delete this->window;
}

const bool System::isRunning() const
{
	return this->window->isOpen();
}

void System::Update()
{
	this->pollEvent();

	Sun.PlanetUpdate(Sun);
}

void System::Render()
{
	this->window->clear();

	Sun.RenderPlanet(this->window);

	this->window->display();
}




