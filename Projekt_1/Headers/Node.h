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
	Node();
	Node(std::string _message, int _key);  //key
	Node(std::string _mess, int _key, Node* _previous, Node* _next);
	Node(const Node& newNode); 	                                     //Konstruktor kopiuj�cy
	Node(Node* newNode); 	                                     //Konstruktor kopiuj�cy
	

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu.
	std::string GetLetter() const;
	int GetKey() const;
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetKey(int _key);
	void SetNext(Node* newNode);

	void SetPrevious(Node* newNode);

	void SwapKeys(Node* _node);


}; //CLASS

