#include <iostream>

using namespace std;

class Date {

	enum maxes { MAX_DAYS = 30, MAX_MONTHS = 12 };

	int day;
	int month;
	int year;

public:

	Date() : day(0), month(0), year(0) {}
	explicit Date(int day) : Date()
	{
		this->day = day % 30;
	}
	Date(int day, int month) : Date()
	{
		this->day = day % 30;
		this->month = month % 12;
	}
	Date(int day, int month, int year)
	{
		this->day = day % 30;
		this->month = month % 12;
		this->year = year;
	}

	void Print() const
	{
		cout << day << " : " << month << " : " << year << endl;
	}

	int DateToDays(int days, int months, int years) {
		return (years * 12 * 30) + (months * 30) + days;
	}
	Date DaysToDate(int days) {
		
		Date date;

		date.year = days / (12 * 30);
		days %= (12 * 30);

		date.month = days / 30;
		date.day = days % 30 + 1;

		return date;
	}

	bool operator<(Date date)
	{
		int value1 = DateToDays(this->day, this->month, this->year);
		int value2 = DateToDays(date.day, date.month, date.year);

		if (value1 < value2)
			return true;
		else
			return false;
	}
	bool operator>(Date date)
	{
		int value1 = DateToDays(this->day, this->month, this->year);
		int value2 = DateToDays(date.day, date.month, date.year);

		if (value1 > value2)
			return true;
		else
			return false;
	}
	bool operator<=(Date date)
	{
		int value1 = DateToDays(this->day, this->month, this->year);
		int value2 = DateToDays(date.day, date.month, date.year);

		if (value1 <= value2)
			return true;
		else
			return false;
	}
	bool operator>=(Date date)
	{
		int value1 = DateToDays(this->day, this->month, this->year);
		int value2 = DateToDays(date.day, date.month, date.year);

		if (value1 >= value2)
			return true;
		else
			return false;
	}
	bool operator==(Date date)
	{
		int value1 = DateToDays(this->day, this->month, this->year);
		int value2 = DateToDays(date.day, date.month, date.year);

		if (value1 == value2)
			return true;
		else
			return false;
	}
	bool operator!=(Date date)
	{
		int value1 = DateToDays(this->day, this->month, this->year);
		int value2 = DateToDays(date.day, date.month, date.year);

		if (value1 != value2)
			return true;
		else
			return false;
	}

	Date operator+(Date date)
	{
		int days1 = DateToDays(this->day, this->month, this->year);
		int days2 = DateToDays(date.day, date.month, date.year);
		int result = days1 + days2;

		Date new_date = DaysToDate(result);
		return new_date;
	}
	Date operator-(Date date)
	{
		int days1 = DateToDays(this->day, this->month, this->year);
		int days2 = DateToDays(date.day, date.month, date.year);
		int result = 0;
		result = (days1 - days2);

		Date new_date = DaysToDate(result);
		return new_date;
	}
	Date operator+=(int value)
	{
		Date date1 = DaysToDate(value);
		Date date2;
		date2.day = this->day;
		date2.month = this->month;
		date2.year = this->year;

		Date new_date = date1 + date2;
		return new_date;
	}
	Date operator-=(int value)
	{
		Date date1 = DaysToDate(value);
		Date date2;
		date2.day = this->day;
		date2.month = this->month;
		date2.year = this->year;

		if (date1 > date2)
		{
			Date new_date = date1 - date2;
			return new_date;
		}
		return Date();
	}

	friend void operator++(Date& date, int);
	friend void operator--(Date& date, int);
	friend void operator++(Date& date);
	friend void operator++(Date& date);
	friend void operator--(Date& date);

	Date operator ()(int days)
	{
		Date date1 = DaysToDate(days);
		Date date2;
		date2.day = this->day;
		date2.month = this->month;
		date2.year = this->year;

		Date new_date = date1 + date2;
		return new_date;
	}
	Date operator ()(int days, int months)
	{
		int to_add = (30 * months) + days;
		Date date1 = DaysToDate(to_add);
		Date date2;
		date2.day = this->day;
		date2.month = this->month;
		date2.year = this->year;

		Date new_date = date1 + date2;
		return new_date;
	}
	Date operator ()(int days, int months, int years)
	{
		months += (years * 12);
		int to_add = (30 * months) + days;
		Date date1 = DaysToDate(to_add);
		Date date2;
		date2.day = this->day;
		date2.month = this->month;
		date2.year = this->year;

		Date new_date = date1 + date2;
		return new_date;
	}
};

