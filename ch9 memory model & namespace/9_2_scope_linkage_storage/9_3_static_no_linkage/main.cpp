#include <iostream>
const int Ar_size = 10;

void strcount(const char * str);

/**
 * 静态存储持续性，无链接性变量
 * 定义：代码块中 + static
 * 作用场景：
 *      函数多次调用，可用读取到上一次的值
**/



int main () {
    using namespace std;
    
    char input[Ar_size];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, Ar_size); // cin.get（input，limit）：一直读取输入，直到到了行尾或limit-1个字符为止，剩下的字符串任然保留。
    while(cin) {
        cin.get(next); // 读取上次get留下的字符
        cout << "next is:" << next << endl;
        while(next != '\n') {
            cin.get(next);
        }
        strcount(input);
        cout << "Enter next line (empty line to quit):" << endl;
        cin.get(input, Ar_size);
    }
    cout << "Bye" << endl;
    return 0;
}

void strcount(const char * str) {
    using namespace std;
    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    while(*str ++) {
        count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total"<< endl;
}