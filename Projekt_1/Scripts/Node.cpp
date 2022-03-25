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
	else key = 0;
	//header = new Node('0', 0, nullptr, nullptr);
	//trailer = new Node('0', 0, header, nullptr);
	//header->SetNext(trailer);
	previous = nullptr;
	next = nullptr;
}

Node::Node(char _mess, Node* _previous, Node* _next)
{
	message = _mess;
	previous = _previous;
	next = _next;
	if (GetPrevious() != nullptr) key = _previous->GetKey() + 1;
	else key = 0;
}

Node::Node(Node* newNode)
{
	message = newNode->GetLetter();
	key = newNode->GetKey();
	next = newNode->GetNext();
	previous = newNode->GetPrevious();
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

void Node::AddAfter(Node* afterMe, Node* newNode)            //niezgodne z posortowanym kluczem
{
	if (afterMe->GetKey() == Max())
	{
		newNode->SetNext(afterMe->GetNext());
		afterMe->SetNext(newNode);
		newNode->SetPrevious(afterMe);
	}
	else
	{
		newNode->SetNext(afterMe->GetNext());
		afterMe->GetNext()->SetPrevious(newNode);
		afterMe->SetNext(newNode);
		newNode->SetPrevious(afterMe);
	}

}


const bool& Node::IsEmpty() const
{
	if (GetPrevious() != nullptr || GetNext() != nullptr)
	{
		return false;
	}
	else return true;
}

const int Node::Size() const
{
	int size = 1;
	Node* head = previous;
	Node* trailer = next;

	while (head != nullptr)
	{
		size++;
		head = head->GetPrevious();
	}

	while (trailer != nullptr)
	{
		size++;
		trailer = trailer->GetNext();
	}

	return size;
}


