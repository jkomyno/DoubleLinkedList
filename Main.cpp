#include<iostream>
#include "dList.h"

using std::cout;
using std::endl;

// esempio d'uso
int main() {
	dList<int> x(4, 2), y, z(6, 8);
	y = x;

	x.insertFront(5);
	y.insertFront(0);
	z.insertBack(3);

	(x < y) ? cout << "x < y" : cout << "x >= y";
	cout << endl;

	for (dList<int>::const_iterator cit = x.begin(); cit != x.end(); ++cit)
		cout << *cit;

	cout << endl;
	cout << "y.getSize()" << y.getSize() << endl;
	for (dList<int>::const_iterator cit = y.begin(); cit != y.end(); ++cit)
		cout << *cit;

	cout << endl;

	getchar();
}