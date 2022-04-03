#pragma once
#include <iostream>           //!
#include <string>

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
	Node(const Node& newNode); 	                                     //Konstruktor kopiuj¹cy
	//Node(Node* newNode); 	                                     //Konstruktor kopiuj¹cy
	~Node();

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string GetMessage() const;   //const &
	const int GetKey() const;
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetKey(int _key);
	void SetNext(Node* newNode);

	void SetPrevious(Node* newNode);

	void SwapKeys(Node* _node);


}; //CLASS

