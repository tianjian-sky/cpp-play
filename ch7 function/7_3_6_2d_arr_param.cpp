#include <iostream>
const int ARR_SIZE = 8;
using namespace std;


/**
* 指针数组与数组指针
* A) int *p1[10];
* B) int (*p2)[10];
*A: “[]”的优先级比“*”要高。p1 先与“[]”结合，构成一个数组的定义，数组名为p1，int *修饰的是数组的内容，即数组的每个元素。那现在我们清楚，这是一个数组，其包含10 个指向int 类型数据的指针，即指针数组。
*B:  至于p2 就更好理解了，在这里“（）”的优先级比“[]”高，“*”号和p2 构成一个指针的定义，指针变量名为p2，int 修饰的是数组的内容，即数组的每个元素。数组在这里并没有名字，是个匿名数组。
*/

/**
* 匿名数组
* 常规的整型数组：
* int array[] = {1, 2, 3};
* 它等价于以下的匿名数组：
* (int[]){1, 2, 3}

* 匿名数组可以直接当作参数传递，可以不使用临时变量存储。
* C99语法支持匿名数组。
* int result = sum((int[]){1, 2, 3});
* 取匿名数组的下标：
* (int []){1, 2, 3}[0] == 1
*/

int sum (int (*ar2)[4], int size); // 正确 
// int sum(int ar2[][4], int size); // 正确
// int sum (int *ar2[4], int size); // 错误 这样表示一个数组的指针，这个数组每一项是一个int 指针 int *(ar2[4])
/**
[] L-R 2
*  R-L 3
**/

int main () {

    int arr[][4]  = {{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    cout << "Sum is :" << sum(arr, 3);
}

int sum (int ar2[][4], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            total += ar2[i][j];
        }
    }

    cout << "2-2:" << *(*(ar2 +1) + 1) << endl;
    return total;   
}
