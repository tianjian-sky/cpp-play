#ifndef GOOD_H_
#define GOOD_H_
#include "./tbPlayer.h"
#include <string>


using std::string;

class GoodPlayer : public TableTennisPlayer {
    private:
        unsigned int rating;
    public:
        GoodPlayer ();
        GoodPlayer (unsigned int r, const string & fn = "none", const string & ln = "none", bool ht = false);
        void Name() const;
        GoodPlayer(unsigned int r, const TableTennisPlayer & tp);
        ~GoodPlayer ();
        unsigned int Rating() const {return rating;};
        void ResetRating (unsigned int r) {rating = r;}
};

# endif
