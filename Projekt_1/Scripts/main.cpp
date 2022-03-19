#include <iostream>
#include<list>
#include<string>
//#include "../Headers/Node.h"
#include "../Headers/List.h"

using namespace std;

int main()
{
	Node trailer('t', 0, nullptr, nullptr);
	Node header('h', 0, nullptr, nullptr);

	Node m2('k', 2);

	header.AddAfter(&header, &m2);       //!!! 
	header.AddAfter(&m2, new Node('p', 3));

	cout << header.GetNext()->GetNext()->GetLetter();

	return 0;

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne!
// kopiec