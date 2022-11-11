#include "Queue.h"

using namespace std;

void Queue::enqueue(string name, int numPeople) {
    Node *node = new Node(name, numPeople);
    if (front == NULL && back == NULL) {
        front = node;
        back = node;
    } else {
        back->next = node;
        back = node;
    }
    size++;
}

Node *Queue::dequeue() {
    if (front != NULL) {
        Node *frontNode = front;
        front = front->next;
        size--;
        return frontNode;
    }
    return NULL;
}

bool Queue::isEmpty() {
    return size == 0;
}
