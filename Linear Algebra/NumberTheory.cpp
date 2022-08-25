#include "NumberTheory.h"
#include <string>
#include <vector>

int findGCD(int a, int b) {
	if (a == b) return a;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		int r = a % b;
		std::cout << "a = " << a << ", b = " << b << ", r = " << r << std::endl;
		a = b;
		b = r;
	}
	return a;
}


