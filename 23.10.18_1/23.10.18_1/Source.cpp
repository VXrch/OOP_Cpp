#include <iostream>

using namespace std;

class Time
{
	unsigned int seconds;
	unsigned int minutes;
	unsigned int hours;

	int totalSeconds;

public:

	Time() {
		seconds = 0;
		minutes = 0;
		hours = 0;
		totalSeconds = 0;
	}
	explicit Time(int value) : Time()
	{
		// (value / 3600 - h; value / 60 % 60 – m; value % 60 - s)

		seconds = value % 60;
		minutes = value / 60 % 60;
		hours = value / 3600;
	}
	explicit Time(unsigned int seconds) : Time()
	{
		if (IsAvailableTime_Sec_Min(seconds) == true) {
			this->seconds = seconds;
		}
		else {
			this->seconds = 0;
		}
	}
	Time(unsigned int seconds, unsigned int minutes) : Time()
	{
		if (IsAvailableTime_Sec_Min(seconds) == true) {
			this->seconds = seconds;
		}
		else {
			this->seconds = 0;
		}

		if (IsAvailableTime_Sec_Min(minutes) == true)
		{
			this->minutes = minutes;
		}
		else {
			this->minutes = 0;
		}
	}
	Time(unsigned int seconds, unsigned int minutes, unsigned int hours) {
		
		if (IsAvailableTime_Sec_Min(seconds) == true) {
			this->seconds = seconds;
		}
		else {
			this->seconds = 0;
		}

		if (IsAvailableTime_Sec_Min(minutes) == true)
		{
			this->minutes = minutes;
		}
		else {
			this->minutes = 0;
		}

		if (IsAvailableTime_Hours(hours) == true)
		{
			this->hours = hours;
		}
		else {
			this->hours = 0;
		}

		totalSeconds = 0;
	}

	bool IsAvailableTime_Sec_Min(int value) const
	{
		if (value < 60 && value >= 0){
			return true;
		}
		return false;
	}
	bool IsAvailableTime_Hours(int value) const
	{
		if (value < 24 && value >= 0) {
			return true;
		}
		return false;
	}

	void Print() const 
	{
		cout << hours << " : " << minutes << " : " << seconds << endl;
	}
	int TotalSeconds() {

		int value = 0;

		value += hours * 3600;
		value += minutes * 60;
		value += seconds;

		return value;
	}

	void operator++() {
		seconds += 1;
	}
	Time operator +(Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		Time result(this->totalSeconds + other.totalSeconds);

		return result;
	}
	Time operator -(Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		if (this->totalSeconds > other.totalSeconds)
		{
			Time result(this->totalSeconds - other.totalSeconds);
			return result;
		}
		else
		{
			Time result(this->totalSeconds - other.totalSeconds);
			return result;
		}
	}
	Time operator *(Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		Time result(this->totalSeconds * other.totalSeconds);

		return result;
	}
	Time operator /(Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		if (this->totalSeconds > other.totalSeconds)
		{
			Time result(this->totalSeconds / other.totalSeconds);
			return result;
		}
		else
		{
			Time result(this->totalSeconds / other.totalSeconds);
			return result;
		}
	}
	bool operator <(Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		if (this->totalSeconds < other.totalSeconds)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool operator >=( Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		return (this->totalSeconds >= other.totalSeconds);
	}
	bool operator <=( Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		return (this->totalSeconds <= other.totalSeconds);
	}
	bool operator ==( Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		return (this->totalSeconds == other.totalSeconds);
	}
	bool operator !=( Time& other) {

		this->totalSeconds = this->TotalSeconds();
		other.totalSeconds = other.TotalSeconds();

		return (this->totalSeconds != other.totalSeconds);
	}
};

void main() {

	/*Створити клас «Time», який буде описувати час 3 - ма характеристиками : 
			години, хвилини, секунди.
		В класі потрібно реалізувати наступні конструктори :
			Конструктор по замовчуванню() – встановлюватиме початкові дані
			Параметризований(hours, minutes, seconds) – встановлює кожну властивість
			Параметризований(seconds) – створює клас перевівши дану кількість секунд в години, хвилини, секунди.
				(Наприклад : 5555 = 1год 32хв 35сек)
				(5555 / 3600 - h; 5555 / 60 % 60 – m; 5555 % 60 - s)

		Також передбачити методи :
			Виводу часу на екран в форматі hh : mm:ss
			Збільшення часу на одну секунду(11:59 : 59)++ -> 12 : 00 : 00

		Клас повинен мати перевантаження наступних бінарних операторів :
			[ + ][ – ][ * ][ / ] --- виконується певна арифметична операція з часом та повертається результат 
									 у вигляді нового об'єкту Time> 
			[ < ][ >= ][ <= ] --- перевіряється, який об’єкт містить більшу/меншу кількість часу
								  та повертається результат у вигляді типу bool
			[ == ][ != ] --- перевіряється чи класи мають не/однаковий час

		Використайте explicit для деяких конструкторів.*/

	Time t1 (555);
	t1.Print();

	Time t2(555);
	t2.Print();

	Time t3;
	t3 = t1 * t2;
	t3.Print();
}