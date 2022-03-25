#include <iostream>
#include<list>
#include<string>
//#include "../Headers/Node.h"
#include "../Headers/List.h"

using namespace std;

int main()
{

	Node trailer('t', nullptr, nullptr);
	//Node header('h', 0, nullptr, &trailer);
	//trailer.SetPrevious(&header);
	cout << trailer.GetKey() <<endl;
	cout << trailer.Max() << endl;
	trailer.AddAtTheEnd('a');
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