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

            cout << arr[i] << " | ";
        }

        cout << endl;
    }

    T_Stack operator [](int i)
    {
        return arr[i];
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
        T_Stack* new_arr = new T_Stack[size + 10];

        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }

        delete[]arr;
        arr = new_arr;
        size += 10;
    }
    bool Push(T_Stack elem)
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
        cout << char(184); // ©
    }
    else if (n == 3)
    {
        cout << char(128); // Ç
    }
    else if (n == 4)
    {
        cout << char(154); // Ü
    }
}

const string text_menu = "MENU [0]";

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AnyLine(int symbhol, int iter) {

    for (int i = 0; i < iter; i++)
    {
        cout << (char)symbhol;
    }
}
void Enter(int number) 
{
    for (int i = 0; i < number; i++)
    {
        cout << " ";
    }
}
void Enter(string text_to_add) {

    float text_lenght = text_to_add.length();
    cout << " " << setw(text_lenght) << text_to_add << " ";
}
void Enter(int number, string text)
{
    for (int i = 0; i < number/2; i++)
    {
        cout << " ";
    }
    cout << text;
    for (int i = 0; i < number / 2; i++)
    {
        cout << " ";
    }
}
void TOP(User user) {

    string text = GetBalance(user);
    //       ┌────────────────────────────────────────────────────────┬─────────────────────────────────────────────────────┬──────────────────────────────────────────────────────────┐
    AnyLine(218, 1);   AnyLine(196, (user.name.length() + 2));   AnyLine(194, 1); AnyLine(196, (text.length() + 2));   AnyLine(194, 1);    AnyLine(196, (text_menu.length() + 2));  AnyLine(191, 1);
    cout << endl;
    //       │                       USERNANE                         │                BALANCE: USER.BALANCE                │                          MENU [0]                        │
    AnyLine(179, 1);            Enter(user.name);                AnyLine(179, 1);           Enter(text);               AnyLine(179, 1);             Enter(text_menu);               AnyLine(179, 1);
    cout << endl;
    //       └────────────────────────────────────────────────────────┴─────────────────────────────────────────────────────┴──────────────────────────────────────────────────────────┘
    AnyLine(192, 1);   AnyLine(196, (user.name.length() + 2));   AnyLine(193, 1); AnyLine(196, (text.length() + 2));   AnyLine(193, 1);    AnyLine(196, text_menu.length() + 2);    AnyLine(217, 1);
    cout << endl;
}
void START(User user)
{
    string text = GetBalance(user);
    int full_lenght = 8 + user.name.length() + text_menu.length() + text.length();
    text = "press [ENTER] to START (200 w)";
    //      ┌───────────────────────────────────────────────────────┐
    AnyLine(218, 1);       AnyLine(196, full_lenght);            AnyLine(191, 1);
    cout << endl;
    //      │                         START                         │
    AnyLine(179, 1);     Enter((full_lenght - text.length()), text); AnyLine(179, 1);
    cout << endl;
    //      └───────────────────────────────────────────────────────┘
    AnyLine(192, 1);      AnyLine(196, full_lenght);             AnyLine(217, 1);
    cout << endl;
}
void MENU()
{
    string t1 = "EXIT [1]";
    string t2 = "SPINS HISTORY [2]";
    string t3 = "RETURN TO MAIN [3]";
    int len = t3.length() + 10;

    //      ┌─────────────────────────────────────────────┬─────────────────────────────────────────────────┬────────────────────────────────────────────────┐
    AnyLine(218, 1);       AnyLine(196, len);       AnyLine(194, 1);        AnyLine(196, len);        AnyLine(194, 1);          AnyLine(196, len);           AnyLine(191, 1);
    cout << endl;
    //      │                    EXIT                     │               SPINS HISTORY                     │            RETURN TO MAIN PAGE                 │
    AnyLine(179, 1); Enter((len - t1.length() + 1), t1); AnyLine(179, 1); Enter((len - t2.length()), t2); cout << " "; AnyLine(179, 1); Enter((len - t3.length()), t3); AnyLine(179, 1);
    cout << endl;
    //      └─────────────────────────────────────────────┴─────────────────────────────────────────────────┴────────────────────────────────────────────────┘
    AnyLine(192, 1);       AnyLine(196, len);       AnyLine(193, 1);        AnyLine(196, len);        AnyLine(193, 1);          AnyLine(196, len);           AnyLine(217, 1);
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GiantFrog();
int MainPage(User& user);
int Menu();

template<typename T>
int DrumsSpin(User& user, Stack<T>& history);

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

        cout << "\t\t";  PrintByNumber(r_n_1); cout << " "; PrintByNumber(r_n_2); cout << " "; PrintByNumber(r_n_3);
        this_thread::sleep_for(chrono::milliseconds(delay));
        delay += 50;
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
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
    
    Stack<int> history;

    User user;
    cout << "Enter your username: "; cin >> user.name;
    
    bool ext = false;
    int choice;

    while (!ext)
    {
        choice = MainPage(user);

        if (choice == 1) // Spin
        {
            DrumsSpin(user, history);
        }
        else if (choice == 0) // Menu
        {
            choice = Menu();

            if (choice == 0)
            {
                // BYE!
                cout << "Bye!" << endl;
                ext = true;
            }
        }
    }
}

