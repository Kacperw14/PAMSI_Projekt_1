#include <iostream>
#include "../Headers/List.h"
#include "../Headers/Node.h"
using namespace std;

int main()
{
	List<Node> Lista;
	List<Node> ListaOdbiorcza;
	string s;
	char choice = 'm';
	//string p;
	//while (cin.peek() != ' ')
	//{
	//	s = cin.get();
	//	p = p + s;
	//}
	//cout << p << endl;
	//Lista.AddAtEnd(p);
	while (choice != 'k')
	{
		switch (choice)
		{
		case 'm':
		{
			cout << "Menu wyboru: " << endl;
			cout << "Wybierz \'m\' aby zobaczyc menu" << endl;
			cout << "Wybierz \'n\' aby napisac wiadomosc" << endl;
			cout << "Wybierz \'w\' aby wyslac wiadomosc" << endl;
			cout << "Wybierz \'d\' aby wydrukowac sekwencje wiadomosci" << endl;
			cout << "Wybierz \'u\' aby usunac wybrana wiadomosc" << endl;
			cout << "Wybierz \'e\' aby edytowac wiadomosc" << endl;
			cout << "Wybierz \'k\' aby wyjsc" << endl;
		}
		break;

		case 'n':
		{
			string p;
			if (cin.peek() == '\n') cin.ignore();//cin.unget();
			//if(!Lista.IsEmpty()) Lista.AddAtEnd(" ");
			do
			{
				cin >> s;
				Lista.AddAtEnd(s);
			} while (cin.peek() != '\n'); //"k"); //'\n' się zapisuje Lista.removeEnd();
			cout << "Wiadomosc wyslana pomyslnie" << endl;
		}
		break;	

		case 'w':
		{
			ListaOdbiorcza.ReceiveMessage(Lista);
			cout << "Wyslana: ";
			ListaOdbiorcza.PrintMessage();

		}
		break;

		case 'd':
		{
			Lista.PrintList();
		}
		break;

		case 'u':
		{
			Lista.Remove(Lista.Last());
		}
		break;

		default:
		{
			cout << "Niepoprawne polecenie" << endl;
		}
		break;
		}

		cin >> choice;
	}


	//Lista.PrintList();

	return 0;
}//MAIN