void operator++(Date& date, int)
{
	if (date.day + 1 <= date.MAX_DAYS)
	{
		date.day++;
	}
	else
	{
		date.day = 1;

		if (date.month + 1 <= date.MAX_MONTHS)
		{
			date.month++;
		}
		else
		{
			date.month++;
			date.year++;
		}
	}
}
void operator--(Date& date, int)
{
	if (date.day - 1 > 0)
	{
		date.day--;
	}
}
void operator++(Date& date)
{
	if (date.day + 1 <= date.MAX_DAYS)
	{
		date.day++;
	}
	else
	{
		date.day = 1;

		if (date.month + 1 <= date.MAX_MONTHS)
		{
			date.month++;
		}
		else
		{
			date.month++;
			date.year++;
		}
	}
}
void operator--(Date& date)
{
	if (date.day - 1 > 0)
	{
		date.day--;
	}
}

void main() {

	/*								«авданн€ 2:
		—твор≥ть клас з ≥м'€м ЂDateї дл€ збер≥ганн€ дати (день, м≥с€ць, р≥к).
			Ќапиш≥ть необх≥дн≥ конструктори та метод дл€ зб≥льшенн€ дати на 1 день.
		
		” клас≥ повинн≥ бути перевантажен≥ операц≥њњ :
		[ ++ ], [ ЦЦ ] (≥нкремент та декремент) Ц додаЇ чи в≥дм≥наЇ один день в≥д дати.
			–еал≥зувати обидв≥ форми оператора(постф≥ксна, преф≥ксна).
		[ != ],[ == ],[ > ],[ < ] (пор≥вн€нн€)Ц пор≥внюють два обТЇкта по величин≥ значень
		[ += ],[ Ц = ] (додаванн€ та в≥дн≥манн€) Ц виконуЇ додаванн€ чи в≥дн≥манн€ певноњ
			к≥лькост≥ дн≥в до об'Їкта. “обто другим операндом буде ц≥ле число.
		[ () ] (кругл≥ дужки) Ц додаЇ до дати певне значенн€, маЇ 3 перевантаженн€:
		
		1.(int days) Ц додаЇ певну к≥льк≥сть дн≥в
		2.(int months, int days) Ц додаЇ певну к≥льк≥сть дн≥в та м≥с€ц≥в
		3.(int years, int months, int days) Ц додаЇ певну к≥льк≥сть дн≥в, м≥с€ц≥в та рок≥в
		
		ќператори ≥нкременту та декременту перевантажити за допомогою глобальних функц≥й.
		ќператори пор≥вн€нн€ Ц дружн≥ми функц≥€ми, вс≥ ≥нш≥ Ц методами класу.
	*/

	Date date(10, 10, 2025);
	cout << "DATE:  "; date.Print();

	++date;
	cout << "Result of (++x):  "; date.Print();
	date++;
	cout << "Result of (x++):  "; date.Print();
	--date;
	cout << "Result of (--x):  "; date.Print();
	date--;
	cout << "Result of (x--):  "; date.Print();

	cout << "_________________________________________________" << endl;

	Date date2(5, 5, 2025);
	cout << "Date 1 ---> "; date.Print();
	cout << "Date 2 ---> "; date2.Print();

	bool result = date > date2;
	cout << "date1 > date2? -->  " << result << endl;

	result = date == date2;
	cout << "date1 == date2? -->  " << result << endl;

	cout << "_________________________________________________" << endl;

	++date2;
	cout << "date 1 = "; date.Print();
	cout << "date 2 = "; date2.Print();
	result = date < date2;
	cout << "date1 < date2? -->  " << result << endl;

	cout << "_________________________________________________" << endl;

	cout << "Date 1 ---> "; date.Print();
	cout << "Date 2 ---> "; date2.Print();

	Date date3;
	date3 = date + date2;
	cout << "Date 3 = date1 + date2 --->   "; date3.Print();

	cout << "_________________________________________________" << endl;

	cout << "Date 3 ---> "; date3.Print();
	cout << "Date 2 ---> "; date2.Print();

	Date date4;
	date4 = date3 - date2;
	cout << "Date 4 = date3 - date2 --->   "; date3.Print();

	cout << "_________________________________________________" << endl;

	Date x_date(1, 2, 1000);
	cout << "DATE X = "; x_date.Print();

	x_date(45);
	cout << "x_date(45);  ---> "; x_date.Print();
	x_date(45, 24);
	cout << "x_date(45, 24);  ---> "; x_date.Print();
	x_date(12, 109, 45);
	cout << "x_date(12, 109, 45);  ---> "; x_date.Print();
}