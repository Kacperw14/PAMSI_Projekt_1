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
	int k = 0;
	//Node n;
	//n = n.GetNext();
	//cout << n.GetLetter()<<endl;
	do
	{

		// cin.getline(s, '\n');
		s = cin.get();      //oddzielnie litery
		//cin>> s;             //brak spacji enter
		//ListaOdb.Insert(new Node(s, rand()));
		Lista.AddAtEnd(s);

		//cout << Lista.AtIndex(1) << endl;
	} while (s != "\n"); //"k"); //'\n' się zapisuje Lista.removeEnd();
		
	cout << Lista.Size() << endl;
	////} while (s != "k"); //"k"); //'\n' się zapisuje Lista.removeEnd();

	//for (int i = 0; i < Lista.Size(); ++i)
	//{
	//	//Node _node = Lista.AtIndex(i);
	//	//cout << Lista.AtIndex(i) << endl;
	//	//ListaOdb.Insert(&_node);
	//	//ListaOdb.AddAtEnd(Lista.AtIndex(i)->GetLetter());
	//}
	////cout << ListaOdb.AtIndex(1) << endl;
	////Lista.PrintList();
	//cout << endl;
	//
	//ListaOdb.PrintMessage();

	////s = cin.get();
	////k = cin.get();


	//for (int i = 0; i < 10; i++)
	//{
	//	s = "a";
	//	k = rand()%10;
	//	//k = i;
	//	Lista.Insert(new Node(s, k));
	//	//Lista.AddAtEnd(s, k);
	//}


	//Lista.AddAfter(Lista.AtIndex(2) ,new Node("z"));
	//Lista.AddAtFront("n");
	//Lista.Insert(3, new Node("w"));
	//cout<< Lista.Size() << endl;
	//cout << Lista.IndexOf("\n") << endl;
	//cout << Lista.AtIndex(2)->GetLetter() << endl;            //enter!!!!
	//cout << Lista.AtIndex(2)->GetKey() << endl;

	//Lista.PrintList();
	//Lista.SortKeys(&Lista);
	//Lista.quickSort();



	return 0;

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne!
// kopiec