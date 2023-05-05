/*
    ios              ->      streambuf
    一般流属性                 缓冲区管理
    一个streambuf指针         

    ostream         istream
    输出方法            输入方法
    ｜              /
    ｜          /
    iostream
    多继承 osrream，isream
*/


/*
char 1B
w_char_t 般为16位或32位，但不同的C或C++库有不同的规定，如GNU Libc规定wchar_t为32位，总之，wchar_t所能表示的字符数远超char型。
char16_t
char32_t
*/

/*
I/O类模版
basic_istream<charT, traits<charT>>
basic_ostream<charT, traits<charT>>
    traits<charT>: 
        为字符类定义具体特性：字符相等判断，字符EOF值...
*/
/*
istream, ostream
char具体化的basic_istream的typedef
*/

/*
字符字面量都是char，因此定义中文字符时，需要前面加前缀
https://stackoverflow.com/questions/61690230/chinese-character-too-large-for-enclosing-character-literal-type
*/

#include <iostream>
#include <string>

using namespace std;

int main () {
    // char ch = '愛'; // character too large for enclosing character literal type
    // wchar_t ch = '愛'; // character too large for enclosing character literal type
    wchar_t ch = u'愛';
    cout << ch << endl;
    cout << '中' << endl; // error: character too large for enclosing character literal type
}