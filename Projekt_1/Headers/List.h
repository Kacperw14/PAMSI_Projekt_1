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
	const bool IsEmpty() const;
	const int Size();  //!!cout << Size()<< endl;	

	//
	//void InsertElement(const char& mess, const int& key) const               //Lista automatycznie nadaje klucz
	//{
	//	Node* newNode = new Node(mess);
	//	newNode->SetPrevious(AtIndex(key));
	//	newNode->SetNext(header->GetNext());
	//	header->GetNext()->SetPrevious(newNode);
	//	header->SetNext(newNode);
	//};

	void AddAtEnd(const char& mess) const;
	void AddAtFront(const char& mess) const;
	//
	const Node* AtIndex(const int& key);
	//
	const Node* GetHeader() const { return header; };
	const Node* GetTrailer() const { return trailer; };

	/*

	const int& IndexOf(const char& mess) const                //Iterator
	{
		//for (mess;  mess == GetLetter(); this->GetNext())
		const Node* help = this;
		const Node* end = this;

		for (int i = 0; i < Size(); i++)
		{
			if (mess == help->GetLetter()) return help->GetKey();
			else if (mess == end->GetLetter()) return end->GetKey();

			if (help->GetNext() != nullptr) help = help->GetNext();
			else if (end->GetPrevious() != nullptr) end = end->GetPrevious();
			//std::cout << i << mess << help->GetLetter() << (mess == help->GetLetter()) << GetKey() << std::endl;
		}

		return 0;
	}
	void Insert(const char& _mess)                 //!!! Po co
	{
		AddAfter(AtIndex(Max()), new Node(_mess));
	}

	void AddAtTheEnd(const char& _mess)
	{
		AddAfter(AtIndex(Max()), new Node(_mess));
	}


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

	void AddAfter(Node* afterMe, Node* newNode);





	*/

}; //CLASS

