#pragma once
#include "../Headers/Node.h"

class List : Node
{
private:
	Node* header;
	Node* trailer;

public:

	//Konstruktory
	List();

	//
	const bool& IsEmpty() const;

	const int& Size()
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

	void PrintList()                //Musi to posk³adaæ!!
	{
		Node* head = header;
		for (int i = 0; i < Size(); i++)
		{
			head = head->GetNext();
			std::cout << head->GetLetter() << head->GetKey() << std::endl;
		}
	};

	void SortKeys()
	{
		Node* head = header;
		Node* trail = trailer;

		while (head == trail)
		{
			head = head->GetNext();
			trail = trail->GetPrevious();
		}
		Node* pivot = head;
		/*const Node* mid = AtIndex(Size() / 2);

		std::cout << mid->GetKey() << std::endl;

		while (mid->GetKey() != 1)
		{
			if (mid->GetKey() < mid->GetPrevious()->GetKey()) mid = mid->GetPrevious();
			else mid = mid->GetNext();
		}*/
		std::cout << head->GetKey() << std::endl;
		//std::cout << std::endl << Size() << std::endl;
		std::cout << pivot->GetLetter() << std::endl;



	}

	void AddAtEnd(const std::string& mess);
	void AddAtFront(const std::string& mess);

	void AddAfter(Node* afterMe, Node* newNode)
	{
		//Node* newNode = new Node(mess);
		newNode->SetPrevious(afterMe);
		newNode->SetNext(afterMe->GetNext());
		afterMe->GetNext()->SetPrevious(newNode);
		afterMe->SetNext(newNode);
		ResetKeys();
	}

	void Insert(const int& _key, Node* newNode)
	{
		//Node* newNode = new Node(mess);
		newNode->SetPrevious(AtIndex(_key));
		newNode->SetNext(AtIndex(_key)->GetNext());
		AtIndex(_key)->GetNext()->SetPrevious(newNode);
		AtIndex(_key)->SetNext(newNode);
		ResetKeys();
	}

	void ResetKeys()
	{
		Node* head = header;
		//while (IsEmpty)
		for (int i = 0; i < Size(); i++)
		{
			head->SetKey(i);
			head = head->GetNext();
		}
	}

	//
	Node* AtIndex(const int& key);
	const int& IndexOf(const std::string& mess);              //Iterator

	//
	const Node* GetHeader() const { return header; };
	const Node* GetTrailer() const { return trailer; };


	/*



	const int& Max()
	{
		const Node* help = this;
		int max = 0;
		for (int i = 0; i < Size(); i++)
		{
			if (max <= help->GetKey()) max = help->GetKey();
			if (help->GetNext() != nullptr) help = help->GetNext();
			//std::cout << i << mess << help->GetLetter() << (mess == help->GetLetter()) << GetKey() << std::endl;
		}
		return max;
	}
	const int& Min()
	{
		const Node* help = this;
		int min = 0;
		for (int i = 0; i < Size(); i++)
		{
			if (min >= help->GetKey()) min = help->GetKey();
			if (help->GetNext() != nullptr) help = help->GetNext();
			//std::cout << i << mess << help->GetLetter() << (mess == help->GetLetter()) << GetKey() << std::endl;
		}
		return min;
	}






	*/

}; //CLASS

