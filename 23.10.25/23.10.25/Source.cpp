#include <iostream>
#include "Libr.h"
#include "Book.h"

using namespace std;

void main() {

	Book temp;
	temp.FillBookInfo();
	cout << endl;
	temp.PrintBookInfo();
}