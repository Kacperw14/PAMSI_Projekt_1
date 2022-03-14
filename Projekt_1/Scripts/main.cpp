#include <iostream>
#include<list>
#include<string>
#include "../Headers/Map.h"

using namespace std;

int main()
{
	Map header('z', 0);
	Map m2('k', 2);

	header.AddAfter(&header, &m2);       //!!! 
	header.AddAfter(&m2, new Map('p', 3));

	cout << header.GetNext()->GetNext()->GetLetter();

	return 0;

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne
// kopiec