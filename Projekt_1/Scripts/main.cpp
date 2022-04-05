#include <iostream>
#include "../Headers/List.h"

using namespace std;

int main()
{
	List<Node> Lista;
	List<Node> ListaTymczasowa;
	List<Node> ListaOdbiorcza;
	string s;
	string p;
	char choice = 'm';   //przypisanie zmiennej wartosci 'm' pozwala na wyswietlenie menu w pierwszej kolejnosci.
	
	while (choice != 'k')
	{
		switch (choice)
		{
		case 'm':
		{
			cout << "Menu wyboru: " << endl;
			cout << "Wybierz \'m\' aby zobaczyc menu" << endl;
			cout << "Wybierz \'n\' aby napisac wiadomosc" << endl;
			cout << "Wybierz \'w\' aby wyslac wiadomosc (Uwaga: usuwa wczesniej napisane wiadomosci)" << endl;
			cout << "Wybierz \'d\' aby wydrukowac sekwencje wiadomosci" << endl;
			cout << "Wybierz \'u\' aby usunac wybrana wiadomosc" << endl;
			cout << "Wybierz \'e\' aby edytowac wiadomosc" << endl;
			cout << "Wybierz \'a\' aby anulowac cala wiadomosc" << endl;
			cout << "Wybierz \'k\' aby wyjsc" << endl;
		}
		break;

		case 'n':
		{
			do
			{
				cin >> s;      
				ListaTymczasowa.AddAtEnd(s);   //Pomocnicza lista zapamietujaca kolejność kluczy wiadomosci nawet po ich wyslaniu (wysylanie usuwa elementy listy "Lista")
				Lista.Insert(ListaTymczasowa.Last());           
				ListaTymczasowa.AddAtEnd(" ");        //cin>> ignoruje znak spacji, wiec trzeba go dodac osobno. 
				Lista.Insert(ListaTymczasowa.Last());

			} while (cin.peek() != '\n');              //Potwierdzenie napisania wiadomosci znakiem nowej lini.
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
			Lista.ClearList();            //Wyczyszczenie wiadomosci wyslanych.
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
				cin >> index;
				if (!cin.good())										//Indeks musi istniec
				{
					cout << "Nie udalo sie usunac widomosci" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if (index == 0) cout << "Powrot do menu" << endl;  //Mozliwosc wyjscia z aktualnego trybu
				else
				{
					if (Lista.AtIndex(index) != nullptr)				//Indeks musi istniec
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
				cin >> index;
				if (!cin.good())										//Indeks musi istniec
				{
					cout << "Nie udalo sie edytowac widomosci" << endl;
					cin.clear();
					cin.ignore(10000, '\n');	
				}
				else if (index == 0) cout << "Powrot do menu" << endl;  //Mozliwosc wyjscia z aktualnego trybu
				else
				{
					string _editnode;
					if (Lista.AtIndex(index) != nullptr)				//Indeks musi istniec
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
		}
		break;

		default:
		{
			cout << "Niepoprawne polecenie" << endl;
			cin.ignore(10000, '\n');                 //Pozwala na ignorowanie losowo wpisanych liter.
		}
		break;
		}
		cin >> choice;      //Wybor opcji.s
	}
	return 0;
}//MAIN
