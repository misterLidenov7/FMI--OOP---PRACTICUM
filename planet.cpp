#include "planet.hpp"

void Planet::copy(const Planet& otherObj) {

	this->name = new char[strlen(otherObj.name) + 1];
	strcpy(this->name, otherObj.name);

	this->republic = new char[strlen(otherObj.republic) + 1];
	strcpy(this->republic, otherObj.republic);

	this->systemPlanet = new char[strlen(otherObj.systemPlanet) + 1];
	strcpy(this->systemPlanet, otherObj.systemPlanet);

	this->type = otherObj.type;
}

void Planet::destroy() {

	delete[] this->name;
	delete[] this->republic;
	delete[] this->systemPlanet;
}

Planet::Planet() {

	this->name = new char[1];
	strcpy(this->name, "");

	this->republic = new char[1];
	strcpy(this->republic, "");

	this->systemPlanet = new char[1];
	strcpy(this->systemPlanet, "");

	this->type = PlanetType::Undefined;
}

Planet::Planet(const Planet& otherObj) {
	copy(otherObj);
}

Planet::Planet(const char* name, const char* republic, const char* systemPlanet, const PlanetType type) {

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->republic = new char[strlen(republic) + 1];
	strcpy(this->republic, republic);

	this->systemPlanet = new char[strlen(systemPlanet) + 1];
	strcpy(this->systemPlanet, systemPlanet);

	this->type = type;
}

Planet& Planet::operator=(const Planet& otherObj) {

	if (this != &otherObj) {
		destroy();
		copy(otherObj);
	}
	return *this;
}

Planet::~Planet() {
	destroy();
}

char* Planet::nameGetter() const {
	return this->name;
}

void Planet::nameSetter(const char* name) {

	if (this->name != "") {

		delete[] this->name;
		int len1 = strlen(name) + 1;
		this->name = new char[len1];
		strcpy(this->name, name);
	}
}

char* Planet::republicGetter() const {
	return this->republic;
}

void Planet::republicSetter(const char* republic) {

	if (this->republic != "") {
		delete[] this->republic;
		int len2 = strlen(republic) + 1;
		this->republic = new char[len2];
		strcpy(this->republic, republic);
	}
}

char* Planet::systemPlanetGetter() const {
	return this->systemPlanet;
}

void Planet::systemPlanetSetter(const char* systemPlanet) {

	if (this->systemPlanet != "") {
		delete[] this->systemPlanet;
		int len3 = strlen(systemPlanet) + 1;
		this->systemPlanet = new char[len3];
		strcpy(this->systemPlanet, systemPlanet);
	}
}

PlanetType Planet::typeGetter() const {
	return this->type;
}

void Planet::typeSetter(const PlanetType& type) {
	this->type = type;
}

std::ostream& operator<<(std::ostream& out, const Planet& object) {

	out << "|---------------PLANET--------------|" << std::endl;
	out << "| Name : " << object.nameGetter() << std::endl;
	out << "| Republic : " << object.republicGetter() << std::endl;
	out << "| System Planet : " << object.systemPlanetGetter() << std::endl;
	out << "| Type : ";

	switch (object.type) {

	case PlanetType::Undefined: out << "Undefined\n";
		break;
	case PlanetType::Lava:out << "Lava\n";
		break;
	case PlanetType::Ocean: out << "Ocean\n";
		break;
	case PlanetType::Helium: out << "Helium\n";
		break;
	default:
		out << "???????\n";
	}
	out << "|-----------------------------------|\n";
	return out;
}

std::istream& operator>>(std::istream& input,  Planet& otherObj){

	char* cont = new char[47];

	delete[] otherObj.name;
	delete[] otherObj.republic;
	delete[] otherObj.systemPlanet;

	std::cout << "| Name : ";
	input.getline(cont, 47);
	otherObj.name = new char[strlen(cont) + 1];
	strcpy(otherObj.name, cont);
	delete[] cont;

	std::cout << "| Republic : ";
	input.getline(cont, 47);
	otherObj.republic = new char[strlen(cont) + 1];
	strcpy(otherObj.republic, cont);
	delete[] cont;

	std::cout << "| System Planet : ";
	input.getline(cont, 47);
	otherObj.systemPlanet = new char[strlen(cont) + 1];
	strcpy(otherObj.systemPlanet, cont);
	delete[] cont;

	return input;
}
