#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class baseDMA {
    private:
        char * label;
        int rating;
    public:
        baseDMA(const char *l = "null", int r = 0);
        baseDMA(const baseDMA & rs);
        virtual ~baseDMA();
        baseDMA & operator=(const baseDMA & rs);
        friend std::ostream & operator<<(std::ostream &os, const baseDMA &rs);
};
#endif

