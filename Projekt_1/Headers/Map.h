#pragma once

/*
Klasa


*/
template <typename T = char>
class Map
{
private:

	int id;
	Map* parent;
	Map* child;
	T message;


public:

	template<char T>
	Map() = default;//delete;

	//Map(T _message);

	const int& Size() const;
	const char& GetLetter() const { return message; };
	const char& operator[] (int index) const;
	//const char& operator[] (int index) const;        //Child's letter;
	const Map* GetChild() const { return child; };
	void SetParent(const Map& _parent) { parent = _parent; };
	const void Add(Map& newMap) 
	{
		child = &newMap; 
		 GetChild(); 
	};

}; //CLASS

