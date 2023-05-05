/*
    二进制模式：
    文件写时，不会做任何的转换。

    文本模式：
    c++ 换行：linefeed
    macintosh换行：cr
    unix,linux换行：linefeed
    windows换行：cr+lf

    window保存文本模式；
    lf -> cr+lf 
    macintosh：
    lf -> cr
    -----
    window读取文本模式；
    cr+lf --> lf 
    macintosh：
    cr --> lf
    
*/

/*
seekg(n)  快速定位到n个字节的位置
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Planet {
    char name[20];
    double population;
    double g;
};
int main () {
    fstream fs;
    const double num = 0.375;
    const string dataFile = "data.dat";
    Planet earth {"Earch", 100000, 9.8};
    fs.open(dataFile, ios_base::out|ios_base::in);
    cout << "sizeof Planet:" << sizeof (earth) << endl; // 40
    fs.write((char *) &earth, sizeof earth);
    cout << "Finished" << endl;
    fs.seekg(0);
    Planet * pl;
    fs.read((char * )pl, sizeof *pl);
    cout << "----read file----" << endl;
    cout << "name: " << pl->name << endl;
    cout << "population: " << pl->population << endl;
    cout << "g: " << pl->g << endl;
}