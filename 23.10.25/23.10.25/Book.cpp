#include "Book.h"
#include <string>

Book::Book() {

	title = "None";
	author = "None";
	genre = None;
	foundationYear = 0;
}

void Book::FillBookInfo()
{
	cout << "Enter title: "; getline(cin, title);
	cout << "Enter author: "; getline(cin, author);
	cout << "Enter year of foundation: "; cin >> foundationYear;

	int number_of_genre;

	PrintAllGenres();
	cout << "Enter genre of this title: "; cin >> number_of_genre;
	this->genre = SwitchGenres(number_of_genre);
}

void Book::PrintBookInfo()
{
	cout << "Author: " << author << endl;
	cout << "Title: " << title << endl;
	cout << "Year of foundation: " << foundationYear << endl;
	PrintBookGenre();
}

void Book::PrintBookGenre()
{
	switch (genre)
	{
	case None: cout << "None" << endl; break;
	case Fiction: cout << "Fiction" << endl; break;
	case Fantasy: cout << "Fantasy" << endl;  break;
	case Science_Fiction: cout << "Science Fiction" << endl; break;
	case Dystopian: cout << "Dystopian" << endl; break;
	case Adventure: cout << "Adventure" << endl; break;
	case Mystery: cout << "Mystery" << endl; break;
	case Horror: cout << "Horror" << endl; break;
	case Thriller: cout << "Thriller" << endl; break;
	case Historical: cout << "Historical" << endl; break;
	case Romance: cout << "Romance" << endl; break;
	case Contemporary: cout << "Contemporary" << endl; break;
	case Literary: cout << "Literary" << endl; break;
	case Magical_Realism: cout << "Magical Realism" << endl; break;
	case Graphic_Novel: cout << "Graphic Novel" << endl; break;
	case Short_Story: cout << "Short Story" << endl; break;
	case Autobiography: cout << "Autobiography" << endl; break;
	case Biography: cout << "Biography" << endl; break;
	case Travel: cout << "Travel" << endl; break;
	case True_Crime: cout << "True Crime" << endl; break;
	case Humor: cout << "Humor" << endl; break;
	case Essays: cout << "Essays" << endl; break;
	case Guide: cout << "Guide" << endl; break;
	case Religion: cout << "Religion" << endl; break;
	}
}

void Book::PrintGenre(int i)
{
	switch (i)
	{
	case 1: cout << "None"; break;
	case 2: cout << "Fiction"; break;
	case 3: cout << "Fantasy";  break;
	case 4: cout << "Science Fiction"; break;
	case 5: cout << "Dystopian"; break;
	case 6: cout << "Adventure"; break;
	case 7: cout << "Mystery"; break;
	case 8: cout << "Horror"; break;
	case 9: cout << "Thriller"; break;
	case 10: cout << "Historical"; break;
	case 11: cout << "Romance"; break;
	case 12: cout << "Contemporary"; break;
	case 13: cout << "Literary"; break;
	case 14: cout << "Magical Realism"; break;
	case 15: cout << "Graphic Novel"; break;
	case 16: cout << "Short Story"; break;
	case 17: cout << "Autobiography"; break;
	case 18: cout << "Biography"; break;
	case 19: cout << "Travel"; break;
	case 20: cout << "True Crime"; break;
	case 21: cout << "Humor"; break;
	case 22: cout << "Essays"; break;
	case 23: cout << "Guide"; break;
	case 24: cout << "Religion"; break;
	}
}

Genre Book::SwitchGenres(int number)
{
	switch (number)
	{
	case 2: return Fiction;
	case 3: return Fantasy;
	case 4: return Science_Fiction;
	case 5: return Dystopian;
	case 6: return Adventure;
	case 7: return Mystery;
	case 8: return Horror;
	case 9: return Thriller;
	case 10: return Historical;
	case 11: return Romance;
	case 12: return Contemporary;
	case 13: return Literary;
	case 14: return Magical_Realism;
	case 15: return Graphic_Novel;
	case 16: return Short_Story;
	case 17: return Autobiography;
	case 18: return Biography;
	case 19: return Travel;
	case 20: return True_Crime;
	case 21: return Humor;
	case 22: return Essays;
	case 23: return Guide;
	case 24: return Religion;
	default: return None;
	}
}

void Book::PrintAllGenres()
{
	for (int i = 1; i < 24; i++)
	{
		cout << "[" << i << "] - "; PrintGenre(i); cout << endl;
	}
}