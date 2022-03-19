#pragma once

/*
Klasa


*/
//template <typename T = char>

class Node
{
private:

	Node* previous;
	Node* next;
	char message;
	int key;



public:

	Node() = default;

	Node(char _message, int _key);

	Node(char _mess, int _key, Node * _previous, Node * _next);

	//Konstruktor kopiuj¹cy
	Node(Node* newNode);

	const int& Size() const;
	const char& GetLetter() const { return message; };
	const int& GetId() const { return key; };
	const char& operator[] (const int& index) const;     //Nie dla listy
	
	Node* GetNext() const { return next; };
	Node* GetPrevious() const { return previous; };

	void SetNext(Node* newNode) { next = newNode; };
	void SetPrevious(Node* NewNode) { previous = NewNode; };

	void AddAfter(Node* afterMe, Node* newNode);
	//bool IsEmpty();


}; //CLASS

