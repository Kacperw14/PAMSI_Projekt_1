#pragma once
#include <iostream>           //!
#include <string>
/*
Klasa


*/
//template <typename T = char>

class Node
{
private:

	std::string message;
	int key;
	Node* previous;
	Node* next;

public:
	
	//Konstruktory
	Node() = default;      //delete
	Node(std::string _message);
	Node(std::string _mess, int _key, Node* _previous, Node* _next);
	Node(Node* newNode); 	                                     //Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu.
	const char& GetLetter() const;
	const int& GetKey() const;
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(Node* newNode) { next = newNode; };
	void SetPrevious(Node* NewNode) { previous = NewNode; };

}; //CLASS

