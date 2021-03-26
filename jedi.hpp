#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <fstream>
#include "planet.hpp"

enum class JediRank {
	Undefined, Master, Knight
};

class Jedi {

private:
	char* name;
	char* spicies;
	char* militaryRank;
	double midiChlorian;
	JediRank jediRank;
	Planet planet;

private:
	void destroyJedi();
	void copyJedi(const Jedi& otherObj);

public:

	Jedi();
	Jedi(const Jedi& otherObj);
	Jedi(const char* name, const char* spicies, const char* militaryRank, const double midiChlorian, const JediRank jediRank, const Planet planet);
	Jedi& operator= (const Jedi& otherObj);
	~Jedi();

	char* nameGetter() const;
	void nameSetter(const char* name);

	char* spiciesGetter() const;
	void spiciesSetter(const char* spicies);

	char* militaryRankGetter() const;
	void militaryRankSetter(const char* militaryRank);

	double midiChlorianGetter() const;
	void midiChlorianSetter(const double midiChlorian);

	JediRank jediRankGetter() const;
	void jediRankSetter(const JediRank jediRank);
	void planetSetter(const Planet planet);

	friend std::ostream& operator<<(std::ostream& out, const Jedi& otherObj);
	friend std::istream& operator>>(std::istream& input, Jedi& otherObj);

	void JediFile(Jedi& obj);

	void printJedi() const;

};