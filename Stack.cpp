#include "Stack.h"

using namespace std;

void Stack::push(string name, int numPeople) {
    Node *node = new Node(name, numPeople);
    if (front == NULL) {
        front = node;
    } else {
        node->next = front;
        front = node;
    }
    size++;
}

Node *Stack::pop() {
    if (front != NULL) {
        Node *frontNode = front;
        front = front->next;
        size--;
        return frontNode;
    }
    return NULL;
}

bool Stack::isEmpty() {
    return size == 0;
}