#ifndef LACK_DMA_H_
#define LACK_DMA_H_
#include <iostream>
#include "dma.h"

class lackDMA : public baseDMA {
    private:
        enum {COL_LEN = 40};
        char color [COL_LEN];
    public:
        lackDMA(const char *c = "blank", const char *l = "null", int r = 0);
        lackDMA(const char *c, const baseDMA & rs);
        lackDMA(const lackDMA & rs);
        friend std::ostream & operator<<(std::ostream &os, const lackDMA &rs);
};

#endif