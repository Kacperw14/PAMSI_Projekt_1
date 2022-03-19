#include"../Headers/Node.h"


//template<char T>
//Map<T>::Map(T _message)
//{
//	message = _message;
//
//	parent = this;
//	child = nullptr;
//}


Node::Node(char _message, int _key)
{
	message = _message;

	if (_key >= 0)
	{
		key = _key;
	}
	else throw;         //EXCEPTIONS

	next = nullptr;
	previous = nullptr;
}

Node::Node(char _mess, int _key, Node* _previous, Node* _next)
{
	message = _mess;
	key = _key;
	previous =  _previous;
	next = _next;
}

Node::Node(Node* newNode)
{
	message = newNode->GetLetter();
	key = newNode->GetKey();
	next = newNode->GetNext();
	previous = newNode->GetPrevious();
}

const int& Node::Size() const
{
	return 0;
}

const char& Node::operator[](const int& index) const
{
	if (index == key)
	{
		return message;
	}
	else
	{
		return '0';
	}
}

void Node::AddAfter(Node* afterMe, Node* newMap)
{
	newMap->SetNext(afterMe->GetNext());
	afterMe->SetNext(newMap);
	newMap->SetPrevious(afterMe);
}


