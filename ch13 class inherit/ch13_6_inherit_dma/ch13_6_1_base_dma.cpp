#include <iostream>
#include <cstring>
using namespace std;
class baseDMA {
    private:
        char *label;
        int rating;
    public:
        baseDMA(const char *l = "null", int r = 0);
        baseDMA(const baseDMA & rs);
        baseDMA & operator=(const baseDMA &rs);
        virtual ~baseDMA();
};

class lacksDMA:public baseDMA {
    private:
        char color[40];
    public:
        lacksDMA(const char *l, int r, char color[]);
        lacksDMA(const lacksDMA & ld);
        lacksDMA & operator=(const lacksDMA &ld);
        virtual ~lacksDMA();
};
baseDMA::baseDMA(const char *l, int r) {
    cout << "1.1 base constructor called: l:" << l << "r:" << r << endl;
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
baseDMA::baseDMA(const baseDMA & rs) {
    cout << "1.2 base copy constructor called" << endl;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}
baseDMA & baseDMA::operator=(const baseDMA &rs) {
    cout << "1.3 base assignment called" << endl;
    if (this == &rs) {
        return *this; // this是一个指针
    }
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return  *this;
}
baseDMA::~baseDMA() {
    cout << "1.4 base destructor called" << endl;
    delete [] label;
}

lacksDMA::lacksDMA(const char *l, int r, char color[]) :baseDMA(l, r) {
    cout << "2.1 sub constructor called" << endl;
    color = color;
}
lacksDMA::lacksDMA(const lacksDMA & ld) {
    cout << "2.2 sub copy constructor called" << endl;
    const int colorSize = sizeof (ld.color) / sizeof (char);
    for (int i = 0; i < colorSize; i++) {
        color[i] = ld.color[i];
    }
}
lacksDMA & lacksDMA::operator=(const lacksDMA &ld) {
    cout << "2.3 sub assignment called" << endl;
    const int colorSize = sizeof (ld.color) / sizeof (char);
    for (int i = 0; i < colorSize; i++) {
        color[i] = ld.color[i];
    }
    return *this;
}
lacksDMA::~lacksDMA() {
    cout << "2.4 sub descructor called" << endl;
}

int main () {
    cout << "segment 1: " << endl;
    {
        lacksDMA l1("tony", 1, "white");
        lacksDMA l2 = l1; // 先基类默认构造函数，再子类拷贝构造函数
        lacksDMA l3("linda", 3, "yellow");
        l3 = l2;
    }
    cout << "segment 2: " << endl;
    {
        baseDMA bl = lacksDMA("helen", 4, "green"); // 调用的是基类的拷贝构造函数
    }
    return 0;
}