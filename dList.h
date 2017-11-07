#pragma once
#include "dNode.h"

template <class T>
class dList {
private:
	// dList class fields
	dNode<T> *first, *last;
	int size;

	// static utilities
	static dNode<T>* copy(dNode<T>*, dNode<T>*&);
	static bool lexicographicCompare(dNode<T>*, dNode<T>*);
	static void destroy(dNode<T>* first_node);

public:
	class const_iterator {
		friend class dList;
	private:
		dNode<T>* ptr;
		const_iterator(dNode<T>* n = nullptr) :
			ptr(n)
		{}
	public:
		// operator overloads
		const_iterator& operator++() // postfix increment
		{
			// increment ptr pointer field if exists
			if (ptr != nullptr) {
				ptr = ptr->next;
			}
			return *this;
		}
		bool operator==(const const_iterator& cit) const // equal
		{
			return ptr == cit->ptr;
		}
		bool operator!=(const const_iterator& cit) const // different than
		{
			return ptr != cit.ptr;
		}
		T& operator*() const // dereference
		{
			return ptr->info;
		}
		T* operator->() const // arrow operator
		{
			return &(ptr->info);
		}
	};
	
	const_iterator begin() const {
		return const_iterator(first);
	}
	const_iterator end() const {
		return const_iterator();
	}

	dList(const dList& l) :
		first(copy(l.first, last)), // side effect on last
		size(l.size)
	{}
	~dList() {
		destroy(first);
	}
	
	// operator overloads
	dList& operator=(const dList&); // assignment
	bool operator<(const dList&) const; // lexicographic comparison

	void insertFront(const T&);
	void insertBack(const T&);
	int getSize() const;

	dList(int k = 0, const T& t = T()) :
		first(nullptr),
		last(nullptr),
		size(0)
	{
		for (int i = 0; i < k; i++) {
			insertFront(t);
		}
	}
};

template <class T>
dNode<T>* dList<T>::copy(dNode<T>* f, dNode<T>*& tail)
{
	if (f == nullptr) {
		tail = nullptr;
		return nullptr;
	}

	dNode<T>* p = new dNode<T>(f->info);

	dNode<T>* tmp = p;
	// p points to the first dNode of the new list copy
	// temp points to the last current dNode of the new list copy
	while (f->next != nullptr) {
		// temp becomes the 'prev' of temp->next.
		tmp->next = new dNode<T>(f->next->info, tmp);
		// updates t and f
		tmp = tmp->next;
		f = f->next;
	}

	// t points to the last dNode of the new list copy
	tail = tmp;
	return p;
}

template <class T>
bool dList<T>::lexicographicCompare(dNode<T>* l1, dNode<T>* l2) {
	if (l1 == nullptr && l2 == nullptr) {
		return true;
	}

	// l1!=0
	if (l2 == nullptr) {
		return false;
	}

	// l1!=0 && l2!=0
	if (l1->info < l2->info) {
		return true;
	}
	if (l1->info > l2->info) {
		return false;
	}
	
	// l1!=0 && l2!=0 && l1->info == l2->info
	return dList<T>::lexicographicCompare(l1->next, l2->next);
}

template <class T>
void dList<T>::destroy(dNode<T>* first_node) {
	if (first_node != nullptr) {
		::delete first_node; // memory leak prevented thanks to ~dNode()
	}
}

// memory handling without sharing
template <class T>
dList<T>& dList<T>::operator=(const dList& l)
{
	// case l1 = l1, silly logic error that can however occur
	if (this != &l) {
		destroy(first);
		first = copy(l.first, last);
	}

	return *this;
}

template <class T>
bool dList<T>::operator<(const dList<T>& l) const
{
	return dList<T>::lexicographicCompare(first, l.first);
}

template <class T>
void dList<T>::insertFront(const T& t) {
	if (first == nullptr) {
		first = last = new dNode<T>(t);
	}
	else {
		first = new dNode<T>(t, nullptr, first);
		(first->next)->prev = first;
	}

	size++;
}

template <class T>
void dList<T>::insertBack(const T& t) {
	if (first == nullptr) {
		first = last = new dNode<T>(t);
	}
	else {
		last = new dNode<T>(t, last);
		(last->prev)->next = last;
	}

	size++;
}

template <class T>
int dList<T>::getSize() const {
	return size;
}
