#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    ~Queue() {
        while (!empty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (empty()) {
            frontNode = newNode;
            rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }

    bool empty() const {
        return frontNode == nullptr;
    }
};

int main() {
    Queue<int> intQueue;
    Queue<double> doubleQueue;
    Queue<std::string> stringQueue;

    int choice;
    do {
        std::cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Is Empty\n5. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            int item;
            std::cout << "Enter integer to enqueue: ";
            std::cin >> item;
            intQueue.enqueue(item);
            break;
        case 2:
            try {
                intQueue.dequeue();
                std::cout << "Dequeued successfully.\n";
            }
            catch (const std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Front element: " << intQueue.front() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 4:
            if (intQueue.empty()) {
                std::cout << "Queue is empty.\n";
            }
            else {
                std::cout << "Queue is not empty.\n";
            }
            break;
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

