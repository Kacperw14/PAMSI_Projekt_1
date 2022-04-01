#include"../Headers/Node.h"


//template<char T>
//Map<T>::Map(T _message)
//{
//	message = _message;
//
//	parent = this;
//	child = nullptr;
//}


Node::Node(std::string _message, int _key)
{
	message = _message;
	key = _key;
	/*if (GetPrevious() != nullptr) key = GetPrevious()->GetKey() + 1;
	else
	{
		key = 1;
		std::cout << "lol" << std::endl;
	}*/
	previous = nullptr;
	next = nullptr;
}

Node::Node(std::string _mess, int _key, Node* _previous, Node* _next)
{
	message = _mess;
	previous = _previous;
	next = _next;
	key = _key;
	//if (_key == 0) key = _key;											//Szczegolny przypadek header, trailer
	//else if (GetPrevious() != nullptr) key = _previous->GetKey() + 1;
	//else key = 1;
}

Node::Node(Node* newNode)
{
	message = newNode->GetLetter();
	key = newNode->GetKey();
	next = newNode->GetNext();
	previous = newNode->GetPrevious();
}

const std::string& Node::GetLetter() const
{
	if (this == nullptr) return "0";
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



