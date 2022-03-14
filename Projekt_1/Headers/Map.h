#pragma once

/*
Klasa


*/
//template <typename T = char>
class Map
{
private:

	char message;
	int id;
	Map* previous;
	Map* next;



public:

	Map() = default;//delete;

	Map(char _message, int _id);//, Map* _previous, Map* _next);
	//Konstruktor kopiuj¹cy
	//Map(Map* newMap);

	const int& Size() const;
	const char& GetLetter() const { return message; };
	const int& GetId() const { return id; };
	const char& operator[] (const int& index) const;
	//const char& operator[] (int index) const;        //Child's letter;
	
	
	
	Map* GetNext() const { return next; };
	Map* GetPrevious() const { return previous; };

	void SetNext(Map* newMap) { next = newMap; };
	void SetPrevious(Map* newMap) { next = newMap; };

	void Add(Map* newMap)
	{
		next = newMap;
		newMap->SetPrevious(next);
	};

}; //CLASS

