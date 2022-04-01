#include "../Headers/Node.h"
#include "../Headers/List.h"



List::List()
{
	header = new Node("h", 0, nullptr, nullptr);
	trailer = new Node("t", 0, header, nullptr);
	header->SetNext(trailer);
}

const bool& List::IsEmpty() const              //bool&
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

const int& List::Size()
{
	int size = 0;
	Node* head = header;            //zapamietuje pozycje header'a

	while (!IsEmpty())
	{
		header = header->GetNext(); //nie liczymy headera dlatego najpierw przsuwamy header
		size++;
	}
	header = head;
	return size;
}

void List::AddAtEnd(const std::string& mess)
{
	Node* newNode = new Node(mess);
	newNode->SetNext(trailer);
	newNode->SetPrevious(trailer->GetPrevious());
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);

	newNode->SetKey((newNode->GetPrevious()->GetKey() + 1));   //Ustalenie klucza

}

void List::AddAtFront(const std::string& mess)        //ustalanie key + sort()
{
	Node* newNode = new Node(mess);
	newNode->SetPrevious(header);
	newNode->SetNext(header->GetNext());
	header->GetNext()->SetPrevious(newNode);
	header->SetNext(newNode);
	ResetKeys();
}

void List::AddAfter(Node* afterMe, Node* newNode)
{
	newNode->SetPrevious(afterMe);
	newNode->SetNext(afterMe->GetNext());
	afterMe->GetNext()->SetPrevious(newNode);
	afterMe->SetNext(newNode);
	ResetKeys();
}
void List::Insert(const int& _key, Node* newNode)
{
	newNode->SetPrevious(AtIndex(_key));
	newNode->SetNext(AtIndex(_key)->GetNext());
	AtIndex(_key)->GetNext()->SetPrevious(newNode);
	AtIndex(_key)->SetNext(newNode);
	ResetKeys();
}

void List::PrintList()                //Musi to posk³adaæ!!
{
	Node* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();
		std::cout << head->GetLetter() << head->GetKey() << std::endl;
	}
}

void List::ResetKeys()
{
	Node* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head->SetKey(i);
		head = head->GetNext();
	}
}

Node* List::AtIndex(const int& key)
{
	Node* head = header;              //zapamietuje pozycje header'a
	for (int i = 0; i < Size(); i++)
	{
		//std::cout << head->GetKey();
		if (head->GetKey() == key) return head;

		head = head->GetNext();
	}
	return AtIndex(0);
}

const int& List::IndexOf(const std::string& mess)
{
	const Node* head = header;

	for (int i = 0; i < Size(); i++)
	{
		if (mess == head->GetLetter()) return head->GetKey();
		else head = head->GetNext();
	}
	return 0;
}

