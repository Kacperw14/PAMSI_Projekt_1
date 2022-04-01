#include "../Headers/Node.h"
#include "../Headers/List.h"



List::List()
{
	header = new Node("h", 0, nullptr, nullptr);
	trailer = new Node("h", 0, header, nullptr);
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

//const int List::Size()


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

	//while (IsEmpty())                //oj chyba nie
	//{
	//	if (header->GetKey() == key)
	//	{
	//		header = head;
	//		return head;
	//	}
	//	else header = header->GetNext();

	//}
}

const int& List::IndexOf(const std::string& mess)
{

	//for (mess;  mess == GetLetter(); this->GetNext())
	const Node* head = header;

	for (int i = 0; i < Size(); i++)
	{
		if (mess == head->GetLetter()) return head->GetKey();
		else head = head->GetNext();
	}
	//	if (head->GetNext() != nullptr) head = head->GetNext();
	//	//else if (end->GetPrevious() != nullptr) end = end->GetPrevious();
	//	//std::cout << i << mess << help->GetLetter() << (mess == help->GetLetter()) << GetKey() << std::endl;
	//}

	return 0;

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
	//newNode->SetKey(1);
	//sort
}

