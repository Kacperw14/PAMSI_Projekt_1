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
	const int& Size();

	void AddAtEnd(const std::string& mess);
	void AddAtFront(const std::string& mess);
	void AddAfter(Node* afterMe, Node* newNode);
	void Insert(const int& _key, Node* newNode);

	void PrintList();                //Musi to posk³adaæ!!
	void ResetKeys();
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
		
	std::cout << head->GetKey() << std::endl;
	//std::cout << std::endl << Size() << std::endl;
	std::cout << pivot->GetLetter() << std::endl;



}


	*/

}; //CLASS

