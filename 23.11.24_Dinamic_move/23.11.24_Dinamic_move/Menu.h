#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Console.h"

using namespace std;

void SetColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

void AnyLine(int symbhol, int iter) 
{
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
void Enter(string text_to_add)
{
    float text_lenght = text_to_add.length();
    cout << " " << setw(text_lenght) << text_to_add << " ";
}
void Enter(int number, string text)
{
    if (number % 2 == 1)
        number++;

    for (int i = 0; i < number / 2; i++)
    {
        cout << " ";
    }
    cout << text;
    for (int i = 0; i < number / 2; i++)
    {
        cout << " ";
    }
}
void Enter(int color, int number, string text, bool blink)
{
    if (number % 2 == 1)
        number++;

    for (int i = 0; i < number / 2; i++)
    {
        cout << " ";
    }

    if (blink)
    {
        SetColor(color);
        cout << text;
        SetColor(7);
    }
    else
    {
        cout << text;
    }

    for (int i = 0; i < number / 2; i++) {
        cout << " ";
    }
}

void PRINTONETEXT(string text, int enter = 0)
{

    int fulllen = text.length() * 2;

    if (enter == 0)
    {
        enter = text.length();
    }
    else
    {
        fulllen = enter + text.length();
    }

    //      ┌───────────────────────────────────────────────────────┐
    AnyLine(218, 1);       AnyLine(196, fulllen);            AnyLine(191, 1);
    cout << endl;
    //      │                         TEXT                          │
    AnyLine(179, 1);     Enter(enter, text); AnyLine(179, 1);
    cout << endl;
    //      └───────────────────────────────────────────────────────┘
    AnyLine(192, 1);      AnyLine(196, fulllen);             AnyLine(217, 1);
    cout << endl;
}
int COLORTEXT(string text, int enter = 0)
{
    int fulllen = text.length() * 2;

    if (enter == 0)
    {
        enter = text.length();
    }
    else
    {
        fulllen = enter + text.length();
    }

    int i = 0;

    while (!_kbhit())
    {
        system("cls");
        //      ┌───────────────────────────────────────────────────────────┐
        AnyLine(218, 1);           AnyLine(196, fulllen);              AnyLine(191, 1);
        cout << endl;
        //      |                                                           |
        AnyLine(179, 1);
        if (i % 2 == 0) { Enter(7, enter, text, true); }
        else { Enter(8, enter, text, true); }
        AnyLine(179, 1);
        cout << endl;
        //      └───────────────────────────────────────────────────────────┘
        AnyLine(192, 1);           AnyLine(196, fulllen);              AnyLine(217, 1);
        cout << endl;

        Sleep(500); i++;
    }

    return 1;
}