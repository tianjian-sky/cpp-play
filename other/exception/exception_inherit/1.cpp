#include "iostream"

class EA {};
class EB : public EA {};
class EC : public EB {};

using namespace std;

void func () {
    throw EC();
}

void testFunc1() {
    try {
        func();
    } catch (EA &) { // 基类异常先捕获
        cout << "ea handle" << endl;
    } catch (EB &) {
        cout << "eb handle" << endl;
    } catch (EC &) {
        cout << "ec handle" << endl;
    }
}

void testFunc2() {
    try {
        func();
    } catch (EA &) {
        cout << "ea handle" << endl;
    } catch (EB &) {
        cout << "eb handle" << endl;
    } catch (EC &) {
        cout << "ec handle" << endl;
    }
}

int main () {
    testFunc1();
}