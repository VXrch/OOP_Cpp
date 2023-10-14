#include <iostream>
#include <fstream>

using namespace std;

struct Book
{
	string title;
	string author;
	string publisher;
	string genre;
	int year_of_publication;
	int price;
	int Id;
	static int FullId;

	Book()
	{
		title = "no";
		author = "no";
		publisher = "no";
		genre = "no";
		year_of_publication = 0;
		price = 0;
		FullId++;
		Id = FullId;
	}

	void FillFromFile(string titleF, string authorF, string publisherF, string genreF, int year_of_publicationF, int priceF) {
		title = titleF;
		author = authorF;
		publisher = publisherF;
		genre = genreF;
		year_of_publication = year_of_publicationF;
		price = priceF;
	}

	void Fill() {

		cout << "Title: "; cin >> title;
		cout << "Author: "; cin >> author;
		cout << "Publisher: "; cin >> publisher;
		cout << "Genre: "; cin >> genre;
		cout << "Year of publication: "; cin >> year_of_publication;
		cout << "Price in $ (for example \"150\"): "; cin >> price;

		cout << "-----------------------------------" << endl;
	}

	void Print() {

		cout << "Id: " << Id << endl;
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Publisher: " << publisher << endl;
		cout << "Genre: " << genre << endl;
		cout << "Year of publication: " << year_of_publication << endl;
		cout << "Price: " << price << endl;

		cout << "-----------------------------------" << endl;
	}

	void Change_title() {
		cout << "Enter new title: "; cin >> title;
	}
	void Change_author() {
		cout << "Enter new author: "; cin >> author;
	}
	void Change_publisher() {
		cout << "Enter new publisher: "; cin >> publisher;
	}
	void Change_genre() {
		cout << "Enter new genre: "; cin >> genre;
	}
	void Change_year_of_publication() {
		cout << "Enter new year of publication: "; cin >> year_of_publication;
	}
	void Change_price() {
		cout << "Enter new price: "; cin >> price;
	}

	/*There is no destructor here, 
	because the static variable should not be decremented, 
	it is used to calculate the IDs for books.*/

#pragma region If book is slass

	string Get_title() {
		return title;
	}
	string Get_author() {
		return author;
	}
	string Get_publisher() {
		return publisher;
	}
	string Get_genre() {
		return genre;
	}
	int Get_year_of_publication() {
		return year_of_publication;
	}
	int Get_price() {
		return price;
	}

#pragma endregion
};

void FindBy_title(Book* arr, int size) {

	string temp;
	bool found = false;

	cout << "Enter title:"; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].title == temp)
		{
			arr[i].Print(); 
			found = true;
		}
	}

	if (found == false) {
		cout << "Book is not found!" << endl;
	}
}
void FindBy_author(Book* arr, int size) {

	string temp;
	bool found = false;

	cout << "Enter author:"; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].author == temp)
		{
			arr[i].Print(); 
			found = true;
		}
	}

	if (found == false) {
		cout << "Book is not found!" << endl;
	}
}
void FindBy_publisher(Book* arr, int size) {

	string temp;
	bool found = false;

	cout << "Enter publisher:"; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].publisher == temp)
		{
			arr[i].Print(); 
			found = true;
		}
	}

	if (found == false) {
		cout << "Book is not found!" << endl;
	}
}
void FindBy_genre(Book* arr, int size) {

	string temp;
	bool found = false;

	cout << "Enter genre:"; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].genre == temp)
		{
			arr[i].Print(); 
			found = true;
		}
	}

	if (found == false){
		cout << "Book is not found!" << endl;
	}
}
void FindBy_year_of_publication(Book* arr, int size) {

	int temp;
	bool found = false;

	cout << "Enter year_of_publication (for example \"1925\"):"; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].year_of_publication == temp)
		{
			arr[i].Print();
			found = true;
		}
	}

	if (found == false) {
		cout << "Book is not found!" << endl;
	}
}
void FindBy_price(Book* arr, int size) {

	int temp;
	bool found = false;

	cout << "Enter price in $ (for example \"150\"): "; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].price == temp)
		{
			arr[i].Print();
			found = true;
		}
	}

	if (found == false) {
		cout << "Book is not found!" << endl;
	}
}

void SaveToFile(Book*& arr, int& size)
{
	ofstream outFile("data.txt", ios::out | ios::trunc);

	if (outFile.is_open()) {

		for (int i = 0; i < size; ++i) {

			outFile << arr[i].title << ":" << arr[i].author << ":" << arr[i].publisher << ":" << arr[i].genre << ":" << arr[i].year_of_publication << ":" << arr[i].price << "|";
		}
		outFile.close();

		cout << "Successfully!" << endl;
	}
	else {
		cout << "I can't open this file!" << endl;
	}
}
void FillFrFile(Book*& arr, int& size)
{
	ifstream inFile("data.txt");

	if (inFile.is_open()) {

		while (!inFile.eof()) {

			string title;
			string author;
			string publisher;
			string genre;
			int year_of_publication;
			int price;

			char delimiter;

			inFile >> title >> delimiter >> author >> delimiter >> publisher >> delimiter >> genre >> delimiter >> year_of_publication >> delimiter >> price >> delimiter;
			if (inFile.eof()) break;

			Book readedDot;
			readedDot.FillFromFile(title, author, publisher, genre, year_of_publication, price);

			Book* temp = new Book[size + 1];

			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}

			temp[size] = readedDot;

			delete[] arr;
			arr = temp;
			size++;
		}

		inFile.close();

		cout << "Successfully!" << endl;
	}
	else {
		cout << "I can't open this file!" << endl;
	}
}

