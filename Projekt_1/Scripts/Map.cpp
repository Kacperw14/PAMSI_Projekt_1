#include"../Headers/Map.h"

//Map::Map()
//{
//	letter = default char;
//	id = 0;
//	next = nullptr;
//}

//Map::Map(char _letter, int _id)
//{
//	letter = _letter;
//
//	if (_id >= 0)
//	{
//		id = _id;
//	}
//	else
//	{
//		throw "Dopuszczalne jedynie liczby naturalne";
//	}
//
//	child = nullptr;
//}

//template<char T>
//Map<T>::Map(T _message)
//{
//	message = _message;
//
//	parent = this;
//	child = nullptr;
//}


Map::Map(char _message, int _id)//, Map* _previous, Map* _next)
{
	//header = new Map('0', 0, nullptr, nullptr);
	//trailer = new Map('0', 0, nullptr, nullptr);


	message = _message;
	id = _id;
	next = nullptr;//_next;
	previous = nullptr;//_previous;
}

//Map::Map(Map* newMap)
//{
//	message = newMap->GetLetter();
//	id = newMap->GetId();
//	//next = newMap->GetNext();
//	//previous = newMap->GetPrevious();
//}

const int& Map::Size() const
{
	return 0;
}

const char& Map::operator[](const int& index) const
{
	if (index == id)
	{
		return message;
	}
	else
	{
		return '0';
	}
}


