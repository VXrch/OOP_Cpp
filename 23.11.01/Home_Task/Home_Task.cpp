#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>

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
void PrintByNumber(int n)
{
    if (n== 1)
    {
        cout << char(197); // ┼
    }
    else if (n == 2)
    {
        cout << char(206); // ╬
    }
    else if (n == 3)
    {
        cout << char(176); // ░
    }
    else if (n == 4)
    {
        cout << char(219); // █
    }
}

const string text_menu = "MENU [0]";

void AnyLine(int symbhol, int iter) {

    for (int i = 0; i < iter; i++)
    {
        cout << (char)symbhol;
    }
}
void Enter(string text_to_add) {

    float text_lenght = text_to_add.length();
    cout << " " << setw(text_lenght) << text_to_add << " ";
}
void Enter(int number) 
{
    for (int i = 0; i < number; i++)
    {
        cout << " ";
    }
}
void Top(User user) {

    string text = GetBalance(user);
    //       ┌────────────────────────────────────────────────────────┬─────────────────────────────────────────────────────┬──────────────────────────────────────────────────────────┐
    AnyLine(218, 1);   AnyLine(196, (user.name.length() + 2));   AnyLine(194, 1); AnyLine(196, ((text.length()) + 2)); AnyLine(194, 1);    AnyLine(196, ((text_menu.length()) + 2));  AnyLine(191, 1);
    cout << endl;
    //       │                       USERNANE                         │                BALANCE: USER.BALANCE                │                          MENU [0]                        │
    AnyLine(179, 1);            Enter(user.name);                AnyLine(179, 1);           Enter(text);              AnyLine(179, 1);             Enter(text_menu);                  AnyLine(179, 1);
    cout << endl;
    //       └────────────────────────────────────────────────────────┴─────────────────────────────────────────────────────┴──────────────────────────────────────────────────────────┘
    AnyLine(192, 1);   AnyLine(196, (user.name.length() + 2));   AnyLine(193, 1); AnyLine(196, ((text.length()) + 2)); AnyLine(193, 1);    AnyLine(196, ((text_menu.length()) + 2));  AnyLine(217, 1);
    cout << endl;
}
void START(User user)
{
    string text = GetBalance(user);
    int full_lenght = 8 + user.name.length() + text_menu.length() + text.length();
    text = "press [ENTER] to START";
    //      ┌───────────────────────────────────────────────────────┐
    AnyLine(218, 1);       AnyLine(196, full_lenght);            AnyLine(191, 1);
    cout << endl;
    //      │                         START                         │
    AnyLine(179, 1); Enter(full_lenght/5); Enter(text);   Enter((full_lenght - (full_lenght / 5) - text.length()) - 2); AnyLine(179, 1);
    cout << endl;
    //      └───────────────────────────────────────────────────────┘
    AnyLine(192, 1);      AnyLine(196, full_lenght);             AnyLine(217, 1);
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GiantFrog();
int MainPage(User& user);
int DrumsSpin(User& user);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SmoothPhrase(int n1, int n2, int n3)
{
    int r_n_1;
    int r_n_2;
    int r_n_3;
    int delay = 100;

    for (int i = 0; delay < 1000; i++)
    {
        system("cls");
        r_n_1 = 1 + rand() % 4; r_n_2 = 1 + rand() % 4; r_n_3 = 1 + rand() % 4;

        cout << "\t\t";  PrintByNumber(r_n_1); PrintByNumber(r_n_2); PrintByNumber(r_n_3);
        this_thread::sleep_for(chrono::milliseconds(delay));
        delay += 50;
    }
    this_thread::sleep_for(chrono::milliseconds(1100));
    system("cls");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

        if (choice == 1) // Spin
        {
            DrumsSpin(user);
        }
        else if (choice == 0) // Menu
        {
            
        }
    }
}

int MainPage(User& user) //  Username / Balance / Menu / Start (200 w.)
{
    Top(user);
    START(user);

    bool ext = false;

    while (!ext)
    {
        int key = _getch();

        if (key == 13) // Enter
        {
            return 1;
        }
        else if (key == 48)
        {
            return 0;
        }
    }
}

void Menu() // Exit / spins history / return to spins
{

}

void FirstSpin() // Forced first spin (garantee win +100 w.)
{

}

int DrumsSpin(User& user) // Animated drums spins
{
    if (user.balance < 200)
        return -1;

    user.balance -= 200;

    int n1 = RandomiseProbabilities();
    int n2 = RandomiseProbabilities();
    int n3 = RandomiseProbabilities();

    SmoothPhrase(n1, n2, n3);

    if (n1 == n2 == n3) // if n1 n2 and n3 = thesame numbers
    {
        if (n1 == 1) // 1 + 1 + 1
        {
            cout << "+ 500!" << endl;
            user.balance += 500;
            return 31;
        }
        if (n1 == 2) // 2 + 2 + 2
        {
            cout << "+ 1,000!!" << endl;
            user.balance += 1000;
            return 32;
        }
        if (n1 == 3)  // 3 + 3 + 3
        {
            cout << "+ 10,000!!!" << endl;
            user.balance += 10000;
            return 33;
        }
        if (n1 == 4)  // 4 + 4 + 4
        {
            cout << "!!!  + 1,000,000  !!!" << endl;
            user.balance += 1000000;
            return 34;
        }
    }

    else if (n1 == n2 || n2 == n3 || n1 == n3) // if n1 and n2 = the same numbers
    {
        if ((n1 == n2 && n1 == 1) || (n2 == n3 && n1 == 1) || (n1 == n3 && n1 == 1)) // 1 + 1 + x
        {
            cout << "+ 50!" << endl;
            user.balance += 50;
            return 21;
        }
        if ((n1 == n2 && n1 == 2) || (n2 == n3 && n1 == 2) || (n1 == n3 && n1 == 2)) // 2 + 2 + x
        {
            cout << "+ 100!" << endl;
            user.balance += 100;
            return 22;
        }
        if ((n1 == n2 && n1 == 3) || (n2 == n3 && n1 == 3) || (n1 == n3 && n1 == 3))  // 3 + 3 + x
        {
            cout << "+ 1,000!!" << endl;
            user.balance += 1000;
            return 23;
        }
        if ((n1 == n2 && n1 == 4) || (n2 == n3 && n1 == 4) || (n1 == n3 && n1 == 4))  // 4 + 4 + x
        {
            cout << "+ 50,00!!!" << endl;
            user.balance += 50000;
            return 24;
        }
    }
    
    if (n1 == 1 || n2 == 1 || n3 == 1)
    {
        cout << "+ 0!" << endl;
        user.balance += 0;
    }
    
    if (n1 == 2 || n2 == 2 || n3 == 2)
    {
        cout << "+ 100!" << endl;
        user.balance += 100;
    }
    
    if (n1 == 3 || n2 == 3 || n3 == 3)
    {
        cout << "+ 500!!" << endl;
        user.balance += 500;
    }
    
    if (n1 == 4 || n2 == 4 || n3 == 4)
    {
        cout << "+ 1,000!!!" << endl;
        user.balance += 1000;
    }

    return 111;
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