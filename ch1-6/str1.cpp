#include <iostream>
#include <cstring>

int main() {
    using namespace std;
    
    // c风格
    char dog[8] = {'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'};
    char cat[8] = {'f', 'a', 't', 's', 's', 'a', 'e', '\0'};

    // 字符串常量
    char bird[] = "Mr. Cheeps";

    char joint[] = "str1" "str2";

    char testStrLen[] = "Fuck you!";

    char name[39];

    char wife[55];

    cout << "str1:" << dog << endl;
    cout << "str2" << cat << endl;
    cout << "str3" << bird << endl;
    cout << "str joint:" << joint << endl;

    cout << "test Strlen:" << strlen(testStrLen) << endl;

    cout << "Please input your name:" << endl;
    cin.getline(name, 100);
    cout << " Your name: " << name << endl;
    cout << "strlen your name:" << strlen(name) << endl;
    cout << "sizeof your name:" << sizeof(name) << endl; 

    cout << "Please input your wife name:";
    cin.getline(wife, 100);

    cout << "Your wife name: " << wife;

    return 0;
}