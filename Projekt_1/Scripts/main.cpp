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
			cout << "Wybierz \'d\' aby wydrukowac wiadomosc" << endl;
			cout << "Wybierz \'o\' aby odebrac wiadomosc" << endl;
			cout << "Wybierz \'u\' aby usunac wybrana wiadomosc" << endl;
			cout << "Wybierz \'e\' aby edytowac wiadomosc" << endl;
			cout << "Wybierz \'k\' aby wyjsc" << endl;
			cout << " ________________________________ " << "   ______________________________" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl;
		}
		break;

		case 'n':
		{
			cin.ignore();
			cin.unget();
			string p;
			int counter = 0;
			do
			{
				while (s != " ")
				{
				s = cin.get();
				p += s;
				}
				//cin.clear();
				Lista.AddAtEnd(p);
				counter++;
			} while (cin.peek() != '\n'); //"k"); //'\n' się zapisuje Lista.removeEnd();
			cout << "Wiadomosc zostala poprawnie wyslana" << endl; //" << "'\'" <<s<< "'\'" << "
			cout << " ________________________________ " << "   ______________________________" << endl
				<< "| " << p                            << "  |..............................| " << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl
				<< "|................................|" << "  |..............................|" << endl;

		}
		break;

		case 'o':
		{
			ListaOdbiorcza.ReceiveMessage(Lista);
		}
		break;

		case 'd':
		{
			Lista.PrintMessage();
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
