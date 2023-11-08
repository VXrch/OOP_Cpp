#include <iostream>

using namespace std;

class Animal
{
protected:

	string type;
	int speed;
	int weight;
	int age;
	string environment;

	void Voice(string sound)
	{
		cout << sound << "!" << endl;
	}

public:

	Animal() : type("No type"), speed(0), weight(0), age(0), environment("No environment") {}
	Animal(string type, int speed, int weight, int age, string environment) : type(type), speed(speed), weight(weight), age(age), environment(environment) {}

	void Show()
	{
		cout << "Type: " << type << endl;
		cout << "Speed: " << speed << endl;
		cout << "Weight: " << weight << endl;
		cout << "Age: " << age << endl;
		cout << "Environment: " << environment << endl;
	}
	void Move(string move)
	{
		cout << "I am moveng! I am " << move << "ing!" << endl;
	}
	void Jump()
	{
		cout << "Jump!" << endl;
	}

	/*						Завдання 1:
			Створити базовий клас «Animal», який буде описувати тварину. 

			Цей клас буде містити загальні характеристики, які притаманні 
			кожній тварині:
			•вид
			•швидкість
			•вага
			•середовище мешкання
			•і тд…

			А також методи:
			• Move – метод руху
			• Show – вивід інформації на екран
			• Say – подача звуку
			• і тд…	

			Створити похідні класи: Bird, Reptile, Fish.
			Ці класи будуть наслідувати базовий клас Animal, додаючи до 
			нього певні характкристики та методи, які притаманні кожному об’єкту.

			Для кожного з видів створити хоча б по одному класу, який 
			буде описувати конкретну тварину-представника. 
			Ці класи повинні наслідувати характерний для них базовий клас 
			(Bird, Reptile, Fish) та ініціалізувати їхні характеристики 
			відповідно до тварини-представника.
	*/
};

class Bird : public Animal
{
	string fly;
	string sound;

public:

	Bird() : fly("Can fly"), sound("Chirick"), Animal() {};
	Bird(string fly, string sound, string type, int speed, int weight, int age, string environment) : fly(fly), sound(sound), Animal(type, speed, weight, age, environment) {};

	void Show()
	{
		Animal::Show();

		cout << "Fly: " << fly << endl;
		cout << "Sound: " << sound << endl;
	}
	void Voice()
	{
		Animal::Voice(sound);
	}
	void Move()
	{
		Animal::Move(fly);
	}
};

class Reptile : public Animal
{
	string crawl;
	string sound;

public:

	Reptile() : crawl("Can crawl"), sound("Shhhh"), Animal() {};
	Reptile(string crawl, string sound, string type, int speed, int weight, int age, string environment) : crawl(crawl), sound(sound), Animal(type, speed, weight, age, environment) {};

	void Show()
	{
		Animal::Show();

		cout << "Crawl: " << crawl << endl;
		cout << "Sound: " << sound << endl;
	}
	void Voice()
	{
		Animal::Voice(sound);
	}
	void Move()
	{
		Animal::Move(crawl);
	}
};

class Fish : public Animal
{
	string swim;
	string sound;

public:

	Fish() : swim("Can swim"), sound("OOOO"), Animal() {};
	Fish(string swim, string sound, string type, int speed, int weight, int age, string environment) : swim(swim), sound(sound), Animal(type, speed, weight, age, environment) {};

	void Show()
	{
		Animal::Show();

		cout << "swim: " << swim << endl;
		cout << "Sound: " << sound << endl;
	}
	void Voice()
	{
		Animal::Voice(sound);
	}
	void Move()
	{
		Animal::Move(swim);
	}
};

void main()
{
	cout << "\n_______________________________________________________________________\n" << endl;

	Animal a;
	a.Show();

	cout << "\n_______________________________________________________________________\n" << endl;

	Bird b("Can fly", "Chirp-chirp-chirp", "Small bird", 12, 1, 1, "Forest");
	b.Show();
	b.Jump();
	b.Voice();

	cout << "\n_______________________________________________________________________\n" << endl;

	Reptile c("Can crowl", "Hisssss", "Snake", 6, 15, 5, "Forest");
	c.Show();
	c.Move();
	c.Voice();

	cout << "\n_______________________________________________________________________\n" << endl;

	Fish d("Can swim", "Splash", "Salmon", 19, 3, 2, "Ocean");
	d.Show();
	d.Move();
	d.Voice();

	cout << "\n_______________________________________________________________________\n" << endl;
}