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
		const T* head = _lista.GetHeader();
		for (int i = (_lista.GetHeader()->GetNext()->GetKey()); i <= _lista.Max(); i++)
		{
			Insert(_lista.AtIndex(i));
			head = head->GetNext();
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
	T* newNode = new T(_node->GetMessage(), (_node->GetKey() + 1), trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
}

template <typename T>
void List<T>::AddAfter(T* afterMe, T* _node)
{

	if (afterMe != nullptr)
	{
		T* newNode = new T(_node->GetMessage(), _node->GetKey(), afterMe, afterMe->GetNext());
		afterMe->GetNext()->SetPrevious(newNode);
		afterMe->SetNext(newNode);
	}
	else throw "Nale¿y podaæ inne parametry ni¿ nulltr";
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
	else std::cout << "Funkcja \"Remove\": Nie mozna usunac nullptr, header ani trailer" << std::endl;
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

			if (head->GetKey() != 0) head = head->GetNext();


		}
		AddAfter(index, _node);
	}
}

template<typename T>
void List<T>::ClearList()
{
	while (!IsEmpty())
	{
		Remove(Last());
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
			std::cout << head->GetMessage() << " (nr wiadomosci: " << head->GetKey() << ")" << std::endl;
		}
	}
}

template <typename T>
void List<T>::PrintMessage() const
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

template<typename T>
const int List<T>::Max() const
{
	if (IsEmpty()) return 0;
	else
	{
		Node* help = header;
		int max = 1;
		for (int i = 0; i < Size(); i++)
		{
			help = help->GetNext();                        //Nastepujaca kolejnosc by pominac header
			if (max < help->GetKey()) max = help->GetKey();
		}
		return max;
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

		std::cout << "Funkcja \"AtIndex\":Nie ma takiego indexu" << std::endl;
		return nullptr;
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

template
class List<Node>;