#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>
#include <ctime>
#include <cmath>

constexpr double PI = 3.14159265358;

class Planet : public sf::CircleShape
{
	float radius, angle, distance, orbitspeed;
	int Total;
	float x, y;
	sf::Transform Rotate;

	void initShape();
	Planet* planets;

	// Baki Planet ke liye

	double mapValue(double value, double inputMin, double inputMax, double outputMin, double outputMax);

	void updatePosition(Planet& body, const Planet& center);


public:

	void initVariables(float r, float d, float o);
	const float getRadius() const;

	void spawnMoon(int total, int level);


	void PlanetUpdate(const Planet& center);


	void RenderPlanet(sf::RenderWindow* window);

};