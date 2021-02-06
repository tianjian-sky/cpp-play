#include "dma.h"
#include "hasDMA.h"
#include <cstring>

hasDMA::hasDMA(const char *s, const char *l, int r):baseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const baseDMA & rs) :baseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs) :baseDMA(hs) {
    std::cout << "3.copy constructor called..." << std::endl;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}
hasDMA::~hasDMA() {
    delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & hs) {
    std::cout << "3.operator= called..." << std::endl;
    if (this == &hs) {
        return *this;
    }
    (baseDMA) *this = hs;
    // baseDMA::operator=(hs); // 该语句含义类似于: *this = hs;，但是如果使用这种写法，将重复调用自己
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
std::ostream & operator<<(std::ostream &os, const hasDMA &hs) {
    std::cout << "3::operator<< called:" << std::endl;
    os << (baseDMA) hs;
    os << "Sylte: " << hs.style << std::endl;
    return os;
}