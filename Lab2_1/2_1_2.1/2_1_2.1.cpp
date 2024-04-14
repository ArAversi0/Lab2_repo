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

// Задание 2.1

struct Node {

    string str;
    Node* next;

    Node(string _str) : str(_str), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _str) {
        Node* p = new Node(_str);

        if (is_empty()) {
            first = p;
            last = p;
            return;
        }

        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;

        Node* p = first;

        while (p != nullptr) {
            cout << p->str << " ";
            p = p->next;
        }
        cout << endl;
    }

    void pop_back()
    {
        if (is_empty()) return;

        if (first == last) {
            Node* p = first;
            first = p->next;
            delete p;
        }
        else {
            Node* p = first;

            while (p->next != last)
            {
                p = p->next;
            }
            p->next = nullptr;
            delete last;
            last = p;
        }
    }

    void count_oneChar()
    {
        if (is_empty()) return;

        Node* p = first;
        int counter = 0;

        while (p != nullptr)
        {
            if ((p->str).length() == 1)
            {
                counter++;
            }
            p = p->next;
        }
        cout << counter << endl;
    }
};

int main()
{
    list l1;

    l1.push_back("abc");
    l1.push_back("de");
    l1.push_back("f");
    l1.push_back("g");
    l1.push_back("hi");
    l1.push_back("jk");

    l1.print();

    l1.pop_back();

    l1.print();

    l1.count_oneChar();

    return 0;
}
