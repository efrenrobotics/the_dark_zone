#include "Node.h"

class Stack {
    private:
        int size;
        Node *front;
    public:
        Stack() {
            front = NULL;
            size = 0;
        }

        void push(std::string name, int numPeople);
        Node *pop();
        bool isEmpty();
};
