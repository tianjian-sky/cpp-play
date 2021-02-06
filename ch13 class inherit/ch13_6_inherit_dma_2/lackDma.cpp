#include "dma.h"
#include "lackDMA.h"
#include <cstring>

lackDMA::lackDMA(const char *c, const char *l, int r) :baseDMA(l, r) {
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lackDMA::lackDMA(const char *c, const baseDMA & rs) :baseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
lackDMA::lackDMA(const lackDMA & rs) :baseDMA(rs) {
    std::cout << "2.copy constructor called..." << std::endl;
    std::strncpy(color, rs.color, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
std::ostream & operator<<(std::ostream &os, const lackDMA &rs) {
    std::cout << "2::operator<< called:" << std::endl;
    os << (baseDMA) rs; // 一定要强转一下，否则会又匹配到自己
    os << "Color: " << rs.color << std::endl;
    return os;
}
