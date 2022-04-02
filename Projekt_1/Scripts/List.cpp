#include "../Headers/Node.h"
#include "../Headers/List.h"



List::List()
{
	header = new Node("h", 0, nullptr, nullptr);
	trailer = new Node("t", 0, header, nullptr);
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
	//nie liczymy headera
//std::cout << head << std::endl;
	if (IsEmpty()) return 0;
	else
	{
		int size = 0;
		Node* head = header;
		//std::cout << header << std::endl;
		//std::cout << trailer << std::endl;
		while (head != trailer)
		{
			size++;
			head = head->GetNext();  //tutaj
			//std::cout << head << std::endl;
			//std::cout << trailer << std::endl;
		}
		std::cout << "size" << std::endl;
		//std::cout << "wylazlem" << std::endl;
		return size - 1;       //nie liczymy headera
	}
}

void List::AddAtEnd(const std::string& mess)
{
	Node* newNode = new Node(mess, 0, trailer->GetPrevious(), trailer);
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
	if (afterMe != nullptr)
	{
		newNode->SetPrevious(afterMe);
		newNode->SetNext(afterMe->GetNext());
		afterMe->GetNext()->SetPrevious(newNode);
		afterMe->SetNext(newNode);
		std::cout << "after" << std::endl;
	}
	else throw "Nale¿y podaæ inne parametry ni¿ nulltr"; //???
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

void List::PrintMessage() const              //Musi to posk³adaæ!!
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
	Node* head = header;
	for (int i = 0; i < Size(); i++)          //jeœli lista jest pusta head pozostanie header
	{
		std::cout <<Size()<<i<< "index" << head->GetKey()<<_key << std::endl;
		if (head->GetKey() == _key) return head;
		head = head->GetNext();                //w tej kolejnoœci aby pomin¹æ header
	}
	return header;
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

