#pragma once
//#include <iostream>
/*
Klasa


*/
//template <typename T = char>

class Node
{
private:

	Node* previous;
	Node* next;
	char message;
	int key;



public:

	//Konstruktory
	Node() = default;
	Node(char _message, int _key);
	Node(char _mess, int _key, Node* _previous, Node* _next);
	Node(Node* newNode); 	                                     //Konstruktor kopiuj¹cy

	const int& Size() const;
	const char& GetLetter() const { return message; };
	const int& GetKey() const { return key; };
	const char& operator[] (const int& index) const;             //Nie dla listy

	Node* GetNext() const { return next; };
	Node* GetPrevious() const { return previous; };

	void SetNext(Node* newNode) { next = newNode; };
	void SetPrevious(Node* NewNode) { previous = NewNode; };

	void AddAfter(Node* afterMe, Node* newNode);

	bool IsEmpty()
	{
		Node* head = previous;
		Node* trailer = next;

		do
		{
			if (previous != nullptr || next != nullptr)
			{
				return false;
			}

			head = GetPrevious();
			trailer = GetNext();

		} while (head != nullptr || trailer != nullptr);

		return true;
	}

	int Size()
	{
		int size = 1;
		Node* head = previous;
		Node* trailer = next;
		//std::cout << next->GetLetter()<<std::endl;

		while (head != nullptr)
		{
			size++;
			head = head->GetPrevious();
		}

		while (trailer != nullptr)
		{
			size++;
			trailer = trailer->GetNext();
		}

		return size;
	}


}; //CLASS

