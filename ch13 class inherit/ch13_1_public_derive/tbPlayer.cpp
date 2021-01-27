#include "./tbPlayer.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer (const string & fn, const string & ln, bool ht) 
: firstname(fn), lastname(ln), hasTable(ht)
{}
void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname << std::endl;
}

TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer &tp) {
    std::cout << "super class copy constructor called.." << std::endl;
    firstname = tp.firstname;
    lastname = tp.lastname;
    hasTable = tp.hasTable;
}
TableTennisPlayer::~TableTennisPlayer() {
    std::cout << "super class destructor called.." << std::endl;
};