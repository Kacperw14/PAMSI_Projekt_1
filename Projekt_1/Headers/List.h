#pragma once
#include "../Headers/Node.h"

template <typename T>
class List : Node
{
private:
	T* header;
	T* trailer;
public:
	//Konstruktory
	List();
	List(const List& _lista) : header(_lista.header), trailer(_lista.trailer) {}; //Czy mo¿na przy template?	

	// Podstaowe funkcje dla listy:
	const bool IsEmpty() const;
	const int Size() const;
	T* AtIndex(int _key) const;
	const int IndexOf(const std::string mess) const;              //Iterator


	void ReceiveMessage(List _lista);

	void AddAfter(T* afterMe, T* newNode);
	void AddAtEnd(std::string mess);
	void AddAtEnd(const T* _node);
	void AddAtFront(const std::string& mess);

	void Remove(T* _node);
	void Insert(T* _node);
	void ClearList()
	{
		while (!IsEmpty())
		{
			Remove(Last());
		}
	}
	T* Last() const { return trailer->GetPrevious(); };

	void PrintList() const;                //Musi to posk³adaæ!!
	void PrintMessage() const;                //Musi to posk³adaæ!!

	const int Min() const;

	const T* GetHeader() const { return header; };
	const T* GetTrailer() const { return trailer; };

	T* Separate(T* left, T* right);
	void PreparatoryQuickSort(T* left, T* right);
	void QuickSort();


}; //CLASS

