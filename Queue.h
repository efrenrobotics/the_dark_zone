#include "Node.h"

class Queue {
    private:
        int size;
        Node *front, *back;
    public:
        Queue() {
            front = NULL;
            back = NULL;
            size = 0;
        }

        void enqueue(std::string name, int numPeople);
        Node *dequeue();
        bool isEmpty();
};
