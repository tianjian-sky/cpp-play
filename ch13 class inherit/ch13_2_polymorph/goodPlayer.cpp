#include "./goodPlayer.h"
#include <iostream>

GoodPlayer::GoodPlayer (unsigned int r, const string & fn, const string & ln, bool ht)
:TableTennisPlayer(fn, ln, ht){
    std::cout << "sub constructor called:GoodPlayer (unsigned int r, const string & fn, const string & ln, bool ht) " << std::endl;
    rating = r;
    // TableTennisPlayer(fn, ln, ht); 写这里也行
}

GoodPlayer::GoodPlayer ()
{
    std::cout << "sub constructor called:GoodPlayer ()" << std::endl;
    // 如果省略:TableTennisPlayer(fn, ln, ht)，则调用基类的默认构造函数
    rating = 1;
}

void GoodPlayer::Name() const {
    // std::cout << "Sub class Name().." << lastname << std::endl;
     std::cout << "Sub class Name()..";;
     TableTennisPlayer::Name();
     std::cout << std:: endl;
}
GoodPlayer::GoodPlayer(unsigned int r, const TableTennisPlayer & tp)
: TableTennisPlayer(tp), rating(r){
    std::cout << "sub constructor called:GoodPlayer(unsigned int r, const TableTennisPlayer & tp)" << std::endl;
}

GoodPlayer::~GoodPlayer () {
    std::cout << "sub class descrtuctor called " << std::endl;
}
