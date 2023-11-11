#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

template <typename T_Stack>
class Stack
{
    enum { EMPTY = -1 };
    T_Stack* arr;
    int size;
    int topIndex;

public:

    Stack() {

        size = 10;
        arr = new T_Stack[size];
        topIndex = EMPTY;
    }
    Stack(int size) : size(size)
    {
        arr = new T_Stack[size];
        topIndex = EMPTY;
    }

    bool IsFull()const
    {
        return topIndex == size - 1;
    }
    bool IsEmpty()const {
        return topIndex == EMPTY;
    }

    void Print()
    {
        for (int i = 0; i <= topIndex; i++) {

            cout << arr[i] << " - ";
        }

        cout << endl;
    }
    int GetCount()const {
        return topIndex + 1;
    }
    int Peek()
    {

        if (!IsEmpty()) {
            return arr[topIndex];
        }

        return 0;
    }

    void Expand()
    {
        T_Stack* new_arr = T_Stack[size + 10];

        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }

        delete[]arr;
        arr = new_arr;
        size += 10;
    }
    bool Push(int elem)
    {
        if (!IsFull()) {

            arr[++topIndex] = elem;
            return true;
        }

        Expand();
        arr[++topIndex] = elem;
        return true;
    }
    int Pop()
    {
        if (!IsEmpty()) {
            return arr[topIndex--];
        }

        return 0;
    }
    void Clear() {
        topIndex = EMPTY;
    }

    ~Stack()
    {
        delete[]arr;
    }
};
struct User
{
    string name;
    int balance;

    User() : name(name), balance(500) {}
};

int RandomiseProbabilities() {

    float probabilities[] = { 0.35, 0.3, 0.2, 0,15 };
    
    float randomValue = static_cast<float>(rand()) / RAND_MAX;
    float cumulativeProbability = 0.0;

    for (int i = 0; i < sizeof(probabilities) / sizeof(probabilities[0]); ++i) 
    {
        cumulativeProbability += probabilities[i];

        if (randomValue < cumulativeProbability) 
        {
            if (i == 4)
            {
                return 4;
            }
            return i + 1;
        }
    }
}
string GetBalance(User user)
{
    string text = "BALANCE: " + to_string(user.balance) + " woolongs";
    return text;
}

const string text_menu = "MENU [0]";

void AnyLine(int symbhol, int iter) {

    for (int i = 0; i < iter; i++)
    {
        cout << (char)symbhol;
    }
}
void Enter(int number, string text_to_add) {
    cout << setw(number - 1) << text_to_add << " ";
}
void Top(User user) {

    string text = GetBalance(user);
    AnyLine(218, 1); AnyLine(196, (user.name.length() + 1)); AnyLine(194, 1); AnyLine(196, ((text.length()) + 1)); AnyLine(194, 1); AnyLine(196, ((text_menu.length()) + 2)); AnyLine(191, 1);
    cout << endl;
    AnyLine(179, 1); Enter(3, user.name); AnyLine(179, 1); Enter(6, text); AnyLine(179, 1); Enter(2, text_menu); cout << " "; AnyLine(179, 1);
    cout << endl;
    AnyLine(192, 1); AnyLine(196, (user.name.length() + 1)); AnyLine(193, 1); AnyLine(196, ((text.length()) + 1)); AnyLine(193, 1); AnyLine(196, ((text_menu.length()) + 2)); AnyLine(217, 1);
    cout << endl;
}
void START()
{
    string text = "START";
    AnyLine(218, 1); AnyLine(196, ((text.length()) + 10)); AnyLine(191, 1);
    cout << endl;
    AnyLine(179, 1); Enter(3, text); Enter(text.length(), ""); AnyLine(179, 1);
    cout << endl;
    AnyLine(192, 1); AnyLine(196, ((text.length()) + 10)); AnyLine(217, 1);
    cout << endl;
}

void GiantFrog();
int MainPage(User user);

