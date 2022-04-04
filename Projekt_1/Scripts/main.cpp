#include <iostream>
#include <fstream>
#include "../Headers/List.h"
using namespace std;

int main()
{
	ifstream test;
	test.open("test.txt");
	List<Node> Lista;
	List<Node> ListaTymczasowa;
	List<Node> ListaOdbiorcza;
	string s;
	string p;
	char choice = 'n';

	//while ()//choice != 'k')
	//{
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
			cout << "Wybierz \'a\' aby anulowac cala wiadomosc" << endl;
			cout << "Wybierz \'k\' aby wyjsc" << endl;
		}
		break;

		case 'n':
		{
			if (test.peek() == '\n')//cin.peek() == '\n')
			{
				//cin.ignore();
				test.ignore();
			}
			//do
			//{
				for (int i = 0; i < 3000; i++)
				{
					ListaTymczasowa.AddAtEnd(s);
					Lista.Insert(ListaTymczasowa.Last());
					test >> s;
				}
				//cin >> s;
				//ListaTymczasowa.AddAtEnd(" ");
				//Lista.Insert(ListaTymczasowa.Last());

			//} while (test.peek() != '\n');//cin.peek() != '\n');
			cout << "Wiadomosc zapisana pomyslnie" << endl;
		}
		break;

		case 'a':
		{
			Lista.ClearList();
			if (Lista.IsEmpty()) cout << "Wiadomosc pomyslnie anulowana" << endl;
			else cout << "Nie udalo sie anulowac wiadomosci" << endl;
		}
		break;

		case 'w':
		{
			ListaOdbiorcza.ReceiveMessage(Lista);
			cout << "Wyslano: ";
			ListaOdbiorcza.PrintMessage();
			Lista.ClearList();
		}
		break;

		case 'd':
		{
			Lista.PrintList();
		}
		break;

		case 'u':
		{
			if (Lista.IsEmpty()) cout << "Lista jest pusta" << endl << "Powrot do menu" << endl;
			else
			{

				int index;
				cout << "Ktora wiadomosc usunac lub wpisz 0 aby wrocic do menu: " << endl;
				Lista.PrintList();
				test >> index;
				//cin >> index;
				if (!cin.good())
				{
					cout << "Nie udalo sie usunac widomosci" << endl;
					//cin.clear();
					//cin.ignore();
					test.clear();
					test.ignore();
				}
				else if (index == 0) cout << "Powrot do menu" << endl;
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
		}
		break;

		case 'e':
		{
			if (Lista.IsEmpty()) cout << "Lista jest pusta" << endl << "Powrot do menu" << endl;
			else
			{
				int index;
				cout << "Wybierz ktora wiadomosc edytowac lub wpisz 0 aby wrocic do menu: " << endl;
				Lista.PrintList();
				test >> index;
				//cin >> index;
				if (!test.good())//cin.good())
				{
					cout << "Nie udalo sie edytowac widomosci" << endl;
					//cin.clear();
					//cin.ignore();
					test.clear();
					test.ignore();
				}
				else if (index == 0) cout << "Powrot do menu" << endl;
				else
				{
					string _editnode;
					if (Lista.AtIndex(index) != nullptr)
					{
						cout << "Edytuj wiadomosc: \"" << Lista.AtIndex(index)->GetMessage() << "\"" << endl;
						test >> _editnode;
						//cin >> _editnode;
						cout << "Wiadomosc pomyslnie edytowana" << endl;
						Lista.Remove(Lista.AtIndex(index));
						Lista.Insert(new Node(_editnode, index));
					}
					else cout << "Nie udalo sie edytowac widomosci" << endl;
				}
			}
		}
		break;

		default:
		{
			cout << "Niepoprawne polecenie" << endl;
			//cin.ignore(10000, '\n');
			test.ignore(10000, '\n');
		}
		break;
		}
		//cin >> choice;
		//test >> choice;
	//}

	test.close();         //zamknij plik
	return 0;
}//MAIN
