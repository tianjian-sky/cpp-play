#include <iostream>
#include "tbPlayer.h"
#include "goodPlayer.h"

int main (void) {
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    GoodPlayer gp1(1140, "Mallory", "Duck", true);
    player1.Name();
    gp1.Name();
    return 0;
}