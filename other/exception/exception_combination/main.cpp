#include "sales.cpp"
#include "iostream"
using namespace std;

int main () {
    double vals1[12] = {
        1220,1100,1122,2212,1232,2334,2884,2393,3302,2922,3002,3544
    };
    double vals2[12] = {
        12,11,22,21,32,34,28,29,33,29,32,35
    };
    Sales sales1(2011, vals1, 12);
    LadySales sales2("BlogStar", 2012, vals2, 12);
    
    cout << "Firt try\n" << endl;
    try {
        int i;
        cout << "YEAR=" << sales1.Year() << endl;
        for (i = 0; i < 12; ++i) {
            cout << sales1[i] << "  ";
            if (i % 6 == 5) {
                cout << endl;
            }
        }
        cout << "YEar = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i) { // 引发异常
            cout << sales2[i] << "  ";
            if (i % 6 == 5) {
                cout << endl;
            }
        }
        cout << "end of block 1." << endl;
    } catch(LadySales::nbad_index & bad) {
        cout << bad.what() << endl;
        cout << bad.label_val() << endl;
        cout << bad.bi_val() << endl;
    } catch(Sales::bad_index & bad) {
        cout << bad.what();
        cout << "bad index:" << bad.bi_val() << endl;
    }
    cout << "Try block 2" << endl;t
    try {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "End of try block 2" << endl;
    } catch(LadySales::nbad_index & bad) {
        cout << bad.what() << endl;
        cout << bad.label_val() << endl;
        cout << bad.bi_val() << endl;
    } catch(Sales::bad_index & bad) {
        cout << bad.what();
        cout << "bad index:" << bad.bi_val() << endl;
    }
    cout << "Done . " << endl;
    return 0;
}