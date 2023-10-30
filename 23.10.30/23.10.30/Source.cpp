#include <iostream>

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
    bool IsEmpty()const{
        return topIndex == EMPTY;
    }

    void Print()
    {
        for (int i = 0; i <= topIndex; i++){

            cout << arr[i] << " - ";
        }
        
        cout << endl;
    }
    int GetCount()const{
        return topIndex + 1;
    }
    int Peek() // повертаЇ останн≥й елемент без видаленн€ з≥ стеку
    {

        if (!IsEmpty()) {
            return arr[topIndex];
        }

        return 0;
    }

    bool Push(int elem) // додаЇ новий елемент в стек
    {
        if (!IsFull()){

            arr[++topIndex] = elem;
            return true;
        }

        return false;
    }
    int Pop() // вит€гуЇ останн≥й елемент з стеку
    {
        if (!IsEmpty()) { 
            return arr[topIndex--]; 
        }

        return 0;
    }
    void Clear(){
        topIndex = EMPTY;
    }

    ~Stack()
    {
        delete[]arr;
    }
};

bool IsValidCode(string code)
{
    Stack<char> st_figure(10);
    Stack<char> st_square(10);
    Stack<char> st_round(10);

    for (char symbol : code){

        if (symbol == '{')
        {
            st_figure.Push(1);
        }
        else if (symbol == '}')
        {
            if (st_figure.IsEmpty())
                return false;

            st_figure.Pop();
        }

        ////////////////////////////

        if (symbol == '[')
        {
            st_square.Push(1);
        }
        else if (symbol == ']')
        {
            if (st_square.IsEmpty())
                return false;

            st_square.Pop();
        }

        ////////////////////////////

        if (symbol == '(')
        {
            st_round.Push(1);
        }
        else if (symbol == ')')
        {
            if (st_round.IsEmpty())
                return false;

            st_round.Pop();
        }
    }

    if (st_figure.IsEmpty() && st_square.IsEmpty() && st_round.IsEmpty()) {
        return true;
    }
    return false;
}


void main()
{
    //                           «авданн€ 1:
    //      —творити клас, €кий описуЇ структуру даних ЂStackї.
    // 
    //       лас м≥стить наступн≥ пол€ :
    //          колекц≥€ елемент≥в (динам≥чний масив)
    //          вершина(≥ндекс останнього елемента)
    //      
    //      –еал≥зувати наб≥р стандартних метод≥в :
    //          Push Ц додаЇ новий елемент в стек
    //          Pop Ц вит€гуЇ останн≥й елемент з стеку
    //          Peek Ц повертаЇ останн≥й елемент без видаленн€ з≥ стеку
    //          GetCount Ц повертаЇ к≥льк≥сть елемент≥в
    //          IsEmpty Ц перев≥р€Ї чи стек порожн≥й    
    //          IsFull Ц перев≥р€Ї чи стек повн≥стю заповнений
    //      
    //       лас обовТ€зково повинен мати конструктор за замовчуванн€м  
    //              та конструктор, €кий приймаЇ максимальний розм≥р стека.
    //       лас повинен бути шаблонним, тобто мати можлив≥сть збер≥гати будь - €кий тип даних.
    //      ќписати наб≥р необх≥дних компонент≥в дл€ коректноњ роботи класу.


    string code = "class Stack{ void Print(){for(.....){if(.....){.....}}}};";
    if (IsValidCode(code))
        cout << "Valid code" << endl;
    else
        cout << "Invalid code" << endl;
}
