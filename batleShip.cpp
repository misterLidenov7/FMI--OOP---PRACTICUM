#include "BatleShip.hpp"
#include "jedi.hpp"
#include "stormtrooper.hpp"


template<class X>
 void BatleShip<X>::destroyShip() {
	delete[] this->size;
}

template<class X>
 void BatleShip<X>::copyShip(const BatleShip<X>& otherObj) {

	this->size = new char[strlen(otherObj.size) + 1];
	strcpy(this->size, otherObj.size);

	this->weapons = otherObj.weapons;
	this->hiperJump = otherObj.hiperJump;
	this->speed = otherObj.speed;
	this->pilot = otherObj.pilot;
}

template<class X>
BatleShip<X>::BatleShip(const BatleShip<X>& otherObj) {
	copyShip(otherObj);
}

template<class X>
BatleShip<X>::BatleShip() {

	this->size = new char[1];
	strcpy(this->size, "");

	this->weapons = 0;
	this->hiperJump = false;
	this->speed = 0;
	this->pilot.nameSetter("Anakin");
}

template<class X>
BatleShip<X>::BatleShip(const int weapons, const bool hiperJump, const  int speed, const char* size, const X pilot)
{
	this->size = new char[strlen(size) + 1];
	strcpy(this->size, size);

	this->weapons = weapons;
	this->hiperJump = hiperJump;
	this->speed = speed;
	this->pilot = pilot;
}

template<class X>
BatleShip<X>& BatleShip<X>::operator=(const BatleShip<X>& otherObj)
{
	if (this != &otherObj) {
		destroyShip();
		copyShip(otherObj);
	}
	return *this;
}

template<class X>
BatleShip<X>::~BatleShip() {
	destroyShip();
}

template<class X>
X BatleShip<X>::pilotGetter() const {
	return this->pilot;
}

template<class X>
void BatleShip<X>::pilotSetter(const X& pilot) {
	this->pilot = pilot;
}


template<class X>
bool BatleShip<X>::typeChecker() {
	return (typeid(X) == typeid(Jedi)) || (typeid(X) == typeid(Stormtrooper));
}

template<class T>
 std::ostream& operator<<(std::ostream& out, BatleShip<T> help) {

	out << "Ship" << std::endl;
	return out;
}


template<class X>
int BatleShip<X>::weaponsGetter() const{
	return this->weapons;
}

template<class X>
void BatleShip<X>::weaponsSetter(const int weapons){
	this->weapons = weapons;
}

template<class X>
bool BatleShip<X>::hiperJumpGetter() const{
	return this->hiperJump;
}

template<class X>
void BatleShip<X>::hiperJumpGetter(const bool hiperJump){
	this->hiperJump = hiperJump;
}

template<class X>
int BatleShip<X>::speedGetter() const {
	return this->speed;
}

template<class X>
void BatleShip<X>::speedSetter(const int speed){
	this->speed = speed;
}

template<class X>
char* BatleShip<X>::sizeGetter() const{
	return this->speed;
}

template<class X>
void BatleShip<X>::sizeSetter(const char* size){

	delete[] this->size;
	int len = strlen(size) + 1;
	this->size = new char[len];
	strcpy(this->size, size);
}
