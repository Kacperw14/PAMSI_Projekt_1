#include "../Headers/Node.h"
#include "../Headers/List.h"



List::List()
{
	header = new Node('0', 0, nullptr, nullptr);
	trailer = new Node('0', 0, header, nullptr);
	header->SetNext(trailer);
}




/*
Node* List::AtIndex(const int& key)
{
	Node* help = this;
	Node* end = this;

	for (int i = 0; i < Size(); i++)
	{
		if (key == help->GetKey()) return help;//help->GetLetter();
		else if (key == end->GetKey()) return end;//->GetLetter();

		if (help->GetNext() != nullptr) help = help->GetNext();
		else if (end->GetPrevious() != nullptr) end = end->GetPrevious();
		//std::cout << key << help->GetKey() << end->GetKey()<< std::endl;
	}

	return AtIndex(0);
}

void List::AddAfter(Node* afterMe, Node* newNode)            //niezgodne z posortowanym kluczem
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


const bool& List::IsEmpty() const
{
	if (GetPrevious() != nullptr || GetNext() != nullptr)
	{
		return false;
	}
	else return true;
}

const int List::Size() const
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
}*/

