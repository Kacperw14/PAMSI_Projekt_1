#include "../Headers/Node.h"
#include "../Headers/List.h"



List::List()
{
	header = new Node('h', 0, nullptr, nullptr);
	trailer = new Node('t', 0, header, nullptr);
	header->SetNext(trailer);
}

const bool List::IsEmpty() const              //bool&
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

const int List::Size()
{
	int size = 0;
	Node* head = header;            //zapamietuje pozycje header'a
	//Node* trail = trailer;

	while (!IsEmpty())
	{
		size++;
		header = header->GetNext();
	}

	/*while (trail != nullptr)
	{
		size++;
		trail = trail->GetNext();
	}*/
	header = head;
	return size;
}

//void List::InsertElement(const char& mess, const int& key) const
//{
//	Node* newNode = new Node(mess);
//	newNode->SetNext(afterMe->GetNext());
//	afterMe->GetNext()->SetPrevious(newNode);
//	afterMe->SetNext(newNode);
//	newNode->SetPrevious(afterMe);
//
//}


const Node* List::AtIndex(const int& key)
{
	Node* head = header;              //zapamietuje pozycje header'a
	while (IsEmpty())
	{
		if (header->GetKey() == key)
		{
			header = head;
			return head;
		}
		else header = header->GetNext();

	}
	header = head;
	return AtIndex(0);

	//for (int i = 0; i < Size(); i++)
	//{
	//	if (key == head->GetKey()) return head;//help->GetLetter();
	//	else if (key == end->GetKey()) return end;//->GetLetter();

	//	if (head->GetNext() != nullptr) head = head->GetNext();
	//	else if (end->GetPrevious() != nullptr) end = end->GetPrevious();
	//	//std::cout << key << help->GetKey() << end->GetKey()<< std::endl;
	//}

}

void List::AddAtEnd(const char& mess) const
{

	Node* newNode = new Node(mess);
	newNode->SetNext(trailer);
	newNode->SetPrevious(trailer->GetPrevious());
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);

}
void List::AddAtFront(const char& mess) const
{
	Node* newNode = new Node(mess);
	newNode->SetPrevious(header);
	newNode->SetNext(header->GetNext());
	header->GetNext()->SetPrevious(newNode);
	header->SetNext(newNode);

}
/*
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




*/