void main()
{
    /*
                    Тема: Динамічні структури даних — стек
                                
                                Завдання N2
            Змініть стек з першого завдання зі статичного типу на
            динамічний(за нестачі вільного місця потрібно змінити
            розмір внутрішнього масиву без втрати даних).
            
                                Завдання N3
                Створити імітацію гри "однорукий бандит".
                
            Наприклад, при натисканні кнопки «Enter» відбувається «обертання»
            трьох барабанів (кількість обертань кожного з них вибирається випадково),
            на яких зображені різні значки і якщо випадає певна комбінація, 
            то гравець отримує якийсь виграш.
            Виконати дане завдання з використанням Queue (данімічна структура даних - черга).
    */

    srand(time(NULL));
    
    User user;
    cout << "Enter your username: "; cin >> user.name;
    
    bool ext = false;
    int choice;

    while (!ext)
    {
        choice = MainPage(user);
    }
}

int MainPage(User user) //  Username / Balance / Menu / Start (200 w.)
{
    Top(user);
    START();

    int key = _getch();

    if (key == 13) // Enter
    {
        return 1;
    }
    else if (key == 1)
    {
        return 0;
    }
}

void Menu() // Exit / balance / spins history 
{

}

void FirstSpin() // Forced first spin (garantee win +100 w.)
{

}

void DrumsSpin() // Animated drums spins
{


}

void GiantFrog()
{
    cout << "                                     .-----." << endl;
    cout << "                                    /   .  (" << endl;
    cout << "                                   /   .-.  \\" << endl;
    cout << "                                  /   /   \\  \\" << endl;
    cout << "                                 / `  )   (   )" << endl;
    cout << "                                / `   )   ).  \\" << endl;
    cout << "                              .'  _.   \\_/  . |" << endl;
    cout << "             .--.           .' _.' )`.        |" << endl;
    cout << "            (    `---...._.'   `---.'_)    ..  \\" << endl;
    cout << "             \\            `----....___    `. \\  |" << endl;
    cout << "              `.           _ ----- _   `._  )/  |" << endl;
    cout << "                `.       /\"  \\   /\"  \\`.  `._   |" << endl;
    cout << "                  `.    ((O)` ) ((O)` ) `.   `._\\" << endl;
    cout << "                    `-- '`---'   `---' )  `.    `-." << endl;
    cout << "                   /                  ` \\      `-." << endl;
    cout << "                 .'                      `.       `." << endl;
    cout << "                /                     `  ` `.       `-." << endl;
    cout << "         .--.   \\ ===._____.======. `    `   `. .___.--`     .''''." << endl;
    cout << "        ' .` `-. `.                )`. `   ` ` \\          .' . '   )" << endl;
    cout << "       (  .  ` `-.`.               ( .  ` `  .`\\      .'  '    '  /" << endl;
    cout << "        \\  `. `    `-.               ) ` .   ` ` \\  .'   ' .  '  /" << endl;
    cout << "         \\ ` `.  ` . \\`.    .--.     |  ` ) `   .``/   '  // .  /" << endl;
    cout << "          `.  ``. .   \\ \\   .-- `.  (  ` /_   ` . / ' .  '/   .'" << endl;
    cout << "            `. ` \\  `  \\ \\  '-.   `-'  .'  `-.  `   .  .'/  .'" << endl;
    cout << "              \\ `.`.  ` \\ \\    ) /`._.`       `.  ` .  .'  /" << endl;
    cout << "               |  `.`. . \\ \\  (.'               `.   .'  .'" << endl;
    cout << "            __/  .. \\ \\ ` ) \\                     \\.' .. \\__" << endl;
    cout << "     .-._.-'     '\"  ) .-'   `.                   (  '\"     `-._.--." << endl;
    cout << "    (_________.-====' / .' /\\_)`--..__________..-- `====-. _________)" << endl;
    cout << "                     (.'(.'" << endl;
}