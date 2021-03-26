#include "jedi.hpp"

void Jedi::destroyJedi() {

	delete[] this->name;
	delete[] this->spicies;
	delete[] this->militaryRank;
}

void Jedi::copyJedi(const Jedi& otherObj) {

	this->name = new char[strlen(otherObj.name) + 1];
	strcpy(this->name, otherObj.name);

	this->spicies = new char[strlen(otherObj.spicies) + 1];
	strcpy(this->spicies, otherObj.spicies);

	this->militaryRank = new char[strlen(otherObj.militaryRank) + 1];
	strcpy(this->militaryRank, otherObj.militaryRank);

	this->jediRank = otherObj.jediRank;
	this->midiChlorian = otherObj.midiChlorian;
	this->planet = otherObj.planet;
}

Jedi::Jedi() {

	this->name = new char[1];
	strcpy(this->name, "");

	this->spicies = new char[1];
	strcpy(this->spicies, "");

	this->militaryRank = new char[1];
	strcpy(this->militaryRank, "");

	this->midiChlorian = 0.0;
	this->jediRank = JediRank::Undefined;
	this->planet.nameSetter("Nowhere");
}

Jedi::Jedi(const Jedi& otherObj) {
	copyJedi(otherObj);
}

Jedi::Jedi(const char* name, const char* spicies, const char* militaryRank, const double midiChlorian, const JediRank jediRank, const Planet planet) {

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->spicies = new char[strlen(spicies) + 1];
	strcpy(this->spicies, spicies);

	this->militaryRank = new char[strlen(militaryRank) + 1];
	strcpy(this->militaryRank, militaryRank);

	this->midiChlorian = midiChlorian;
	this->jediRank = jediRank;
	this->planet = planet;
}

Jedi& Jedi::operator=(const Jedi& otherObj) {

	if (this != &otherObj) {
		destroyJedi();
		copyJedi(otherObj);
	}
	return *this;
}

Jedi::~Jedi() {
	destroyJedi();
}

char* Jedi::nameGetter() const {
	return this->name;
}

void Jedi::nameSetter(const char* name) {

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char* Jedi::spiciesGetter() const {
	return this->spicies;
}

void Jedi::spiciesSetter(const char* spicies) {

	delete[] this->spicies;
	this->spicies = new char[strlen(spicies) + 1];
	strcpy(this->spicies, spicies);
}

char* Jedi::militaryRankGetter() const {
	return this->militaryRank;
}

void Jedi::militaryRankSetter(const char* militaryRank) {

	delete[] this->militaryRank;
	this->militaryRank = new char[strlen(militaryRank) + 1];
	strcpy(this->militaryRank, militaryRank);
}

double Jedi::midiChlorianGetter() const {
	return this->midiChlorian;
}

void Jedi::midiChlorianSetter(const double midiChlorian) {
	this->midiChlorian = midiChlorian;
}

JediRank Jedi::jediRankGetter() const {
	return this->jediRank;
}

void Jedi::jediRankSetter(const JediRank jediRank) {
	this->jediRank = jediRank;
}

void Jedi::planetSetter(const Planet planet){
	this->planet = planet;
}

std::ostream& operator<<(std::ostream& out, const Jedi& otherObj){

	out << "|-------------JEDI------------------|\n";
	out << "| Name : " << otherObj.nameGetter() << std::endl;
	out << "| Spicies : " << otherObj.spiciesGetter() << std::endl;
	out << "| Military Rank : " << otherObj.militaryRankGetter() << std::endl;
	out << "| Midi-Chlorian : " << otherObj.midiChlorianGetter() << std::endl;
	out << "| Rank : ";

	switch (otherObj.jediRankGetter())
	{
	case JediRank::Undefined: out << "Undefined\n";
		break;
	case JediRank::Knight: out << "Knight\n";
		break;
	case JediRank::Master: out << "Master\n";
		break;
	default:
		break;
	}
	std::cout << "| Planet : ";
	planetPrinter<const char*>(otherObj.nameGetter());
	out << "\n|-----------------------------------|";

	return out;
}

std::istream& operator>>(std::istream& input, Jedi& otherObj){
	
	char* cont = new char[47];

	delete[] otherObj.name;
	delete[] otherObj.spicies;
	delete[] otherObj.militaryRank;

	std::cout << "| Name : ";
	input.getline(otherObj.name, 47);
	strcpy(otherObj.name, cont);
	delete[] cont;

	std::cout << "| Spicies : ";
	input.getline(otherObj.spicies, 47);
	strcpy(otherObj.spicies, cont);
	delete[] cont;

	std::cout << "| Military Rank : ";
	input.getline(otherObj.militaryRank, 47);
	strcpy(otherObj.militaryRank, cont);
	delete[] cont;

	return input;
}

void Jedi::JediFile(Jedi& obj){

	std::fstream myFile("Jedi.txt");
	myFile.open("Jedi.txt", std::ios::out);

	myFile << obj.nameGetter() << std::endl;
	myFile << obj.midiChlorianGetter() << std::endl;
	myFile << obj.militaryRankGetter() << std::endl;
	myFile << obj.spiciesGetter() << std::endl;

	myFile.close();
}

void Jedi::printJedi() const {

	std::cout << "|-------------JEDI------------------|\n";
	std::cout << "| Name : " << nameGetter() << std::endl;
	std::cout << "| Spicies : " << spiciesGetter() << std::endl;
	std::cout << "| Military Rank : " << militaryRankGetter() << std::endl;
	std::cout << "| Midi-Chlorian : " << midiChlorianGetter() << std::endl;
	std::cout << "| Rank : ";

	switch (jediRank)
	{
	case JediRank::Undefined: std::cout << "Undefined\n";
		break;
	case JediRank::Knight: std::cout << "Knight\n";
		break;
	case JediRank::Master: std::cout << "Master\n";
		break;
	default:
		break;
	}
	std::cout << "| Planet : ";
	planetPrinter<const char*>(this->planet.nameGetter());
	std::cout << "\n|-----------------------------------|";

}