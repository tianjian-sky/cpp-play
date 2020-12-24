#include <iostream>
/**
 * 类作用域
 * 
*/

class Ik {
    private:
        int fuss;
    public:
        Ik(int f = 9) {fuss = f;}
        void ViewIk() const ;
};

void Ik::ViewIk() const {
    std::cout << fuss << std::endl;
}

int main () {
    const Ik * pik = new Ik;
    const Ik ee = Ik(8);
    ee.ViewIk();
    pik->ViewIk();
    return 0;
}