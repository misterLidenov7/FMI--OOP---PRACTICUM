#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning(disable:4996)

template<typename P>
void planetPrinter(const P name) {
	std::cout << name;
}

enum class PlanetType {
	Undefined,
	Lava,
	Helium,
	Ocean
};

class Planet {

private:
	char* name;
	char* republic;
	char* systemPlanet;
	PlanetType type;

public:
	void copy(const Planet& otherObj);
	void destroy();

	Planet();
	Planet(const Planet& otherObj);
	Planet(const char* name, const char* republic, const char* systemPlanet, const PlanetType type);
	Planet& operator=(const Planet& otherObj);
	friend std::ostream& operator<<(std::ostream& out, const Planet& object);
	~Planet();

	char* nameGetter() const;
	void nameSetter(const char* name);

	char* republicGetter() const;
	void republicSetter(const char* republic);

	char* systemPlanetGetter() const;
	void systemPlanetSetter(const char* systemPlanet);

	PlanetType typeGetter() const;
	void typeSetter(const PlanetType& type);

	friend std::istream& operator>>(std::istream& input,  Planet& otherObj);


};
