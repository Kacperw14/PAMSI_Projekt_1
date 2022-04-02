#include "../Headers/Node.h"
#include "../Headers/List.h"


template <typename T>
List<T>::List()
{
	header = new T("h", 0, nullptr, nullptr);
	trailer = new T("t", 0, header, nullptr);
	header->SetNext(trailer);
}

template <typename T>
bool List<T>::IsEmpty() const              //bool&
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

template <typename T>
int List<T>::Size() const
{
	//nie liczymy headera
//std::cout << head << std::endl;
	if (IsEmpty()) return 0;
	else
	{
		int size = 0;
		T* head = header;
		//std::cout << header << std::endl;
		//std::cout << trailer << std::endl;
		while (head != trailer)
		{
			size++;
			head = head->GetNext();  //tutaj
			//std::cout << head << std::endl;
			//std::cout << trailer << std::endl;
		}
		//std::cout << "wylazlem" << std::endl;
		return size - 1;       //nie liczymy headera
	}
}

template <typename T>
void List<T>::AddAtEnd(std::string mess)
{
	T* newNode = new T(mess, 0, trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
	newNode->SetKey((newNode->GetPrevious()->GetKey() + 1));   //Ustalenie klucza
	//ResetKeys();   //nie mo¿na tak :c
}

template <typename T>
void List<T>::AddAtEnd(const T* _node)
{
	AddAtEnd(_node->GetLetter());
}

template <typename T>
void List<T>::AddAtFront(const std::string& mess)        //ustalanie key + sort()
{
	T* newNode = new T(mess, 0);
	newNode->SetPrevious(header);
	newNode->SetNext(header->GetNext());
	header->GetNext()->SetPrevious(newNode);
	header->SetNext(newNode);
	ResetKeys();
}

template<typename T>
void List<T>::ReceiveMessage(List _lista)
{
	_lista.quickSort();
	const T* head = _lista.GetHeader();
	for (int i = 0; i < _lista.Size(); i++)
	{
		head = head->GetNext();
		AddAtEnd(head);
	}
}

template <typename T>
void List<T>::AddAfter(T* afterMe, T* newNode)
{
	if (afterMe != nullptr)
	{
		newNode->SetPrevious(afterMe);
		newNode->SetNext(afterMe->GetNext());
		afterMe->GetNext()->SetPrevious(newNode);
		afterMe->SetNext(newNode);
		std::cout << "after" << std::endl;
	}
	else throw "Nale¿y podaæ inne parametry ni¿ nulltr"; //???
	// ResetKeys();
}

//void List::Insert(const int& _key, Node* newNode)
//{
//	newNode->SetPrevious(AtIndex(_key));
//	newNode->SetNext(AtIndex(_key)->GetNext());
//	AtIndex(_key)->GetNext()->SetPrevious(newNode);
//	AtIndex(_key)->SetNext(newNode);
//	ResetKeys();
//}

template <typename T>
void List<T>::PrintList() const                //Musi to posk³adaæ!!
{
	T* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();
		std::cout << head->GetLetter() << head->GetKey() << std::endl;
	}
}

template <typename T>
void List<T>::PrintMessage() const              //Musi to posk³adaæ!!
{
	T* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();
		std::cout << head->GetLetter();
	}
}


template <typename T>
void List<T>::ResetKeys()
{
	T* head = header;
	for (int i = 0; i < Size(); i++)
	{
		head = head->GetNext();      //pomijamy header
		head->SetKey(i + 1);           // i+1 aby paczki mia³y klucze > 0 (tylko header i trailer maj¹ klucz 0)
	}
}

template <typename T>
T* List<T>::AtIndex(int _key) const
{
	T* head = header;
	for (int i = 0; i < Size(); i++)          //jeœli lista jest pusta head pozostanie header
	{
		std::cout <<Size()<<i<< "index" << head->GetKey()<<_key << std::endl;
		if (head->GetKey() == _key) return head;
		head = head->GetNext();                //w tej kolejnoœci aby pomin¹æ header
	}
	return header;
}

template <typename T>
int List<T> ::IndexOf(const std::string& mess) const
{
	const T* head = header;

	for (int i = 0; i < Size(); i++)
	{
		if (mess == head->GetLetter()) return head->GetKey();
		else head = head->GetNext();
	}
	return 0;
}

template<typename T>
T* List<T>::partition(T* h, T* t)
{
	// set pivot as h element
	int x = t->GetKey();

	// similar to i = l-1 for array implementation
	T* i = h->GetPrevious();

	// Similar to "for (int j = l; j <= h- 1; j++)"
	for (T* j = h; j != t; j = j->GetNext())
	{
		if (j->GetKey() <= x)
		{
			// Similar to i++ for array
			i = (i == NULL) ? h : i->GetNext();

			i->SwapKeys(j);
			//swap(&(i->GetKey()), &(j->GetKey()));
		}
	}
	i = (i == NULL) ? h : i->GetNext(); // Similar to i++
	i->SwapKeys(t);
	//swap(&(i->GetKey()), &(t->GetKey()));
	return i;
}

template<typename T>
void List<T>::_quickSort(T* h, T* t)
{
	if (t != NULL && h != t && h != t->GetNext())
	{
		T* p = partition(h, t);
		_quickSort(h, p->GetPrevious());
		_quickSort(p->GetNext(), t);
	}
}

template<typename T>
void List<T>::quickSort()
{
	_quickSort(header, trailer);
}

template
class List<Node>;