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


// Задание 1.1
void push(int* px);
void num();
void data(int* px);

deque <int> q;
deque <int> tq;

string y;
int x;

int main()
{
    cin >> x;
    int* px = &x;
    while (cin >> y) {
        if (y == "exit") {
            cout << "\nbye\n";
            return 0;
        }
        if (y == "push")
        {
            push(px);
        }
        if (y == "num") {
            num();
        }
        if (y == "data") {
            data(px);
        }
    }
}

void push(int* px)
{
    for (int i = 0; i < x; i++)
    {
        int t;
        cin >> t;
        if (t < 10)
        {
            q.push_back(t);
            tq.push_back(t);
        }
        else {
            q.push_back(t);
        }
    }
    cout << "Has been filled sucssesfully!\n";
}

void num()
{
    cout << tq.size() << endl;
}

void data(int* px)
{
    for (int i = 1; i < (x + 1); i++)
    {
        cout << q[q.size() - i] << " ";
    }
    cout << endl;
}