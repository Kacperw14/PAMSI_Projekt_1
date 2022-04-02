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
	int number = 0;

	//s = cin.get();      //oddzielnie litery
	//s = getline();

/*for (int i = 0; i < number; i++)
{
}*/

//cin >> s;
//Lista.AddAtEnd(" ");
	do
	{
		//getline(cin, s, ' ');
		//cin.putback(' ');
		cin >> s;
		Lista.AddAtEnd(s);
		//cin.unget();
		//Lista.AddAtEnd(s);
		//cin.putback('\n');
		//cout << cin.out;
	} while (cin.peek() != '\n'); //"k"); //'\n' się zapisuje Lista.removeEnd();
	//} while (s != "k"); //"k"); //'\n' się zapisuje Lista.removeEnd();

	Lista.PrintList();

	cout << endl;

	ListaOdb.ReceiveMessage(Lista);
	ListaOdb.PrintList();
	ListaOdb.PrintMessage();

	return 0;

}//MAIN
