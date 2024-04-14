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

// Задание 3

stack <int> _s1;
stack <int> _s2;

int ind = 1;

void fill_s1()
{
    if (!_s1.empty())
    {
        while (!_s1.empty()) _s1.pop();
    }

    cin >> ind;

    while (ind != 0)
    {
        _s1.push(ind);
        cin >> ind;
    }
    cout << endl;
}

void fill_s2()
{
    while (!_s1.empty())
    {
        _s2.push(_s1.top());
        _s1.pop();
    }
}

void print()
{
    while (!_s2.empty())
    {
        cout << _s2.top() << " ";
        _s1.push(_s2.top());
        _s2.pop();
    }
    cout << endl;
}

int main()
{
    string s;

    while (cin >> s)
    {
        if (s == "exit") return 0;
        else if (s == "fill_queue")
        {
            fill_s1();
            fill_s2();
        }
        else if (s == "print")
        {
            print();
            fill_s2();
        }
    }

    return 0;
}
