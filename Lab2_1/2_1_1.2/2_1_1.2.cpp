#include <iostream>
#include <deque>
#include <queue>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::deque;
using std::queue;
using std::stack;

// Задание 1.2

void AddCPU();
void PrintQ();
void PrintAQ();
void PrintMultiCoreCPU();

struct CPU
{
    string name;
    float freq;
    int cores;
};

queue <CPU> q;
queue <CPU> aq;
int parity = 0;

int main()
{
    string input;
    while (cin >> input)
    {
        if (input == "exit")
        {
            return 0;
        }
        else if (input == "add_CPU")
        {
            AddCPU();
        }
        else if (input == "CPU_list")
        {
            if (parity % 2 == 0)
            {
                PrintQ();
            }
            else
            {
                PrintAQ();
            }
        }
        else if (input == "chooseMultiCoreCPU")
        {
            cout << "Warning: the queue will be cleaned after that command!" << endl;
            cout << "Please, confirm your action (write: confirm)" << endl;

            string c;
            cin >> c;

            if (c == "confirm")
            {
                PrintMultiCoreCPU();
            }
        }
    }
}

void AddCPU()
{
    CPU newCPU;

    cout << "Name:" << endl;
    cin >> newCPU.name;
    cout << "Frequency:" << endl;
    cin >> newCPU.freq;
    cout << "Cores:" << endl;
    cin >> newCPU.cores;
    cout << endl << "/////////////////////////////////" << endl;

    q.push(newCPU);
}

void PrintQ()
{
    while (!q.empty())
    {
        CPU currentCPU = q.front();

        cout << "Name: " << currentCPU.name << endl;
        cout << "Frequency: " << currentCPU.freq << endl;
        cout << "Cores: " << currentCPU.cores << endl;
        cout << endl << endl;

        aq.push(currentCPU);
        q.pop();
    }
    parity += 1;
    cout << endl << "/////////////////////////////////" << endl;
}

void PrintAQ()
{
    while (!aq.empty())
    {
        CPU currentCPU = aq.front();

        cout << "Name: " << currentCPU.name << endl;
        cout << "Frequency: " << currentCPU.freq << endl;
        cout << "Cores: " << currentCPU.cores << endl;
        cout << endl << endl;

        q.push(currentCPU);
        aq.pop();
    }
    parity += 1;
    cout << endl << "/////////////////////////////////" << endl;
}

void PrintMultiCoreCPU()
{
    if (!q.empty())
    {
        while (!q.empty())
        {
            CPU currentCPU = q.front();
            if (currentCPU.cores > 1)
            {
                cout << "Name: " << currentCPU.name << endl;
                cout << "Frequency: " << currentCPU.freq << endl;
                cout << "Cores: " << currentCPU.cores << endl;
                cout << endl << endl;
            }

            cout << endl << "/////////////////////////////////" << endl;
            q.pop();
        }
    }
}