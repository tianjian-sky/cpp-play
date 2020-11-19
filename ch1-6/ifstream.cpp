#include <iostream>
#include <fstream>
#include <cstdlib>


int main() {
    using namespace std;

    const int SIZE = 60;
    char filename[SIZE];

    ifstream inFile;
    cout << "ENTER FILENAME:";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "FILE OT FOUNT"<<endl;
        cout << "END" <<endl;
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;
    inFile >> value;

    while(inFile.good()) {
        ++count;
        sum+=value;
        inFile>>value;
    }

    if (inFile.eof()) {
        cout << "End of file" << endl;
    } else if (inFile.fail()) {
        cout << "Terminate data mismatch" << endl;
    } else {
        cout << "Terminate unknown reason" << endl;
    }

    if (count == 0) {
        cout << "no data processed" << endl;
    } else {
        cout << "Times read" << count << endl;
        cout << "Sum" << sum << endl;
    }
    inFile.close();
    return 0;
}