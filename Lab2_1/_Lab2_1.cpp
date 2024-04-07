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

/*
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
}*/


// Задание 1.2
/*
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
}*/

/*
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
    cout << counter << endl;

    return 0;
}*/
/*
// Задание 2.2

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

    void count_more3Char()
    {
        if (is_empty()) return;

        Node* p = first;
        int counter = 0;

        while (p != nullptr)
        {
            if ((p->str).length() > 2)
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
    list l2;

    l2.push_back("Student");
    l2.push_back("of");
    l2.push_back("the");
    l2.push_back("OSAT");

    l2.print();

    l2.pop_back();

    l2.push_back("ONAT");

    l2.print();

    l2.count_more3Char();

    return 0;
}*/
/*
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
}*/

/*
// Задание 4.1

struct Node {

    float fl;
    Node* next;

    Node(float _fl) : fl(_fl), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void push_back(double value) {
        Node* p = new Node(value);
        if (head == nullptr) {
            head = p;
        }
        else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = p;
        }
    }

    void pop() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        else {
            Node* prev = nullptr;
            Node* current = head;
            while (current != nullptr && current->fl <= 0) {
                prev = current;
                current = current->next;
            }
            if (current != head) {
                prev->next = current;
                delete head;
                head = current;
            }
        }
    }

    void print() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->fl << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    List l3;

    l3.push_back(-3.1);
    l3.push_back(3);
    l3.push_back(5);
    l3.push_back(-3.3);
    l3.push_back(7.2);

    l3.print();

    l3.pop();

    l3.print();
}
*/
