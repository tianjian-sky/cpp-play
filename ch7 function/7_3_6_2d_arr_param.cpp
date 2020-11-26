#include <iostream>
const int ARR_SIZE = 8;
using namespace std;


/**
* 二维数组作为参数，需要接收的是一个数组的指针，这个数组每一项都是一个4个int的数
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
