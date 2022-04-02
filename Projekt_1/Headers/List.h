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
	bool IsEmpty() const;
	int Size() const;

	void AddAtEnd(const std::string& mess);
	void AddAtFront(const std::string& mess);
	void AddAfter(Node* afterMe, Node* newNode);
	void AddBefore(Node* newNode, Node* beforeMe)
	{
		newNode->SetNext(beforeMe);
		newNode->SetPrevious(beforeMe->GetPrevious());
		beforeMe->GetPrevious()->SetNext(newNode);
		beforeMe->SetPrevious(newNode);
		// ResetKeys();
	};

	void Insert(Node* newNode)
	{
		//Node* head = header;
		Node* trail = trailer;

		if (trail->GetPrevious() == nullptr) AddBefore(newNode, trail);
		else 
		{
			//while(newNode->GetKey() < head->GetKey()) head = head->GetNext();
			while (newNode->GetKey() < trail->GetKey() && IsEmpty()) trail = trail->GetPrevious();

			AddAfter(trail, newNode);
		}
	};

	void PrintList() const;                //Musi to posk³adaæ!!
	void PrintMessage() const;                //Musi to posk³adaæ!!
	void ResetKeys();  //???
	//
	Node* AtIndex(int _key) const;
	int IndexOf(const std::string& mess) const;              //Iterator

	//
	const Node* GetHeader() const { return header; };
	const Node* GetTrailer() const { return trailer; };

	Node* partition(Node* h, Node* t)
	{
		// set pivot as h element
		int x = t->GetKey();

		// similar to i = l-1 for array implementation
		Node* i = h->GetPrevious();

		// Similar to "for (int j = l; j <= h- 1; j++)"
		for (Node* j = h; j != t; j = j->GetNext())
		{
			if (j->GetKey() <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? h : i->GetNext();

				i->SwapKeys(j);
				//swap(&(i->GetKey()), &(j->GetKey()));
			}
		}
		i = (i == NULL) ? h : i->GetNext(); // Similar to i++
		i->SwapKeys(t);
		//swap(&(i->GetKey()), &(t->GetKey()));
		return i;
	}

	void _quickSort(Node* h, Node* t)
	{
		if (t != NULL && h != t && h != t->GetNext())
		{
			Node* p = partition(h, t);
			_quickSort(h, p->GetPrevious());
			_quickSort(p->GetNext(), t);
		}
	}

	void quickSort()
	{
		// Call the recursive QuickSort
		_quickSort(header, trailer);
	}

	void SortKeys(List* _list)
	{
		Node* head = header;
		Node* trail = trailer;

		while (head != trail)
		{
			head = head->GetNext();
			trail = trail->GetPrevious();
			if (head->GetKey() < trail->GetKey()) head->SwapKeys(trail);
		}
		//const Node* pivot = _list->AtIndex(Size() / 2);
		//std::cout << pivot->GetKey() << std::endl;

		//while (pivot->GetKey() != 1)
		//{
		//	if (pivot->GetKey() < pivot->GetPrevious()->GetKey()) pivot = pivot->GetPrevious();
		//	else pivot = pivot->GetNext();

		//	std::cout << head->GetKey() << std::endl;
		//	//std::cout << std::endl << Size() << std::endl;
		//	std::cout << pivot->GetLetter() << std::endl;
		//}
	}


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

