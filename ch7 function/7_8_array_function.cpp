#include <iostream>
#include <array> //1. 模板类array ，c++11   g++ filename -std=c++11
#include <string>
const int Seasons = 4;

const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"}; //2.名称array位于std空间中

void fill(std::array<double, Seasons> * pa);
void show(std::array<double, Seasons> da);

int main () {
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::array<double, Seasons> * pa){
    using namespace std;
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses:";
        cin >> (*pa)[i]; // 3.
    }
}

void show(std::array<double, Seasons> da) {
    using namespace std;
    double total = 0.0;
    cout << "\nExpenses\n";
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}




