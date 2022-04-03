#include <iostream>
#include "../Headers/List.h"
#include "../Headers/Node.h"
using namespace std;

int main()
{
	List<Node> Lista;
	List<Node> ListaOdb;
	string s;
	int k = 1;
	//int i = 1;
	int number = 0;
	do
	{
		//getline(cin, s, ' ');
		//cin.putback(' ');
		cin >> s;
		//Lista.AddAtEnd(new Node(s, rand()%10+2));
		Lista.AddAtEnd(s);
		//Lista.Insert(new Node(s, k--));

		//cin.unget();
		//Lista.AddAtEnd(s);
		//cin.putback('\n');
		//cout << cin.out

	} while (cin.peek() != '\n'); //"k"); //'\n' się zapisuje Lista.removeEnd();
	
	//ListaOdb.Insert(Lista.AtIndex(1));
	//ListaOdb.Insert(Lista.AtIndex(2));
	//ListaOdb.Insert(Lista.AtIndex(3));
	//ListaOdb.Insert(Lista.AtIndex(4));
	Lista.PrintList();
	//} while (s != "k"); //"k"); //'\n' się zapisuje Lista.removeEnd();
	//cout << "Index: " << Lista.AtIndex(0)->GetMessage() << endl;
	//Lista.Remove(Lista.GetHeader()->GetNext());

	//cout << Lista.AtIndex(1)<<endl;


	//ListaOdb.AtIndex(0);

	//ListaOdb.ReceiveMessage(Lista);
	ListaOdb.PrintList();
	ListaOdb.PrintMessage();

	//ListaOdb.Insert(Lista.GetHeader()->GetNext());                        //!!!
	return 0;

}//MAIN
