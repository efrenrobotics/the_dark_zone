#include <vector>
#include <string>

using namespace std;

static int capacity;

class Queue {
    private:
        int size;
        Node *front, *back;
    public:
        Queue() {
            front = back = NULL;
        }
        void enqueue();
        void dequeue();
};

struct Node {
    int size;
    string name;
    Node *next;

    Node(int s, string n){
        size = s;
        name = n;
    }
};