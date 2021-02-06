#ifndef HAS_DMA_H_
#define HAS_DMA_H_
#include <iostream>
#include "dma.h"

class hasDMA : public baseDMA {
    private:
        char *style;
    public:
        hasDMA(const char *s = "none", const char *l = "null", int r = 0);
        hasDMA(const char *s, const baseDMA & rs);
        hasDMA(const hasDMA & rs);
        ~hasDMA();
        hasDMA & operator=(const hasDMA & rs);
        friend std::ostream & operator<<(std::ostream &os, const hasDMA &rs);
};

#endif