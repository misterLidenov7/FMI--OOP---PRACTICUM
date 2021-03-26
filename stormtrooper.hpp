#pragma once
#include <iostream>
#include <cstring>
#include "planet.hpp"
#pragma  warning(disable : 4996)

enum class Rank {
	Undefined, Sergeant, Commander, Enlisted
};

class Stormtrooper {

private:

	char* ID;
	char* type;
	Planet planet;
	Rank rank;

private:
	void destroyTrooper();
	void copyTrooper(const Stormtrooper& otherObj);

public:

	Stormtrooper();
	Stormtrooper(const Stormtrooper& otherObj);
	Stormtrooper(const char* ID, const char* type, const Rank rank, const Planet planet);
	Stormtrooper& operator=(const Stormtrooper& otherObj);
	~Stormtrooper();

	char* idGetter() const;
	void idSetter(const char* ID);

	char* typeGetter() const;
	void typeSetter(const char* type);

	Rank rankGetter() const;
	void rankSetter(const Rank rank);
	void planetSetter(const Planet planet);

	void print() const;

	friend std::ostream& operator<<(std::ostream& out, const Stormtrooper& otherObje);
	friend std::istream& operator>>(std::istream& input, const Stormtrooper& otherObj);

};