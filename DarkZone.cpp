#include <fstream>
#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(){
    ifstream capsuleInfo;
    capsuleInfo.open("darKZone.txt");
    string numSeats;
    getline(capsuleInfo, numSeats);
    capacity = stoi(numSeats);


    return 0;
}