#pragma once
#include "../Headers/Node.h"


//Mozliwosc rozszerzenia struktury o nowe wezly dwukietrunkowe (template)
template <typename T>
class List : Node
{
private:
	T* header;
	T* trailer;
public:
	//Konstruktory
	List();
	//Konstruktor kopiujacy
	List(const List& _lista) : header(_lista.header), trailer(_lista.trailer) {};  
	//

	// Podstaowe funkcje dla priorytetowej listy dwukierunkowej:
	const bool& IsEmpty() const;
	const int& Size() const;
	T* AtIndex(const int& _key) const;
	const int& IndexOf(const std::string& mess) const;
	T* Last() const { return trailer->GetPrevious(); };
	T* First() const { return header->GetNext(); };
	//

	//Metody dodajace
	void AddAfter(T* afterMe, T* newNode);
	void AddAtEnd(std::string mess);
	void AddAtEnd(const T* _node);
	void Insert(T* _node);
	//
	
	//Metody usuwajace
	void Remove(T* _node);
	void ClearList();
	//

	//Dodatkowe przydatne metody
	void ReceiveMessage(List _lista);
	void PrintList() const;         
	void PrintMessage() const;
	const int Min() const;
	const int Max() const;
	//
	
	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const T* GetHeader() const { return header; };
	const T* GetTrailer() const { return trailer; };
	//
}; //CLASS

