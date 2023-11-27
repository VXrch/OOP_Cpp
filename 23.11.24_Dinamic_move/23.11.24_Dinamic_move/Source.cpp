#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include"Console.h"
#include"Menu.h"

enum Direction { LEFT, RIGHT, UP, DOWN };

class Move
{
protected:

    int h, w;
    COORD position;
    Direction dir;
    
public:

    Move() : h(1), w(2), position({0, 0}), dir(RIGHT) {}
    Move(int h, int w, COORD pos, Direction dir) : h(h), w(w), position(pos), dir(dir) {}

    bool IsValidPosition(int x, int y)
    {
        return x >= 0 && y >= 0;
    }

    void PlusCoordinateX(vector<COORD>& vector_of_COORDs)
    {
        for (int i = 0; i < vector_of_COORDs.size(); i++)
        {
            vector_of_COORDs[i].X++;
        }
    }
    void PlusCoordinateY(vector<COORD>& vector_of_COORDs, int plus = 1)
    {
        for (int i = 0; i < vector_of_COORDs.size(); i++)
        {
            vector_of_COORDs[i].Y += plus;
        }
    }

    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }

    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }

    bool MoveRight()
    {
        if (IsValidPosition(position.X + 1, position.Y))
        {
            position.X += 2;
            return true;
        }
        return false;

    }
    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {
            position.X -= 2;
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

    void ChangeColor(int Xor)const
    {
        switch (Xor)
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

    void SetCursorPosition(int X, int Y, int Xor = 49, char symbhol = char(219))
    {
        gotoxy(X, Y);
        ChangeColor(Xor);
        cout << symbhol;
    }
    void PrintByCoordinates(vector<COORD> black, int Xor = 49)
    {
        for (int i = 0; i < black.size(); i++)
        {
            SetCursorPosition(black[i].X, black[i].Y, Xor);
        }
    }

};

class Hero : public Move
{
    struct Player
    {
        string name;
        int hp;

        Player(string name, int hp) : name(name), hp(hp) {}
    };
    
    void MovePlayer(int color)
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

    Player player;
    char symbol;
    
    void Print(char symbol)const
    {
        for (int i = 0; i < h; i++)
        {
            gotoxy(position.X, position.Y + i);
            for (int j = 0; j < w; j++)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }

public:

    Hero(string name, int hp, char symbol, int h, int w, COORD pos, Direction dir) : symbol(symbol), player(name, hp), ::Move(h, w, pos, dir) {}
    
    void ShowInfo()const
    {
       
    }
    
    void PrintHero(int Xor)const
    {
        ChangeColor(Xor);
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

    void ToFile(vector<COORD>& trains, string FILENAME)
    {
        ofstream outputFile(FILENAME);

        if (!outputFile.is_open())
        {
            cout << "Can't open file: " << FILENAME << endl;
            return;
        }

        for (int i = 0; i < trains.size(); i++)
        {
            outputFile << trains[i].X << endl;
            outputFile << trains[i].Y << endl;
        }

        outputFile.close();
    }
    void FromFile(vector<COORD>& COORDinates, string FILENAME)
    {
        ifstream inputFile(FILENAME);

        if (!inputFile.is_open())
        {
            cout << "Can't open file: " << FILENAME << endl;
            return;
        }

        string s_X, s_Y;
        int X = 0, Y = 0;

        int i = 0;

        while (!inputFile.eof())
        {
            getline(inputFile, s_X);

            if (s_X.empty())
                break;

            X = stoi(s_X);

            getline(inputFile, s_Y);
            Y = stoi(s_Y);

            COORD coordinates;
            coordinates.X = X;
            coordinates.Y = Y;
            COORDinates.push_back(coordinates);

            i++;
        }

        inputFile.close();
    }

    void Mushroom()
    {
        vector<COORD> mushroom_black;
        FromFile(mushroom_black, "Mushroom_black.txt");
        PrintByCoordinates(mushroom_black);
        PrintByCoordinates(mushroom_black);
    }

    void Start()
    {
        
    }
};

int main()
{
    system("Xor 70");

    hidecursor();
    /*Hero hero((char)219);
    hero.Mushroom();
    hero.SetCursorPosition(25, 25);

    hero.SetPosition(10, 10);
    time_t interval = 500;
    time_t start = clock();
    int key;

    int Xor = 49;*/

    /*while (true)
    {
        if (clock() >= start + interval)
        {
            hero.Move(Xor);
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
                Xor = key;
            }
        }
    }*/
}
