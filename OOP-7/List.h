#pragma once
const int MAX_SIZE = 25;

template <typename TT>
class Node {
public:
	TT data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

template <typename TT>
class Iter
{
public:
	Node<TT>* node;
	Iter();
	Iter(const Iter<TT>& it);
	Iter& operator=(const Iter<TT>& a);
	TT& operator*() const;
	Iter& operator+ (const int& a);
};

template <typename TT>
class List
{
	int size;
	Node<TT>* head = nullptr;
	Node<TT>* tail = nullptr;
	Iter<TT> start;
	Iter<TT> end;

public:
	List() { size = 0; head = nullptr; tail = nullptr; };
	List(int second);
	List(const List<TT>& l);
	~List();

	Iter<TT> first();
	Iter<TT> last();
	void push(TT a);
	void pop();

	List& operator= (const List<TT>& l);
	TT& operator[] (int i);
	int& operator()();
	List operator*(List<TT>& l);

};

template <typename TT>
List<TT>::List(int second)
{
	size = second;
	Node<TT>* new_elem = new Node<TT>;
	head = new_elem;
	tail = new_elem;

	for (int i = 0; i < size - 1; i++)
	{
		Node<TT>* new_elem = new Node<TT>;
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
	}
	start.node = head;
	end.node = tail;
}

template <typename TT>
List<TT>::List(const List<TT>& l)
{
	Node<TT>* node = l.head;
	while (node != nullptr) {
		push(node->data);
		node = node->next;
	}
	start.node = head;
	end.node = tail;
}

template <typename TT>
List<TT>::~List()
{
	Node<TT>* curr = head;
	while (curr != nullptr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

template <typename TT>
List<TT>& List<TT>::operator= (const List<TT>& l)
{
	if (this == &l)return *this;

	if (head != nullptr)
	{
		Node<TT>* curr = head;
		while (curr != nullptr)
		{
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

	Node<TT>* node = l.head;
	while (node != nullptr) {
		push(node->data);
		node = node->next;
	}
	start.node = head;
	end.node = tail;
	return *this;
}

template <typename TT>
TT& List<TT>::operator[] (int i)
{
	Node<TT>* curr = head;
	for (int j = 0; j < i; j++) {
		curr = curr->next;
	}
	return curr->data;
}

template <typename TT>
List<TT> List<TT>::operator*(List<TT>& l)
{
	List base = *this;
	int second = this->size;
	List temp;

	for (int i = 0; i < second; i++)
	{
		temp.push(base[i] * l[i]);
	}

	return temp;
}

template <typename TT>
int& List<TT>::operator()() {
	return size;
}


template <typename TT>
Iter<TT> List<TT>::first()
{
	return start;
}

template <typename TT>
Iter<TT> List<TT>::last()
{
	return end;
}

template <typename TT>
void List<TT>::push(TT a)
{
	Node<TT>* new_elem = new Node<TT>;
	new_elem->data = a;

	if (size == 0)
	{
		head = new_elem;
		tail = new_elem;
		size++;
		start.node = head;
		end.node = tail;
	}
	else
	{
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
		size++;
		end.node = tail;
	}

}

template <typename TT>
void List<TT>::pop()
{
	Node<TT>* curr = tail;
	tail = curr->prev;
	delete curr;
	tail->next = nullptr;
	size--;
	end.node = tail;
}


template <typename TT>
Iter<TT>::Iter() {
	node = nullptr;
}

template <typename TT>
Iter<TT>::Iter(const Iter& it) {
	node = it.node;
}

template <typename TT>
Iter<TT>& Iter<TT>::operator=(const Iter<TT>& a)
{
	node = a.node;
	return *this;
}

template <typename TT>
TT& Iter<TT>::operator*() const
{
	return node->data;
}

template <typename TT>
Iter<TT>& Iter<TT>::operator+ (const int& a)
{
	for (int i = 0; i < a; ++i) {
		node = node->next;
	}
	return *this;
}