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
	Node(std::string _message);  //key
	Node(std::string _mess, int _key, Node* _previous, Node* _next);
	Node(Node* newNode); 	                                     //Konstruktor kopiuj¹cy

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu.
	const std::string& GetLetter() const;
	const int& GetKey() const;
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetKey(const int& _key) { key = _key; };
	void SetNext(Node* newNode) { if (this != nullptr) next = newNode; };
	void SetPrevious(Node* newNode) { if (this != nullptr) previous = newNode; };


}; //CLASS

