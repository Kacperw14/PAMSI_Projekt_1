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


	//do
	//{

	//	// cin.getline(s, '\n');
	//	s = cin.get();      //oddzielnie litery
	//	//cin>> s;             //brak spacji enter
	//	Node* n = new Node(s, 2);
	//	//cout<<n->GetLetter()<< n->GetKey()<<endl;
	//	//Lista.Insert(n);
	//	--k;

	//	Lista.AddAtEnd(s);
	////} while (s != "\n"); //"k"); //'\n' się zapisuje Lista.removeEnd();
	//} while (s != "k"); //"k"); //'\n' się zapisuje Lista.removeEnd();
	////cout << endl;
	//cout << Lista.AtIndex(0)->GetLetter() << endl;

	//Node* n = Lista.AtIndex(1);
	//ListaOdb.Insert(n);
	//ListaOdb.Insert(new Node("c", 3));
	//ListaOdb.Insert(new Node("b", 2));
	/*cin >> s;
	Lista.Insert(new Node(s, 2));

	cin >> s;
	Lista.Insert(new Node(s, 1));
	Lista.Insert(new Node(s, 3));*/
	cin >> s;
	Lista.AddAtEnd(s);
	Lista.AddAtEnd(s);
	Lista.AddAtEnd(s);
	//cout << Lista.Size() << endl;
	Lista.PrintList();
	//Lista.AddAfter(Lista.AtIndex(0), new Node(s,2));
	//Lista.AddAfter(Lista.AtIndex(1), new Node(s,3));
	//cout << Lista.AtIndex(1)->GetLetter() << endl;
	//Lista.Insert(Lista.AtIndex(5));

	//ListaOdb.ReceiveMessage(Lista);
	ListaOdb.Insert(Lista.AtIndex(1));
	Lista.AtIndex(2);
	std::cout << "nast" << std::endl;
	ListaOdb.Insert(Lista.AtIndex(3));
	//ListaOdb.Insert(Lista.AtIndex(4));
////cout << ListaOdb.AtIndex(1)->GetLetter() << endl;
	/*cout<< ListaOdb.Size()<<endl;
	cout<< ListaOdb.GetHeader()->GetLetter()<<endl;
	cout<< ListaOdb.GetHeader()->GetNext()-> GetLetter()<<endl;
	cout<< ListaOdb.GetHeader()->GetNext()->GetLetter()<<endl;*/

	cout << endl;
	cout << ListaOdb.GetHeader()->GetLetter() << endl;
	cout << ListaOdb.GetHeader()->GetNext()->GetLetter() << endl;
	cout << ListaOdb.GetHeader()->GetNext()->GetNext()->GetLetter() << endl;
	//ListaOdb.PrintList();

	//ListaOdb.PrintMessage();

	////s = cin.get();
	////k = cin.get();





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