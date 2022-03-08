#pragma once

/*
Klasa


*/
class Map
{
private:
	char letter;
	int id;
	Map* parent;
	Map* child;

public:
	Map() = default;//delete;
	Map(char _letter, int _id);
	const int& Size() const;
	const char& GetLetter() const { return letter; };
	const char& operator[] (int index) const;
	//const char& operator[] (int index) const;        //Child's letter;
	const Map* GetChild() const { return child; };
	const void Add(Map& newMap) { child = &newMap; };

}; //CLASS

