#pragma once
#include <iostream>
#include <cstring>
#include <typeinfo>
#include "jedi.hpp"
#include "stormtrooper.hpp"
#include "BatleShip.cpp"

#pragma warning(disable:4996)

template<class X=Jedi>
class BatleShip {

private:
	int weapons;
	bool hiperJump;
	 int speed;
	char* size;
	X pilot;

private:
	void destroyShip();
	void copyShip(const BatleShip<X>& otherObj);

public:

	BatleShip();
	BatleShip(const BatleShip<X>& otherObj);
	BatleShip(const int weapons,const bool hiperJump, const  int speed, const char* size, const X pilot);
	BatleShip<X>& operator=(const BatleShip<X>& otherObj);
	~BatleShip();

	int weaponsGetter() const;
	void weaponsSetter(const int weapons);

	bool hiperJumpGetter() const;
	void hiperJumpGetter(const bool hiperJump);

	 int speedGetter() const;
	void speedSetter(const  int speed);

	char* sizeGetter() const;
	void sizeSetter(const char* size);

	X pilotGetter() const;
	void pilotSetter(const X& pilot);

	bool typeChecker();

	template<class T>
	friend std::ostream& operator<<(std::ostream&, BatleShip<T>);
};

