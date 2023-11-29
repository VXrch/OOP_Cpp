#include <iostream>
#include <vector>

using namespace std;

enum Ingredients { None, tomatoes, mushrooms, chicken, pork, olives, corn, pineapples, cheese, karchofs, sausage };
enum Sauces { None, tomato, cheese, barbecue, taco, soy, tartar, mint, cranberry, hollandaise, mayonnaise, Garlic };

class Sauce
{
	vector<Sauces> sauses;
	vector<Ingredients> ingredients;

public:

	Sauce() : sauses(), ingredients() {}
	Sauce(vector<Sauces> sauses, vector<Ingredients> ingredients) : sauses(sauses), ingredients(ingredients) {}

	virtual void MakeSauce() = 0;
	void PrintPrescription()
	{
		bool printed = false;

		cout << "Prescription : " << endl;

		if (sauses.size() >= 0)
		{
			for (int i = 0; i < sauses.size(); i++)
			{
				cout << sauses[i] << ", ";
			}

			cout << endl;
			printed = true;
		}

		if (ingredients.size() >= 0)
		{
			cout << "\nIngredients to add: " << endl;

			for (int i = 0; i < ingredients.size(); i++)
			{
				cout << ingredients[i] << ", ";
			}

			cout << endl;
			printed = true;
		}

		if (printed == false)
		{
			cout << "Prescription is empty!" << endl;
		}
	}
};

class Pizza
{
	vector<Ingredients> ingredients;
	string dough;

public:

	Pizza() : ingredients(), dough("none") {}
	Pizza(vector<Ingredients> ingredients, string dough) : ingredients(ingredients), dough(dough){}

	virtual void MakePizza() = 0;
	void PrintPrescription()
	{
		bool printed = false;

		cout << "Prescription : " << endl;

		if (ingredients.size() >= 0)
		{
			for (int i = 0; i < ingredients.size(); i++)
			{
				cout << ingredients[i] << ", ";
			}

			cout << endl;
			printed = true;
		}

		cout << "Dough: " << endl;

		if (printed == false)
		{
			cout << "Prescription is empty!" << endl;
		}
	}
};

class Fabric
{
	



};

void main()
{
	/*
		�������� ���� ϳ�� � ����� ���������� ������� "����������� ���"
			� ����� ��� � ��� ���������: 
				�������� ��� �� ������� ���
			� ���� �� ���� ���������� ���������� ����� 
			������������ �����
			
		�������� ���� ���� � ����� ���������� ������� "����������� ����"
			��������� : ��������� ���� �� �������� ����

		�������� ���� ������� �� ������������ ��� � ����� ����������� ��������: 
			- ����������� ���
			- �����������  ����
			
			��� ����� ������� �������� ��� ��������� :
				�������̳��� �� ������������� � ���������� ���������� ������
		� ���� ���������� ���� ��� ������ � ���������
	*/

}