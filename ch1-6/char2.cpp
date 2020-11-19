#include <iostream>
#include <climits>

int main() {
    using namespace std;
    char ch = 'M'; // 字符使用单引号，字符串用双引号
    int i = ch;

    cout << "Sizeof char" << sizeof ch <<endl;
    cout << "The ascii code for " << ch << " is " << i << endl;
    
    ch += 1;
    i = ch;
    cout << "The ascii code for " << ch << " is " << i << endl;

    cout << "Displaying char using cout.put():";
    cout.put(ch);
    cout.put('!');
    cout << endl << "Done" << endl;

    return 0;
}