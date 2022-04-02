#include <iostream>
#include "../Headers/List.h"

using namespace std;

int main()
{
	//Node N("h");
	//Node* T = new Node("t");
	//N.GetPrevious()->SetPrevious(T);
	List Lista;
	List ListaOdb;
	string s;
	int k = 9;


	do
	{

		// cin.getline(s, '\n');
		s = cin.get();      //oddzielnie litery
		Node* n = new Node(s, 2);
	
		Lista.AddAtEnd(s);
	} while (s != "\n"); //"k"); //'\n' się zapisuje Lista.removeEnd();
	//} while (s != "k"); //"k"); //'\n' się zapisuje Lista.removeEnd();
	
	//cin >> s;
	//Lista.AddAtEnd(s);
	//Lista.AddAtEnd(s);
	//Lista.AddAtEnd(s);
	////cout << Lista.Size() << endl;
	Lista.PrintList();
	
	cout << endl;

	ListaOdb.ReceiveMessage(Lista);
	ListaOdb.PrintList();
	ListaOdb.PrintMessage();

	return 0;

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne!
// kopiec