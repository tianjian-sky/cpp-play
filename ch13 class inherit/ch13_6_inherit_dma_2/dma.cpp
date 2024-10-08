#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char *l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}
baseDMA::baseDMA(const baseDMA & rs) {
    std::cout << "1.copy constructor called..." << std::endl;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}
baseDMA::~baseDMA() {
    delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & rs) {
    if (this == &rs) {
        return *this;
    }
    delete [] label;
    label = new char [std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
std::ostream & operator<<(std::ostream &os, const baseDMA &rs) {
    std::cout << "1::operator<< called:" << std::endl;
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}