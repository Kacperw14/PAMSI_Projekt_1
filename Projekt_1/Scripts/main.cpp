#include <iostream>
#include<list>
#include<string>
#include "../Headers/Map.h"

using namespace std;

int main()
{
	Map header('0', 0);
	header.Add(new Map('d', 1));

	cout << header.GetNext()->GetPrevious()->GetId();
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