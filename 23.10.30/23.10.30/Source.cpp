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
    int Peek() // ������� ������� ������� ��� ��������� � �����
    {

        if (!IsEmpty()) {
            return arr[topIndex];
        }

        return 0;
    }

    bool Push(int elem) // ���� ����� ������� � ����
    {
        if (!IsFull()){

            arr[++topIndex] = elem;
            return true;
        }

        return false;
    }
    int Pop() // ������ ������� ������� � �����
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
    //                           �������� 1:
    //      �������� ����, ���� ����� ��������� ����� �Stack�.
    // 
    //      ���� ������ ������� ���� :
    //          �������� �������� (��������� �����)
    //          �������(������ ���������� ��������)
    //      
    //      ���������� ���� ����������� ������ :
    //          Push � ���� ����� ������� � ����
    //          Pop � ������ ������� ������� � �����
    //          Peek � ������� ������� ������� ��� ��������� � �����
    //          GetCount � ������� ������� ��������
    //          IsEmpty � �������� �� ���� �������    
    //          IsFull � �������� �� ���� ������� ����������
    //      
    //      ���� ���������� ������� ���� ����������� �� �������������  
    //              �� �����������, ���� ������ ������������ ����� �����.
    //      ���� ������� ���� ���������, ����� ���� ��������� �������� ���� - ���� ��� �����.
    //      ������� ���� ���������� ���������� ��� �������� ������ �����.


    string code = "class Stack{ void Print(){for(.....){if(.....){.....}}}};";
    if (IsValidCode(code))
        cout << "Valid code" << endl;
    else
        cout << "Invalid code" << endl;
}
