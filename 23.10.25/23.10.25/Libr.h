#pragma once
#include "Book.h"
#include <iostream>

class Lib
{
	string name;
	string address;
	int foundationYear;

	int books_counter;
	Book* books;

public:

	Lib();

	void FillLibInfo();

	void PrintLibInfo();
	void PrintAllBooks();

	void AddBook();
	void DeleteBook();
};