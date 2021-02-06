#include <iostream>
#include "studentc.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student &sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main () {
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };
    int i;
    for (int i = 0; i < pupils; i++) {
        set(ada[i], quizzes);
    }
    cout << "\n student List:\n";
    for (int i = 0; i < pupils; i++) {
        cout << ada[i].Name() << endl;
    }
    cout << "\nResults:\n";
    for (i = 0; i < pupils; i++) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    return 0;
}