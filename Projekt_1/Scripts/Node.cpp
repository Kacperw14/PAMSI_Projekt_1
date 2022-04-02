#include"../Headers/Node.h"


//template<char T>
//Map<T>::Map(T _message)
//{
//	message = _message;
//
//	parent = this;
//	child = nullptr;
//}


Node::Node()
{
	message = "0";
	key = 0;
	previous = nullptr;
	next = nullptr;
}

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
	key = _key;
	previous = _previous;
	next = _next;
	//if (_key == 0) key = _key;											//Szczegolny przypadek header, trailer
	//else if (GetPrevious() != nullptr) key = _previous->GetKey() + 1;
	//else key = 1;
}

Node::Node(const Node& newNode)
{
	message = newNode.GetLetter();
	key = newNode.GetKey();
	next = newNode.GetNext();
	previous = newNode.GetPrevious();
}

Node::Node(Node* newNode)
{
	message = newNode->GetLetter();
	key = newNode->GetKey();
	next = newNode->GetNext();
	previous = newNode->GetPrevious();
}

std::string Node::GetLetter() const
{
	if (this == nullptr) return "0";
	else return message;
}

int Node::GetKey() const
{
	if (this == nullptr) return 0;
	else return key;
}

Node* Node::GetNext() const
{
	if (this == nullptr) throw nullptr;//std::cout << "Cos nie tak" << std::endl; 
	else return next;
}

Node* Node::GetPrevious() const
{
	if (this == nullptr) throw nullptr;
	else return previous;
}

void Node::SetKey(int _key)
{
	if (_key < 0) key = 0;
	else key = _key;
}
void Node::SetNext(Node* newNode)
{
	if (this != nullptr) next = newNode;
	else throw nullptr;
}

void Node::SetPrevious(Node* newNode)
{
	if (this != nullptr) previous = newNode;
	else throw nullptr;
}

void Node::SwapKeys(Node* _node)
{
	int k = GetKey();
	SetKey(_node->GetKey());
	_node->SetKey(k);
}



