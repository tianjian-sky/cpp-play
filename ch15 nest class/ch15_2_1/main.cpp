#include <iostream>
#include <string>
#include "q.cpp"

int main () {
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    Queue<string> cs(5);
    string temp;
    while(!cs.isFull()) {
        cout << "Please enter name:" ;
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "Queue full" << endl;
    while (!cs.isEmpty()) {
        cs.dequeue(temp);
        cout << "Now processing "<< temp << "....\n";
    }
    return 0;
}