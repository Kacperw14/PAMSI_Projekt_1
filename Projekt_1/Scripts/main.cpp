#include <iostream>
#include<list>
#include<string>
#include "../Headers/Map.h"

using namespace std;

int main()
{
	Map header('z', 0);
	Map m2('k', 2);
	header.Add(&m2);

	cout << header.GetNext()->GetPrevious()->GetLetter();
	//Map mojaMapa1;
	////Map mojaMapa2('d', 1, &mojaMapa1, &mojaMapa1);
	////mojaMapa2.SetNext(&mojaMapa1);

	//cout<< mojaMapa2[1]<<endl; 


	return 0;

	//Map<string> mapa1('l', 0);

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne
// kopiec