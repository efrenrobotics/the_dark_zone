#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    int size;
    std::string name;
    Node *next;

    Node(std::string n, int s) {
        size = s;
        name = n;
        next = NULL;
    }
};

#endif