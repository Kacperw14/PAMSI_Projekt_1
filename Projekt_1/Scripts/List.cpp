#include "../Headers/Node.h"
#include "../Headers/List.h"


template <typename T>
List<T>::List()
{
	header = new T("header", 0, nullptr, nullptr);
	trailer = new T("trailer", 0, header, nullptr);
	header->SetNext(trailer);
}

template <typename T>
const bool List<T>::IsEmpty() const              //bool&
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

template <typename T>
const int List<T>::Size() const
{
	if (IsEmpty()) return 0;
	else
	{
		int size = 0;
		T* head = header->GetNext();    //nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje
		while (head != trailer)
		{
			size++;
			head = head->GetNext();
		}
		return size;
	}
}

template<typename T>
void List<T>::ReceiveMessage(List _lista)
{
	if (_lista.IsEmpty()) std::cout << "Funkcja \"ReceiveMessage\": Lista jest pusta" << std::endl;
	else
	{
		//_lista.QuickSort();
		const T* head = _lista.GetHeader();
		for (int i = 0; i < _lista.Size(); i++)
		{
			head = head->GetNext();
			AddAtEnd(head);
		}
	}
}

template <typename T>
void List<T>::AddAtEnd(std::string mess)
{
	T* newNode = new T(mess, (trailer->GetPrevious()->GetKey() + 1), trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
}

template <typename T>
void List<T>::AddAtEnd(const T* _node)
{
	//AddAtEnd(_node->GetLetter());
	T* newNode = new T(_node->GetMessage(), (_node->GetKey() + 1), trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
}

template <typename T>
void List<T>::AddAtFront(const std::string& mess)        //ustalanie key + sort()
{
	T* newNode = new T(mess, 0, header, header->GetNext());
	header->GetNext()->SetPrevious(newNode);
	header->SetNext(newNode);
	ResetKeys();
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
	}
	else throw "Nale¿y podaæ inne parametry ni¿ nulltr"; //???
}

template<typename T>
void List<T>::Remove(T* _node)
{
	if (_node != nullptr && _node != header && _node != trailer)
	{
		_node->GetNext()->SetPrevious(_node->GetPrevious());
		_node->GetPrevious()->SetNext(_node->GetNext());
		delete _node;
	}
	else std::cout << "Funkcja \"Remove\": Nie mozna usunac nullptr, header ani trailer" << std::endl;//throw
}

template<typename T>
void List<T>::Insert(T* _node)
{
	if (IsEmpty()) AddAfter(header, _node);
	else
	{
		Node* head = header->GetNext(); //nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje
		Node* index = head;
		for (int i = 0; i < Size(); i++)
		{
			if (_node->GetKey() >= head->GetKey()) index = head;
		}
		AddAfter(index, _node);
	}
}

template <typename T>
void List<T>::PrintList() const
{
	if (IsEmpty()) std::cout << "Funkcja \"PrintList\": Lista jest pusta" << std::endl;
	else
	{
		T* head = header;
		for (int i = 0; i < Size(); i++)
		{
			head = head->GetNext();
			std::cout << head->GetMessage() << " (nr wiadomosci: "<< head->GetKey() << ")" << std::endl;
		}
	}
}

template <typename T>
void List<T>::PrintMessage() const              //Musi to posk³adaæ!!
{
	if (IsEmpty()) std::cout << "Funkcja \"PrintMessage\": Lista jest pusta" << std::endl;
	else
	{
		T* head = header;
		for (int i = 0; i < Size(); i++)
		{
			head = head->GetNext();
			std::cout << head->GetMessage();
		}
		std::cout << std::endl;
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

template<typename T>
const int List<T>::Min() const
{
	if (IsEmpty()) return 0;
	else
	{
		Node* help = header;
		int min = 1;
		for (int i = 0; i < Size(); i++)
		{
			help = help->GetNext();                        //Nastepujaca kolejnosc by pominac header
			if (min > help->GetKey()) min = help->GetKey();
		}
		return min;
	}
}

template <typename T>
 T* List<T>::AtIndex(int _key) const
{
	if (IsEmpty() || _key < 0)	throw "Index musi istniec";
	else
	{
		T* head = header->GetNext();
		for (int i = 0; i < Size(); i++)
		{
			if (head->GetKey() == _key) return head;
			else head = head->GetNext();
		}
		return nullptr;//throw "Index musi istniec";
	}
}

template <typename T>
const int List<T> ::IndexOf(const std::string mess) const
{
	if (IsEmpty()) return 0;
	else
	{
		T* head = header->GetNext();
		for (int i = 0; i < Size(); i++)
		{
			if (mess == head->GetMessage()) return head->GetKey();
			else head = head->GetNext();
		}
		return 0;
	}
}

template<typename T>
T* List<T>::Separate(T* left, T* right)
{
	int help = right->GetKey();
	T* i = left->GetPrevious();
	for (T* j = left; j != right; j = j->GetNext())
	{
		if (j->GetKey() <= help)
		{
			if (i == nullptr) i = left;
			else i->GetNext();
			i->SwapKeys(j);
		}
	}
	i = (i == nullptr) ? left : i->GetNext();

	i->SwapKeys(right);
	return i;
}

template<typename T>
void List<T>::PreparatoryQuickSort(T* left, T* right)
{
	if (left != right && left != right->GetNext())
	{
		T* pivot = Separate(left, right);
		PreparatoryQuickSort(left, pivot->GetPrevious());
		PreparatoryQuickSort(pivot->GetNext(), right);
	}
}

template<typename T>
void List<T>::QuickSort()
{
	PreparatoryQuickSort(header, trailer);
}

template
class List<Node>;