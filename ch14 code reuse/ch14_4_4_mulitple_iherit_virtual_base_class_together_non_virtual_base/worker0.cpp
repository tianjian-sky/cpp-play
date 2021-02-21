#include "worker0.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {

}
void Worker::Show() const {
    cout << "Worker Show() called:" << endl;
}
void Waiter::Show() const {
    cout << "Waiter Show() called:" << endl;
}
void Singer::Show() const {
    cout << "Singer Show() called:" << endl;
}
void Waiter2::Show() const {
    cout << "Waiter2 Show() called:" << endl;
}
void Singer2::Show() const {
    cout << "Singer2 Show() called:" << endl;
}

void Singer_Waiter_Mix::Show() const {
    cout << "Singer_Waiter_Mix Show() called:" << endl;
    Waiter::Show();
    Singer::Show();
    Waiter2::Show();
    Singer2::Show();
}

