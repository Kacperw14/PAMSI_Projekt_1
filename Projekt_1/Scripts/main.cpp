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
			cout << "Wyslano: ";
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
			int index;
			cout << "Ktora wiadomosc usunac lub wpisz 0 aby wrocic do menu: " << endl;
			Lista.PrintList();
			cin >> index;
			if (!cin.good() || index == 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Powrot do menu" << endl;
			}
			else
			{
				if (Lista.AtIndex(index) != nullptr)
				{
					cout << "Wiadomosc usunieta pomyslnie" << endl;
					Lista.Remove(Lista.AtIndex(index));
				}
				else cout << "Nie udalo sie usunac widomosci" << endl;
			}
		}
		break;

		case 'e':
		{
			int index;
			cout << "Wybierz ktora wiadomosc edytowac lub wpisz 0 aby wrocic do menu: " << endl;
			Lista.PrintList();
			cin >> index;
			if (!cin.good() || index == 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Powrot do menu" << endl;
			}
			else
			{
				string _editnode;
				if (Lista.AtIndex(index) != nullptr)
				{
					cout << "Edytuj wiadomosc: \"" << Lista.AtIndex(index)->GetMessage() << "\"" << endl;
					cin >> _editnode;
					cout << "Wiadomosc pomyslnie edytowana" << endl;
					Lista.Remove(Lista.AtIndex(index));
					Lista.Insert(new Node(_editnode, index));
				}
				else cout << "Nie udalo sie edytowac widomosci" << endl;
			}
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
	return 0;
}//MAIN
