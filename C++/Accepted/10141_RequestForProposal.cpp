#include <iostream>
#include <string>
#include <algorithm>

struct PName {
	int requirement;
	double price;
	std::string name;
};

std::string arr[1010];
PName pArr[1010];

int R, P, best;

bool cmp(const PName &x, PName &y) {
	if (x.requirement == y.requirement)
		return x.price < y.price;
	return x.requirement > y.requirement;
}

int main() {
	int tc = 1, f = 0;
	std::string buffer;
	while (std::cin >> R >> P) {
		if (R == 0 && P == 0)
			break;
		if (f)
			std::cout << std::endl;
		std::getline(std::cin, buffer);
		for (int i = 0; i < R; i++)
			std::getline(std::cin, arr[i]);
		
		for (int pc = 0; pc < P; pc++) {
			std::getline(std::cin, pArr[pc].name);
			std::cin >> pArr[pc].price >> pArr[pc].requirement;

			std::getline(std::cin, buffer);
			for (int j = 0; j < pArr[pc].requirement; j++)
				std::getline(std::cin, buffer);
		}

		std::sort(pArr, pArr + P, cmp);
		std::cout << "RFP #" << tc++ << std::endl;
		std::cout << pArr[0].name << std::endl;
		f = 1;
	}

	return 0;
}