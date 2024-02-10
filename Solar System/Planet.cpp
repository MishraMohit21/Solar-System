#include "Planet.h"


void Planet::initShape()
{
	//this->setOrigin(this->radius, this->radius);
	this->setRadius(this->radius);
	this->setFillColor(sf::Color(255, 255, 255, 255));
	this->setOutlineColor(sf::Color::White);
	this->setOutlineThickness(0.75f);
	//this->setRotation(this->angle);

}

void Planet::initVariables(float r, float d, float o)
{
	this->radius = 2 * r;
	this->distance = d;
	this->orbitspeed = o;
	this->angle = (rand() % 360) * (PI/180);
	this->initShape();/*
	x = this->distance * cos(this->angle);
	y = this->distance * sin(this->angle);
	this->setPosition(sf::Vector2f(0 - this->getRadius() , 0 - this->getRadius()));*/

	
}

double Planet::mapValue(double value, double inputMin, double inputMax, double outputMin, double outputMax)
{
	return (value - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
}

void Planet::spawnMoon(int total, int level)
{
	this->Total = total;

	planets = new Planet[total];

	//planets = (Planet*)malloc(sizeof(Planet) * total);

	for (int i = 0; i < total; i++)
	{
		float r = this->radius * 0.25;
		float d = this->mapValue(rand() % 100, 0, 100, (this->radius + r) * 5, (this->radius + r) * 8);//(rand() % 200 - 100 + 1) + 100;
		float o = this->mapValue(d, (this->radius + r) * 4, (this->radius + r) * 8, -0.025f, 0.025f);
		planets[i].initVariables(r, d / level, o);
		this->setPosition(this->getPosition() + sf::Vector2f(this->distance, this->distance));


		if (level < 2)
		{
			//int moon = rand() % 3;
			planets[i].spawnMoon(2, level + 1);
		}
	}
}


void Planet::updatePosition(Planet& body, const Planet& center)
{
	float x = center.getPosition().x + center.getRadius() + body.distance * std::cos(body.angle);
	float y = center.getPosition().y + center.getRadius() + body.distance * std::sin(body.angle);

	body.setPosition(x - body.getRadius(), y - body.getRadius());
}


const float Planet::getRadius() const
{
	return this->radius;
}

void Planet::RenderPlanet(sf::RenderWindow* window)
{
	
	this->angle += this->orbitspeed;

	window->draw(*this);
	if (planets != NULL)
	{
		for (int i = 0; i < this->Total; i++)
		{
			this->planets[i].RenderPlanet(window);
		}
	}
}



void Planet::PlanetUpdate(const Planet& center)
{

	this->updatePosition(*this, center);

	if (planets != NULL)
	{
		for (int i = 0; i < this->Total; i++)
		{
			this->planets[i].PlanetUpdate(*this);
		}
	}


}