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
	Node() = default;
	Node(char _message);
	Node(char _mess, Node* _previous, Node* _next);
	Node(Node* newNode); 	                                     //Konstruktor kopiuj¹cy

	const char& GetLetter() const { return message; };
	const int& GetKey() const { return key; };
	//const char& operator[] (const int& index) const;             //Nie dla listy


	Node* GetNext() const { return next; };
	Node* GetPrevious() const { return previous; };

	void SetNext(Node* newNode) { next = newNode; };
	void SetPrevious(Node* NewNode) { previous = NewNode; };




}; //CLASS

