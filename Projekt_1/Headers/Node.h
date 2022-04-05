#pragma once
#include <iostream>
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
	Node(std::string _message, int _key);
	Node(std::string _mess, int _key, Node* _previous, Node* _next);
	//Konstruktor kopiuj¹cy
	Node(const Node& newNode); 	                                     

	//Destruktor
	~Node();

	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string& GetMessage() const;
	const int& GetKey() const;
	Node* GetNext() const;
	Node* GetPrevious() const;

	//Metody umozliwiajace zmiane atrybutow.
	void SetNext(Node* newNode);
	void SetPrevious(Node* newNode);

}; //CLASS

