#include <iostream>
#include "../Headers/List.h"

using namespace std;

int main()
{
	//Node N("h");
	//Node* T = new Node("t");
	//N.GetPrevious()->SetPrevious(T);
	List Lista;
	string s;
	int k;

	//do
	//{
	//	s = cin.get();
	//	Lista.AddAtEnd(s, k);
	//} while (s != "\n"); //"k"); //'\n' się zapisuje Lista.removeEnd();
	//
	//s = cin.get();
	//k = cin.get();
	for (int i = 0; i < 10; i++)
	{
		s = "a";
		k = rand()%10;
		Lista.AddAtEnd(s, k);
	}


	//Lista.AddAfter(Lista.AtIndex(2) ,new Node("z"));
	//Lista.AddAtFront("n");
	//Lista.Insert(3, new Node("w"));
	//cout<< Lista.Size() << endl;
	//cout << Lista.IndexOf("\n") << endl;
	//cout << Lista.AtIndex(2)->GetLetter() << endl;            //enter!!!!
	//cout << Lista.AtIndex(2)->GetKey() << endl;

	//Lista.PrintList();
	//Lista.SortKeys(&Lista);
	Lista.quickSort();
	Lista.PrintList();


	return 0;

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne!
// kopiec