#ifndef COORDIN_H_ //若所指定的标识符A已经被#define命令定义过则编译程序段1，否则编译程序段2
#define COORDIN_H_ // 防止同一个文件多次引入相同的头文件，造成redefine error
#include <cmath>
/** 
 * 头文件中常包含：
 *  函数原型
 *  模板声明
 *  符号常量
 *  结构声明
 *  类声明
 *  内联函数
**/

// 函数定义不要放在头文件里，会造成函数重复定义


struct polar {
    double distance;
    double angle;  
};

struct rect {
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);


polar rect_to_polar(rect xypos) {
    using namespace std;
    polar answer;

    answer.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}


#endif