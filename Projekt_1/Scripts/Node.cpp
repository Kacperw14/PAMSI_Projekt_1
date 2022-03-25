#include"../Headers/Node.h"


//template<char T>
//Map<T>::Map(T _message)
//{
//	message = _message;
//
//	parent = this;
//	child = nullptr;
//}


Node::Node(char _message)
{
	message = _message;
	if (GetPrevious() != nullptr) key = GetPrevious()->GetKey() + 1;
	else key = 1;
	previous = nullptr;
	next = nullptr;
}

Node::Node(char _mess, int _key, Node* _previous, Node* _next)
{
	message = _mess;
	previous = _previous;
	next = _next;
	if (_key == 0) key = _key;											//Szczegolny przypadek header, trailer
	else if (GetPrevious() != nullptr) key = _previous->GetKey() + 1;
	else key = 1;
}

Node::Node(Node* newNode)
{
	message = newNode->GetLetter();
	key = newNode->GetKey();
	next = newNode->GetNext();
	previous = newNode->GetPrevious();
}


//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu.

const char& Node::GetLetter() const
{
	if (this == nullptr) return '0';
	else return message;
}

const int& Node::GetKey() const
{
	if (this == nullptr) return 0;
	else return key;
}

Node* Node::GetNext() const
{
	if (this == nullptr) return nullptr;
	else return next;
}

Node* Node::GetPrevious() const 
{
	if (this == nullptr) return nullptr;
	else return previous;
}

//const char& Node::operator[](const int& index) const
//{
//	if (index == key)
//	{
//		return message;
//	}
//	else
//	{
//		return '0';
//	}
//}


