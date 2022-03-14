#include"../Headers/Map.h"


//template<char T>
//Map<T>::Map(T _message)
//{
//	message = _message;
//
//	parent = this;
//	child = nullptr;
//}


Map::Map(char _message, int _id)
{
	message = _message;

	if (_id >= 0)
	{
		id = _id;
	}
	else throw;         //EXCEPTIONS

	next = nullptr;
	previous = nullptr;
}

Map::Map(Map* newMap)
{
	message = newMap->GetLetter();
	id = newMap->GetId();
	next = newMap->GetNext();
	previous = newMap->GetPrevious();
}

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