void Show(Book* arr, int size) { // Print all

	for (int i = 0; i < size; i++)
	{
		arr[i].Print();
	}
}

int ChooseBook(Book* arr, int size) {

	Show(arr, size);

	int temp;

	cout << "Enter book id: "; cin >> temp;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].Id == temp) {

			return arr[i].Id;
		}
	}

	cout << "Book is not found!" << endl;
	return -1;
}

void ChangeData(Book* arr, int size) {

	int title_Id = ChooseBook(arr, size);

	for (int i = 0; i < size; i++)
	{
		if (arr[i].Id == title_Id)
		{
			int choice;

			cout << "Change:" << endl;
			cout << "[1] - title" << endl;
			cout << "[2] - author" << endl;
			cout << "[3] - publisher" << endl;
			cout << "[4] - genre" << endl;
			cout << "[5] - year_of_publication" << endl;
			cout << "[6] - price" << endl;
			cout << "___---| "; cin >> choice;

			switch (choice)
			{
			case 1: arr[i].Change_title(); break;
			case 2: arr[i].Change_author(); break;
			case 3: arr[i].Change_publisher(); break;
			case 4: arr[i].Change_genre(); break;
			case 5: arr[i].Change_year_of_publication(); break;
			case 6: arr[i].Change_price(); break;
			default: cout << "Wrong choice!" << endl; break;
			}

			break;
		}
	}
}

void AddNewBook(Book*& arr, int& size)
{
	Book* temp = new Book[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	temp[size].Fill();

	delete[] arr;
	arr = temp;
	size++;
}

void DeleteBook(Book*& arr, int& size)
{
	int book_to_delete;

	cout << "Enter book to delete: " << endl;
	book_to_delete = ChooseBook(arr, size);

	if (book_to_delete == -1){

		cout << "Wrong Id!" << endl; 
		return;
	}

	Book* temp = new Book[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (arr[i].Id != book_to_delete){
			temp[i] = arr[i];
		}
	}

	delete[] arr;
	arr = temp;
	size--;
}

int Book::FullId = 0;

void main() {

	srand(time(NULL));

	/*Завдання 1. 
	
	Розробіть програму «Бібліотека».

    Створіть клас «Книга»
		(назва, автор, видавництво, жанр, рік видання, price).
		
	Створіть масив з 10 книг.Реалізуйте для нього такі можливості:
		■ Редагувати книгу; (ChangeData)
		■ Друк усіх книг; (Show);
		■ Пошук книг за автором;
		■ Пошук книги за назвою;
		■ Пошук книги за видавництвом
		■ Пошук книги за жанром
		■ Add new book
		■ Save to File
		■ Load from file
	*/

	bool isExit = false;
	int choice = 0;

	int size = 0;
	Book* arr = new Book[size];

	while (!isExit)
	{
		cout << "___---| MENU |---___" << endl;
		cout << "[1] - Add new book" << endl;
		cout << "[2] - Delete book" << endl;
		cout << "[3] - Change book info" << endl;
		cout << "[4] - Show all books" << endl;
		cout << "   _- | Find book by | -_" << endl;
		cout << "[5] - Title" << endl;
		cout << "[6] - Author" << endl;
		cout << "[7] - Publisher" << endl;
		cout << "[8] - Genre" << endl;
		cout << "[9] - Year of publication" << endl;
		cout << "[10] - Price" << endl;
		cout << endl;
		cout << "[11] - Fill from file" << endl;
		cout << "[12] - Save to file" << endl;
		cout << endl;
		cout << "[0] - EXIT" << endl;

		cout << "Enter task number (1-4): "; cin >> choice;

		switch (choice) {
		case 1: // Add new book
			AddNewBook(arr, size);
			break;
		case 2: // Delete book
			if (size > 0)
			{
				DeleteBook(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 3: // Change book info
			if (size > 0)
			{
				ChangeData(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 4: // Show all books
			if (size > 0)
			{
				Show(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 5: // FB Title
			if (size > 0)
			{
				FindBy_title(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 6: // FB Author
			if (size > 0)
			{
				FindBy_author(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 7: // FB Publisher
			if (size > 0)
			{
				FindBy_publisher(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 8: // FB Genre
			if (size > 0)
			{
				FindBy_genre(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 9: // FB Year of publication
			if (size > 0)
			{
				FindBy_year_of_publication(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 10: // FB Price
			if (size > 0)
			{
				FindBy_price(arr, size);
			}
			else {
				cout << "There are no books in the library!" << endl;
			}
			break;
		case 11: // Fill from file
			FillFrFile(arr, size);
			break;
		case 12: // Save to file
			if (size > 0)
			{
				SaveToFile(arr, size);
			}
			else {
				cout << "There are no books in the library! There are no books in the library! You can't save information if it doesn't exist!" << endl;
			}
			break;
		case 0: // EXIT
			cout << "Bye-bye!" << endl; 
			isExit = true;
			break;
		default: cout << "Wrong choice!" << endl; break;
		}

		system("pause");
		system("cls");
	}

	delete[]arr;
}