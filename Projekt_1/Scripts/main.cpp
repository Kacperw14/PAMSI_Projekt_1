#include <iostream>
#include<map>
#include "../Headers/Map.h"

using namespace std;

int main()
{
	map<char, int> myMap
	{
		{'d', 2}
	};

	Map mapa;
	Map mapa1 = Map('r', 1);
	Map mapa2 = Map('k', 2);
	mapa2.Add(mapa1);
	cout<<mapa2[2]<<endl << mapa2.GetChild()->operator[](1)<<endl;


}//MAIN
