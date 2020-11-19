#include <iostream>
using namespace std;
struct dummy1 {
    std::string name;
    float age;
} myDum, myDum2;

struct com_reg {
    unsigned int SN: 4;
    unsigned int : 4;
    bool goodIn : 1;
    bool goodTorgle : 1;
};
int main() {
    
    
    myDum = {};
    myDum2 = {"hello", 13};

    com_reg reg1 = {3, true, false}; // 如果有字段没名称，则不用初始化

    cout << myDum.name << endl;
    cout << myDum2.name << endl;
    cout << reg1.SN << reg1.goodIn;
    return 0;
}