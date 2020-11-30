#include <iostream>
#include <cmath>

struct polar{
    double distance;
    double angle;
};

struct rect{
    double x;
    double y;
};

polar rect_to_polar(rect xypos); // 1.结构体按值传递，会创建一个结构体的副本
void show_polar(polar dapos);

polar rect_to_polar2(const rect * pxy, polar * pda); // 2.结构体按地址传递，传结构体地址
void show_polar2(const polar * pda);

int main () {
    using namespace std;

    rect rplace;
    polar pplace;

    cout << "Enter the x and y:";
    while (cin >> rplace.x >> rplace.y) { //3. cin >> xxx; 也是返回一个istream对象，所以 cin >> aaa >> bbb; 等同于 cin >>aaa; cin >> bbb;
        
        // pplace = rect_to_polar(rplace);
        // show_polar(pplace);

        rect_to_polar2(&rplace, &pplace);
        show_polar2(&pplace);

        cout << "Next two numbers (q to quit)";
    }

    cout << "Done.\n";
    return 0;
}

polar rect_to_polar(rect xypos) {
    using namespace std;
    polar answer;

    answer.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}

void show_polar(polar dapos) {
    using namespace std;
    const double Rad_to_deg = 57.19577951;

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle*Rad_to_deg;
    cout << " Degrees\n";
}

void show_polar2(const polar * pda) {
    using namespace std;
    const double Rad_to_deg = 57.19577951;

    //4. struct.member 和 struct -> member 两种访问方式
    // struct.member 成员运算符
    // struct->member 间接成员运算符 。 此处接收的主体是结构体的指针，因此不能用.访问成员了
    // cout << "distance = " << pda.distance; // error: request for member 'distance' in 'pda', which is of pointer type 'const polar*' (maybe you meant to use '->' ?)
    
    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angle*Rad_to_deg;
    cout << " Degrees\n";

}


polar rect_to_polar2(const rect * pxy, polar * pda) {
    using namespace std;
    pda->distance = sqrt(pxy->x*pxy->x + pxy->y*pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}