#include"../Headers/Node.h"

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
	previous = nullptr;
	next = nullptr;
}

Node::Node(std::string _mess, int _key, Node* _previous, Node* _next)
{
	message = _mess;
	key = _key;
	previous = _previous;
	next = _next;
}

Node::Node(const Node& newNode)
{
	message = newNode.GetMessage();
	key = newNode.GetKey();
	next = newNode.GetNext();
	previous = newNode.GetPrevious();
}

Node::~Node()
{
	next = nullptr;
	previous = nullptr;
}
const std::string Node::GetMessage() const
{
	if (this == nullptr) return "0";
	else return message;
}

const int Node::GetKey() const
{
	if (this == nullptr) return 0;
	else return key;
}

Node* Node::GetNext() const
{
	if (this == nullptr) throw "Funkcja \"GetNext:\": otrzymala nullptr";
	else return next;
}

Node* Node::GetPrevious() const
{
	if (this == nullptr) throw "Funkcja \"GetPrevious:\": otrzymala nullptr";
	else return previous;
}

void Node::SetNext(Node* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetNext:\": otrzymala nullptr" << std::endl;//throw nullptr;
	else next = newNode;
}
void Node::SetPrevious(Node* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetPrevious:\": otrzymala nullptr" << std::endl; //throw nullptr;
	else previous = newNode;
}




