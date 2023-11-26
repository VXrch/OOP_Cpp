#include <Windows.h>
#include <chrono>
#include <conio.h>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include"Console.h"

enum Direction { LEFT, RIGHT, UP, DOWN };

struct coord
{
    int col;
    int row;

    coord(int col, int row) : col(col), row(row) {}
};

void FromFile(vector<coord>& coordinates, string FILENAME);
void ToFile(vector<coord>& trains, string FILENAME);

class Hero
{
    int hp;
    int h, w;
    COORD position;
    string name;
    char symbol;
    Direction dir;

    void Print(char filler)const
    {
        for (int i = 0; i < h; i++)
        {
            gotoxy(position.X, position.Y + i);
            for (int j = 0; j < w; j++)
            {
                cout << filler;
            }
            cout << endl;
        }
    }

public:

    Hero() :hp(100), h(1), w(1), position({ 0,0 }), name("no name"), symbol('#'), dir(RIGHT) {}
    Hero(string name, int h, int w, char symbol) :hp(100), position({ 0,0 }), dir(RIGHT), name(name), symbol(symbol)
    {
        this->h = h >= 1 ? h : 1;
        this->w = w >= 1 ? w : 1;      
    }
    
    void ShowInfo()const
    {
        cout << "--------------- Player [" << name << "] Hp : " << hp << "-------------" << endl;
    }
    bool IsValidPosition(int x, int y)
    {
        return x >= 0 && y >= 0;
    }

    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }

    void Move(int color)
    {
        ClearHero();

        bool isMoved = false;
        
        switch (dir)
        {
        case LEFT:isMoved = MoveLeft(); break;
        case RIGHT:isMoved = MoveRight(); break;
        case UP:isMoved = MoveUp(); break;
        case DOWN:isMoved = MoveDown(); break;
        }

        isMoved ? PrintHero(color) : MarkHero();
    }

    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }

    bool MoveRight()
    {
        if (IsValidPosition(position.X + 1, position.Y))
        {
            position.X++;
            return true;
        }
        return false;

    }
    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {
            position.X--;
            return true;
        }
        return false;

    }
    bool MoveDown()
    {
        if (IsValidPosition(position.X, position.Y + 1))
        {
            position.Y++;
            return true;
        }
        return false;
    }
    bool MoveUp()
    {
        if (IsValidPosition(position.X, position.Y - 1))
        {
            position.Y--;
            return true;
        }
        return false;
    }

    void PrintHero(int color)const
    {
        ChangeColor(color);
        Print(symbol);
    }
    void MarkHero()const
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::MAGENTA);
        Print(symbol);
    }
    void ClearHero()const
    {
        Print((char)219);
    }
    void ChangeColor(int color)const
    {
        switch (color)
        {
        case 49: SetConsoleTextAttribute(hConsole, ConsoleColors::BLACK); break;
        case 50: SetConsoleTextAttribute(hConsole, ConsoleColors::WHITE); break;
        case 51: SetConsoleTextAttribute(hConsole, ConsoleColors::RED); break;
        case 52: SetConsoleTextAttribute(hConsole, ConsoleColors::BLUE); break;
        case 53: SetConsoleTextAttribute(hConsole, ConsoleColors::CYAN); break;
        case 54: SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW); break;
        case 55: SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN); break;
        case 56: SetConsoleTextAttribute(hConsole, ConsoleColors::LIGHT_GREEN); break;
        case 57: SetConsoleTextAttribute(hConsole, ConsoleColors::BROWN); break;
        default: break;
        }
    }

    void SetCursorPosition(int col, int row, int color = 49, char symbhol = char(219))
    {
        gotoxy(col, row);
        ChangeColor(color);
        cout << symbhol;
    }
    void PrintByCoordinates(vector<coord> black, int color = 49)
    {
        for (int i = 0; i < black.size(); i++)
        {
            SetCursorPosition(black[i].col, black[i].row, color);
        }
    }

    void Mushroom()
    {
        vector<coord> mushroom_black;
        FromFile(mushroom_black, "Mushroom_black.txt");
        PrintByCoordinates(mushroom_black);
    }
};

void ToFile(vector<coord>& trains, string FILENAME)
{
    ofstream outputFile(FILENAME);

    if (!outputFile.is_open())
    {
        cout << "Can't open file: " << FILENAME << endl;
        return;
    }

    for (int i = 0; i < trains.size(); i++)
    {
        outputFile << trains[i].col << endl;
        outputFile << trains[i].row << endl;
    }

    outputFile.close();
}
void FromFile(vector<coord>& coordinates, string FILENAME)
{
    ifstream inputFile(FILENAME);

    if (!inputFile.is_open())
    {
        cout << "Can't open file: " << FILENAME << endl;
        return;
    }

    string s_col, s_row;
    int col = 0, row = 0;

    int i = 0;

    while (!inputFile.eof())
    {
        getline(inputFile, s_col);

        if (s_col.empty())
            break;

        col = stoi(s_col);

        getline(inputFile, s_row);
        row = stoi(s_row);

        coord coordinate(col, row);
        coordinates.push_back(coordinate);

        i++;
    }

    inputFile.close();
}

int main()
{
    system("color 70");

    hidecursor();
    Hero hero("Bill", 1, 2, (char)219);
    hero.ShowInfo();
    hero.Mushroom();
    hero.SetCursorPosition(0, 0);

    /*hero.SetPosition(10, 10);
    time_t interval = 500;
    time_t start = clock();
    int key;

    int color = 49;

    while (true)
    {
        if (clock() >= start + interval)
        {
            hero.Move(color);
            start = clock();
        }

        if (_kbhit())
        {
            key = _getch();

            if (key == 224)
            {
                key = _getch();

                switch (key)
                {
                case 77:hero.ChangeDirection(RIGHT); break;
                case 80:hero.ChangeDirection(DOWN); break;
                case 72:hero.ChangeDirection(UP); break;
                case 75:hero.ChangeDirection(LEFT); break;
                }
            }
            else if (key >= 49 && key <= 57)
            {
                color = key;
            }
        }
    }*/
}
