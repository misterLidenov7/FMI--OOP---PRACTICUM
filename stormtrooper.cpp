#include "stormtrooper.hpp"
#include "planet.hpp"
//#include "planet.cpp"

void Stormtrooper::destroyTrooper() {
	delete[] this->ID;
	delete[] this->type;
}

void Stormtrooper::copyTrooper(const Stormtrooper& otherObj) {

	this->ID = new char[strlen(otherObj.ID) + 1];
	strcpy(this->ID, otherObj.ID);

	this->type = new char[strlen(otherObj.type) + 1];
	strcpy(this->type, otherObj.type);

	this->rank = otherObj.rank;
	this->planet = otherObj.planet;
}

Stormtrooper::Stormtrooper() {

	this->ID = new char[1];
	strcpy(this->ID, "");

	this->type = new char[1];
	strcpy(this->type, "");

	this->rank = Rank::Undefined;
	this->planet.nameSetter("Nibiru");

}

Stormtrooper::Stormtrooper(const Stormtrooper& otherObj) {
	copyTrooper(otherObj);
}

Stormtrooper::Stormtrooper(const char* ID, const char* type, const Rank rank, const Planet planet) {

	this->ID = new char[strlen(ID) + 1];
	strcpy(this->ID, ID);

	this->type = new char[strlen(type) + 1];
	strcpy(this->type, type);

	this->rank = rank;
	this->planet = planet;
}

Stormtrooper& Stormtrooper::operator=(const Stormtrooper& otherObj) {
	if (this != &otherObj) {
		destroyTrooper();
		copyTrooper(otherObj);
	}
	return *this;
}

Stormtrooper::~Stormtrooper() {
	destroyTrooper();
}

char* Stormtrooper::idGetter() const {
	return this->ID;
}

void Stormtrooper::idSetter(const char* ID) {

	delete[] this->ID;
	this->ID = new char[strlen(ID) + 1];
	strcpy(this->ID, ID);
}

char* Stormtrooper::typeGetter() const {
	return this->type;
}

void Stormtrooper::typeSetter(const char* type) {

	delete[] this->type;
	this->type = new char[strlen(type) + 1];
	strcpy(this->type, type);
}

Rank Stormtrooper::rankGetter() const {
	return this->rank;
}

void Stormtrooper::rankSetter(const Rank rank) {
	this->rank = rank;
}

void Stormtrooper::planetSetter(const Planet planet) {
	this->planet = planet;
}

void Stormtrooper::print() const {

	std::cout << "|----------STORMTROOPER-------------|\n";
	std::cout << "| ID : " << idGetter() << std::endl;
	std::cout << "| Type : " << typeGetter() << std::endl;
	std::cout << "| Rank : ";
	
	switch (rank)
	{
	case Rank::Undefined: std::cout << "Undefined\n";
		break;
	case Rank::Sergeant:std::cout << "Sergeant\n";
		break;
	case Rank::Commander:std::cout << "Comander\n";
		break;
	case Rank::Enlisted:std::cout << "Enlisted\n";
		break;
	default:
		std::cout << "?????????\n";
		break;
	}
	std::cout << "| Planet : ";
	planetPrinter<const char*>(this->planet.nameGetter());
		std::cout << "\n|-----------------------------------|\n";

}

std::ostream& operator<<(std::ostream& out, const Stormtrooper& otherObje)
{
	//throw gcnew System::NotImplementedException();
	
	out << "|----------STORMTROOPER-------------|\n";
	out << "| ID : " << otherObje.idGetter() << std::endl;
	out << "| Type : " << otherObje.typeGetter() << std::endl;
	out << "| Rank : ";

	switch (otherObje.rank)
	{
	case Rank::Undefined: out << "Undefined\n";
		break;
	case Rank::Sergeant:out << "Sergeant\n";
		break;
	case Rank::Commander:out << "Comander\n";
		break;
	case Rank::Enlisted:out << "Enlisted\n";
		break;
	default:
		out << "?????????\n";
		break;
	}
	
	out << "\n|-----------------------------------|\n";
	return out;
}

std::istream& operator>>(std::istream& input, const Stormtrooper& otherObj){
	
	char* cont = new char[47];
	
	delete[] otherObj.ID;
	delete[] otherObj.type;

	std::cout << "| ID: ";
	input.getline(cont, 47);
	strcpy(otherObj.ID, cont);
	delete[] cont;

	std::cout << "| Type : ";
	input.getline(cont, 47);
	strcpy(otherObj.type, cont);
	delete[] cont;

	return input;
}
