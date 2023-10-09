#include <iostream>
#include <windows.h>

using namespace std;


void gotoxy(int x, int y) {
	static HANDLE h = NULL;    if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

struct Coord {

	int x;
	int y;

	void Fill() {

		cout << "x: "; cin >> x;
		cout << "y: "; cin >> y;
	}
};

class Rctngl {

	int height;
	int width;
	char symbhol;
	Coord coordinates;

public:

	Rctngl()
	{
		height = 1;
		width = 1;
		symbhol = '*';
	}
	Rctngl(int size)
	{
		this->height = size;
		this->width = size;
	}
	Rctngl(int height, int width)
	{
		this->height = height;
		this->width = width;
	}
	Rctngl(int height, int width, char symbhol)
	{
		this->height = height;
		this->width = width;
		this->symbhol = symbhol;
	}

	void Fill() {
		cout << "Enter height: "; cin >> height;
		cout << "Enter width: "; cin >> width;
		cout << "Enter symbhol: "; cin >> symbhol;
		coordinates.Fill();
	}

	void FillCoords() {

		coordinates.Fill();
	}

	void Print() {

		for (int i = 0; i < height; i++)
		{
			gotoxy(coordinates.x, coordinates.y+i);
			for (int i = 0; i < width; i++)
			{
				cout << " " << symbhol;
			}
			cout << endl;
		}
	}
};

void main() {

	/*Створити клас Rectangle, який буде описувати прямокутник.
	Клас містить розміри : ширина, висота, символ, який відображатиме 
	прямокутник на екрані та координати розміщення.
	Для збереження координат створити структуру Coord, яка міститиме X та Y координату.

		Клас повинен містити наступні конструктори :
	Конструктор по замовчуванню, який встановлюватиме «дефолтні» дані
	Параметризований конструктор, який приймає один параметр «розмір» та ініціалізує 
	ним ширину та висоту
	Параметризований конструктор, який приймає два параметри «ширину» та «висоту», 
	які являються розмірами об’єкта

		Та наступні методи :
	Вивід фігури на екран, відповідного розміру, символом та у відповідних координатах
	Зміна розміру прямокутника.Метод приймає два парметри : 1 – зміна висоти, 2 – ширини
	Переміщення прямокутника.Метод приймає два парметри : 1 – величина переміщення по осі X, 2 – по осі Y
		Методи повинні включати перевірку на коректність даних(від’ємна ширина, координати і тд).
		Створити екземпляр об’єкту та протестувати написаті методи.*/

	Rctngl first(10, 5, '*');

	first.FillCoords();
	first.Print();
}