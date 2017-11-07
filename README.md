# DoubleLinkedList

Object Oriented Programming assignment @University of Padova, Italy.

## Assignment costraints

> Define a template with class `dList<T>` whose objects represent a double linked list for elements
> of type T. It has to satisfy these costraints:

> 1. memory management without sharing;
> 2. `dList<T>` has to expose the constructor `dList(int k, const T& t)`, which builds a list containing k nodes, everyone of which keeps a copy of t;
> 3. `dList<T>` must perform head and tail insertion in a constant time O(1)
>   - `void insertFront(const T& t)`: adds a node with info `t` to the head and updates the surrounding nodes accordingly;
>   - `void insertBack(const T& t)`: adds a node with info `t` to the tail and updates the surrounding nodes accordingly;
> 4. `dList<T>` has to expose an overload of `operator<` which implements the lexicographic sorting;
> 5. `dList<T>` has to expose constant iterator type `dList<T>::const_iterator` whose objects allow to iterate through the elements of a list.

## Personal choices

To avoid memory leaks with ease, each class' destructor is responsible for deleting its pointers. For instance, the following snipped taken from `dNode.h` allows the user to delete a dNode and let the destructor handle the removal of every possible subsequence next to that node.

```c++
	~dNode() {
		if (next != nullptr) {
			delete next;
		}
	}
```

## Build and Run

I've used Visual Studio 2015 to build and run my project. Just double click on DoubleLinkedList.vcxproj

If you prefer using g++, be sure to include the header `-std=c++11`.
