﻿#include <iostream>
#include<list>

//#include "../Headers/Node.h"
#include "../Headers/List.h"

using namespace std;

int main()
{
	List Lista;
	char c;
	string s;
	do
	{
		s = cin.get();
		Lista.AddAtEnd(s);
	} while (s != "\n"); //"k");//
	
	cout << Lista.Size() << endl;

	cout << Lista.GetHeader()->GetLetter() << endl;
	cout << Lista.GetHeader()->GetNext()->GetLetter() << endl;
	cout << Lista.GetHeader()->GetNext()->GetNext()->GetLetter() << endl;
	cout << Lista.GetHeader()->GetNext()->GetNext()->GetNext()->GetLetter() << endl;
	cout << Lista.GetHeader()->GetNext()->GetNext()->GetNext()->GetNext()->GetLetter() << endl;
	//for (int i = 0; i < Lista.Size(); i++)


	//cout << Lista.Size()<< endl;	
	//Node trailer('t', nullptr, nullptr);
	//Node header('h', 0, nullptr, &trailer);
	//trailer.SetPrevious(&header);
	//cout << trailer.GetKey() <<endl;
	//cout << trailer.Max() << endl;
	//trailer.AddAtTheEnd('a');
	/*trailer.Insert('b');
	trailer.Insert('c');
	trailer.Insert('d');


	cout<< trailer.Size()<<endl;
	cout<< trailer.AtIndex(3)<<endl;
	cout<< trailer.IndexOf('c') << endl;
	*/


	return 0;

}//MAIN


// Merge sort
// lista dwukierunkwa
// Iterator ??
// kontenery sekwencyjne!
// kopiec