#pragma once
#include <iostream>

using namespace std;

enum Genre { None = 1, Fiction, Fantasy, Science_Fiction, Dystopian, 
	Adventure, Mystery, Horror, Thriller, Historical, 
	Romance, Contemporary, Literary, Magical_Realism, 
	Graphic_Novel, Short_Story, Autobiography, Biography, 
	Travel, True_Crime, Humor, Essays, Guide, Religion };

class Book {

	string title;
	string author;
	Genre genre;
	int foundationYear;

	Genre SwitchGenres(int number);
public:

	Book();
	void FillBookInfo();
	void PrintBookInfo();

	void PrintGenre(int i);
	void PrintAllGenres();
	void PrintBookGenre();
};