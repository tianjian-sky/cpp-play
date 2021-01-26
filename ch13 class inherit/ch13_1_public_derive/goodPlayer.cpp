#include "./goodPlayer.h"
#include <iostream>

GoodPlayer::GoodPlayer (unsigned int r, const string & fn, const string & ln, bool ht)
:TableTennisPlayer(fn, ln, ht){
    rating = r;
}
void GoodPlayer::Name() const {
    // std::cout << "Sub class Name().." << lastname << std::endl;
     std::cout << "Sub class Name().." << std::endl;
}
GoodPlayer::GoodPlayer(unsigned int r, const TableTennisPlayer & tp)
: TableTennisPlayer(tp), rating(r){

}
