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

	Map(char _message, int _id);
	//Konstruktor kopiuj¹cy
	Map(Map* newMap);

	const int& Size() const;
	const char& GetLetter() const { return message; };
	const int& GetId() const { return id; };
	const char& operator[] (const int& index) const;     //Nie dla listy

	Map* GetNext() const { return next; };
	Map* GetPrevious() const { return previous; };

	void SetNext(Map* newMap) { next = newMap; };
	void SetPrevious(Map* newMap) { previous = newMap; };

	void AddAfter(Map* afterMe, Map* newMap)
	{
		newMap->SetNext(afterMe->GetNext());
		afterMe->SetNext(newMap);
		newMap->SetPrevious(afterMe);
	};

}; //CLASS

