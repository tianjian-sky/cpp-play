#include <stdio.h>

extern int add(int, int);
extern int multiply(int, int);

int main() {
	printf("%d\n", add(1, 2));
    printf("%d\n", multiply(3, 5));
	return 0;
}