#include <stdio.h>
#include <lib.h>
#include <b.h>
#include <bbb.h>
#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost;

int main() {
	printf("%d\n", add(1, 2));
    printf("%d\n", multiply(3, 5));
    printf("%d\n", myMinus(100, 1));

    string s = R"(Search Engines: http://baidu.com https://google.com
        About Me: https://xuhongxu.com/about/
        )";

    regex e(R"(([a-zA-Z]*)://[a-zA-Z0-9./]+)");
    for (sregex_iterator m(s.begin(), s.end(), e), end; m != end; ++m) {
        cout << "URL:" << (*m)[0].str() << endl;
        cout << "Scheme:" << (*m)[1].str() << endl;
        cout << endl;
    }

	return 0;
}