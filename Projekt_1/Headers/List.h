#pragma once
#include "../Headers/Node.h"

class List : Node
{
	Node* header, trailer;

	List()
	{
		header = new Node('0', nullptr, nullptr);
		trailer = new Node('0', nullptr, nullptr);
	}

	Node* AtIndex(const int& key)
	{
		Node* help = this;
		Node* end = this;

		for (int i = 0; i < Size(); i++)
		{
			if (key == help->GetKey()) return help;//help->GetLetter();
			else if (key == end->GetKey()) return end;//->GetLetter();

			if (help->GetNext() != nullptr) help = help->GetNext();
			else if (end->GetPrevious() != nullptr) end = end->GetPrevious();
			//std::cout << key << help->GetKey() << end->GetKey()<< std::endl;
		}

		return AtIndex(0);
	}
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


	const bool& IsEmpty() const;
	const int Size() const;               //zmienna statyczna?




}; //CLASS

