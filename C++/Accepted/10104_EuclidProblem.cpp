#include <iostream>

long long extendedGCD(long long a, long long b, long long &x, long long &y ) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	long long x1, y1, g = extendedGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

void swap(long long &x, long long &y) {
	long long temp = x;
	x = y;
	y = temp;
}

int main()
{
	long long x, y, gcd;
	long long a, b;
	while (std::cin >> a >> b) {
		gcd = extendedGCD(a, b, x, y);
		if (a < b) swap(a, b);
		std::cout << x << " " << y << " " << gcd << std::endl;
	}

	return 0;
}