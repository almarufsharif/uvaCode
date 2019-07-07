#include <iostream>

int main()
{
	long long a, b, c, d, L;
	int count;

	while (std::cin >> a >> b >> c >> d >> L) {
		if (a + b + c + d + L == 0) break;
		count = 0;
		for (int i = 0; i <= L; i++)
			if (((a * i * i) + (b * i) + c) % d == 0)
				count++;
		std::cout << count << std::endl;
	}
	return 0;

}