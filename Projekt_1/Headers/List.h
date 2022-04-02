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
	void ReceiveMessage(List _lista)
	{
		/*std::cout << _lista.AtIndex(1)->GetLetter() << std::endl;
		std::cout << _lista.AtIndex(2)->GetLetter() << std::endl;
		std::cout << _lista.AtIndex(3)->GetLetter() << std::endl;
		*/
		//Insert(_lista.AtIndex(1));
		//Insert(_lista.AtIndex(3));
		//std::cout << _lista.AtIndex(4 + 1)->GetLetter() << std::endl;
		for (int i = 0; i < _lista.Size(); i++)
		{
			//std::cout << _lista.AtIndex(i+1)->GetLetter()<<std::endl;
			Insert(_lista.AtIndex(i));
			std::cout << "reP" << std::endl;
			//ListaOdb.AddAtEnd(Lista.AtIndex(i+1)->GetLetter());
		}
		std::cout << "receive" << std::endl;
	};


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
		std::cout << Size() << std::endl;

		Node* head = header;
		Node* stop = header;
		if (IsEmpty()) AddAfter(header, newNode);
		else
		{
			for (int i = 0; i < Size(); i++)
			{
				if (head->GetNext() != nullptr) head = head->GetNext();

				if (newNode->GetKey() >= head->GetKey())
				{
					std::cout << "nowa wieksza równa" << std::endl;//max = head->GetKey();
					stop = head;
				}

			}
			std::cout << head->GetLetter() << std::endl;
			std::cout << stop->GetLetter() << std::endl;
			//std::cout << "Max: " << max << std::endl;
			//AddBefore(newNode, stop);
			AddAfter(stop, newNode);
		}
		/*
		Node* trail = trailer;//->GetPrevious();

		//if (IsEmpty()) //AddAtEnd(newNode->GetLetter());//
		//else
		//{
		//std::cout << newNode<< std::endl;
		//std::cout << header << std::endl;
		if (newNode == header || newNode == trailer) std::cout << "co" << std::endl;//AddAfter(header, newNode);
		else
		{


			if (Size() != 0)
			{
				std::cout << "jestem" << std::endl;
				for (int i = 0; i < Size(); i++)
				{
					trail = trail->GetPrevious();
					if (trail == header)
					{
						std::cout << "jestem header" << std::endl;
						AddAfter(header, newNode);
					}
					else if (trail == trailer)
					{
						std::cout << "jestem trailer" << std::endl;
						//AddAfter(header, newNode);
					}
					else
					{
						std::cout << trail->GetLetter() << std::endl;
						if (newNode->GetKey() < trail->GetKey())
						{
							std::cout << i << std::endl;
							trail = trail->GetPrevious();
						}

					}

					//ListaOdb.AddAtEnd(Lista.AtIndex(i+1)->GetLetter());
				}
				//AddAfter(trail, newNode)
			}
			else
			{
				AddAfter(header, newNode);
				std::cout << "ok" << std::endl;
			}
			//if (trail == trailer)
			//{
			//	std::cout << "jestem trailer" << std::endl;

			//	//AddAfter(header, newNode);
			//}
			//else  AddAfter(trail, newNode);


			//for (int i = 0; i < Size(); i++)
			//{
			//	if (newNode->GetKey() < head->GetKey()) head = head->GetNext();
			//	//ListaOdb.AddAtEnd(Lista.AtIndex(i+1)->GetLetter());
			//}
			//AddBefore(newNode, head);
		}
		//while(newNode->GetKey() < head->GetKey()) head = head->GetNext();
		/*do
		{

		}
		while (newNode->GetKey() < trail->GetKey());*/


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


	int Max()
	{
		const Node* head = header;
		int max = 0;
		if (!IsEmpty()) head = head->GetNext();
		for (int i = 0; i < Size(); i++)
		{
			if (max <= head->GetKey()) max = head->GetKey();
			if (head->GetNext() != nullptr) head = head->GetNext();
			//std::cout << i << mess << help->GetLetter() << (mess == help->GetLetter()) << GetKey() << std::endl;
		}
		return max;
	}

	/*




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