int MainPage(User& user) //  Username / Balance / Menu / Start (200 w.)
{
    TOP(user);
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
        else if (key == 70)
        {
            system("cls");
            GiantFrog();
            system("pause");
            system("cls");
            return 0;
        }
    }
}
int Menu()
{
    MENU();

    bool ext = false;

    while (!ext)
    {
        int key = _getch();

        if (key == 49) // Exit
        {
            ext = true;
            return 0;
        }
        else if (key == 50) // History
        {
            
        }
        else if (key == 51) // Return
        {
            
        }
        else if (key == 70) // Frog :)
        {
            system("cls");
            GiantFrog();
            system("pause");
            system("cls");
        }
    }
}

template<typename T>
int DrumsSpin(User& user, Stack<T>& history) // Animated drums spins
{
    if (user.balance < 200)
        return -1;

    user.balance -= 200;
    int result = 0;

    int n1 = RandomiseProbabilities();
    int n2 = RandomiseProbabilities();
    int n3 = RandomiseProbabilities();

    SmoothPhrase(n1, n2, n3);

    if (n1 == n2 == n3) // if n1 n2 and n3 = thesame numbers
    {
        if (n1 == 1) // 1 + 1 + 1
        {
            cout << "+ 500!" << endl;
            result += 500;
        }
        if (n1 == 2) // 2 + 2 + 2
        {
            cout << "+ 1,000!!" << endl;
            result += 1000;
        }
        if (n1 == 3)  // 3 + 3 + 3
        {
            cout << "+ 10,000!!!" << endl;
            result += 10000;
        }
        if (n1 == 4)  // 4 + 4 + 4
        {
            cout << "!!!  + 1,000,000  !!!" << endl;
            result += 1000000;
        }
    }

    else if (n1 == n2 || n2 == n3 || n1 == n3) // if n1 and n2 = the same numbers
    {
        if ((n1 == n2 && n1 == 1) || (n2 == n3 && n1 == 1) || (n1 == n3 && n1 == 1)) // 1 + 1 + x
        {
            cout << "+ 100!" << endl;
            result += 100;
        }
        if ((n1 == n2 && n1 == 2) || (n2 == n3 && n1 == 2) || (n1 == n3 && n1 == 2)) // 2 + 2 + x
        {
            cout << "+ 200!" << endl;
            result += 200;
        }
        if ((n1 == n2 && n1 == 3) || (n2 == n3 && n1 == 3) || (n1 == n3 && n1 == 3))  // 3 + 3 + x
        {
            cout << "+ 500!!" << endl;
            result += 500;
        }
        if ((n1 == n2 && n1 == 4) || (n2 == n3 && n1 == 4) || (n1 == n3 && n1 == 4))  // 4 + 4 + x
        {
            cout << "+ 1,000!!!" << endl;
            result += 1000;
        }
    }

    if (n1 == 1 || n2 == 1 || n3 == 1)
    {
        cout << "+ 0!" << endl;
    }

    if (n1 == 2 || n2 == 2 || n3 == 2)
    {
        cout << "+ 10!" << endl;
        result += 10;
    }

    if (n1 == 3 || n2 == 3 || n3 == 3)
    {
        cout << "+ 50!!" << endl;
        result += 50;
    }

    if (n1 == 4 || n2 == 4 || n3 == 4)
    {
        cout << "+ 100!!!" << endl;
        result += 100;
    }

    user.balance += result;
    history.Push(result);

    return result;
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