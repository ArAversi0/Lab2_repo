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
