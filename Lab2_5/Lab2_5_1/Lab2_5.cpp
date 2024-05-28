#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::vector<T> elements;

public:
    Queue() = default;

    void enqueue(const T& item) {
        elements.push_back(item);
    }

    void dequeue() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        elements.erase(elements.begin());
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return elements.front();
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Deque size: " << myQueue.size() << std::endl;

    myQueue.dequeue();

    std::cout << "Front element: " << myQueue.front() << std::endl;

    return 0;
}

