#include "../Headers/Node.h"
#include "../Headers/List.h"



List::List()
{
	header = new Node("h", 0, nullptr, nullptr);
	trailer = new Node("t", -1, header, nullptr);
	header->SetNext(trailer);
}

bool List::IsEmpty() const              //bool&
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

int List::Size() const
{
	int size = 0;
	Node* head = header;

	while (head != trailer)
	{
		head = head->GetNext();
		size++;
	}
	return size - 1;       //nie liczymy headera
}

void List::AddAtEnd(const std::string& mess)
{
	//Node* newNode = new Node(mess, 0);
	Node* newNode = new Node(mess, 0, trailer->GetPrevious(), trailer);
	//newNode->SetNext(trailer);
	//newNode->SetPrevious(trailer->GetPrevious());
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
	newNode->SetKey((newNode->GetPrevious()->GetKey() + 1));   //Ustalenie klucza
	//ResetKeys();   //nie mo¿na tak :c
}

void List::AddAtFront(const std::string& mess)        //ustalanie key + sort()
{
	Node* newNode = new Node(mess, 0);
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
	// ResetKeys();
}

//void List::Insert(const int& _key, Node* newNode)
//{
//	newNode->SetPrevious(AtIndex(_key));
//	newNode->SetNext(AtIndex(_key)->GetNext());
//	AtIndex(_key)->GetNext()->SetPrevious(newNode);
//	AtIndex(_key)->SetNext(newNode);
//	ResetKeys();
//}

void List::PrintList() const                //Musi to posk³adaæ!!
{
	Node* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();
		std::cout << head->GetLetter() << head->GetKey() << std::endl;
	}
}

void List::PrintMessage() const                //Musi to posk³adaæ!!
{
	Node* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();
		std::cout << head->GetLetter();
	}
}

void List::ResetKeys()
{
	Node* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();      //pomijamy header
		head->SetKey(i + 1);           // i+1 aby paczki mia³y klucze > 0 (tylko header i trailer maj¹ klucz 0)
	}
}

Node* List::AtIndex(int _key) const
{
	Node* head = header;              //zapamietuje pozycje header'a
	for (int i = 0; i < Size(); i++)
	{
		//std::cout << head->GetKey();
		head = head->GetNext();                //bez headera
		if (head->GetKey() == _key) return head;
	}
	return AtIndex(0);
}


int List::IndexOf(const std::string& mess) const
{
	const Node* head = header;

	for (int i = 0; i < Size(); i++)
	{
		if (mess == head->GetLetter()) return head->GetKey();
		else head = head->GetNext();
	}
	return 0;
}

