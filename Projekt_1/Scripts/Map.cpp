#include"../Headers/Map.h"

//Map::Map()
//{
//	letter = default char;
//	id = 0;
//	next = nullptr;
//}

Map::Map(char _letter, int _id)
{
	letter = _letter;

	if (_id >= 0)
	{
		id = _id;
	}
	else
	{
		throw "Dopuszczalne jedynie liczby naturalne";
	}

	child = nullptr;
}

const int& Map::Size() const
{
	return 0;
}

const char& Map::operator[](int index) const
{
	if (index == id)
	{
		return letter;
	}
	else
	{
		return '0';
	}
}


