#pragma once
#include <iostream>           //!
/*
Klasa


*/
//template <typename T = char>

class Node
{
private:

	char message;
	int key;
	Node* previous;
	Node* next;
	//Node* header;
	//Node* trailer;



public:
	
	//Konstruktory
	Node() = default;      //delete
	Node(char _message);
	Node(char _mess, int _key, Node* _previous, Node* _next);
	Node(Node* newNode); 	                                     //Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu.
	const char& GetLetter() const;
	const int& GetKey() const;
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(Node* newNode) { next = newNode; };
	void SetPrevious(Node* NewNode) { previous = NewNode; };

	//const char& operator[] (const int& index) const;             //Nie dla listy
}; //CLASS

