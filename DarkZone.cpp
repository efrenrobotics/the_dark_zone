#include <fstream>
#include <iostream>
#include <iomanip>

#include "Stack.h"
#include "Queue.h"

using namespace std;

Queue *readInput(ifstream &capsuleInfo) {
    string input;
    Queue *queue = new Queue();
    while (getline(capsuleInfo, input)) {
        int spaceIndex = input.find(" ");
        string name = input.substr(0, spaceIndex);
        string numPeople = input.substr(spaceIndex + 1);
        queue->enqueue(name, stoi(numPeople));
    }
    capsuleInfo.close();
    return queue;
}

void printCapsule(Stack *stack, int remainingSpace, int currentSize,
    int capsuleNum) {
    cout << "Capsule #" << capsuleNum << endl;
    while (!stack->isEmpty()) {
        Node *node = stack->pop();
        cout << node->name << " " << node->size << endl;
        delete node;
    }
    cout << "Total guests: " << currentSize << endl;
    cout << "Remaining capacity: " << remainingSpace << endl << endl;
}

void printStatistics(int totalGuests, int capsuleNum, int capacity) {
    cout << "Overall number of guests: " << totalGuests << endl;
    cout << "Overall number of capsules: " << capsuleNum << endl;
    cout << "Capsule capacity: " << capacity << endl;
    double utilization = ((double) totalGuests / (capsuleNum * capacity))
                            * 100;
    cout << fixed << setprecision(1);
    cout << "Percentage Utilization: " << totalGuests << " / (" << capsuleNum;
    cout <<  " * " << capacity << ") = " << utilization << "%" << endl;
}

void fillCapsules(int capacity, Queue *queue) {
    int currentSize = 0;
    Stack *stack = new Stack();
    int capsuleNum = 1;
    int totalGuests = 0;
    while (!queue->isEmpty()) {
        Node *node = queue->dequeue();
        totalGuests += node->size;
        if (currentSize + node->size <= capacity) {
            currentSize += node->size;
            stack->push(node->name, node->size);
        } else {
            int remainingSpace = capacity - currentSize;
            printCapsule(stack, remainingSpace, currentSize, capsuleNum);
            currentSize = node->size;
            stack->push(node->name, node->size);
            capsuleNum++;
        }
        delete node;
    }
    int remainingSpace = capacity - currentSize;
    printCapsule(stack, remainingSpace, currentSize, capsuleNum);
    printStatistics(totalGuests, capsuleNum, capacity);
    delete stack;
}

int main() {
    ifstream capsuleInfo;
    capsuleInfo.open("darkZone.txt");
    string input;
    getline(capsuleInfo, input);
    int capacity = stoi(input);
    Queue *queue = readInput(capsuleInfo);
    fillCapsules(capacity, queue);
    delete queue;
    return 0;
}
