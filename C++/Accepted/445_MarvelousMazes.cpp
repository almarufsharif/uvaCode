#include <iostream>
#include <string>

int main()
{
	std::string str;
	int num, f;

	while (std::getline(std::cin, str)) {
		if (str[0] == '\n')
			std::cout << std::endl;
		f = 0;
		num = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				if (f)
					num += str[i] - '0';
				else {
					num = str[i] - '0';
					f = 1;
				}
			}
			else if ((str[i] >= 'A' && str[i] <= 'Z') || str[i] == '*') {
				f = 0;
				for (int j = 0; j < num; j++)
					std::cout << str[i];
				num = 0;
			}

			else if (str[i] == 'b') {
				f = 0;
				for (int j = 0; j < num; j++)
					std::cout << " ";
				num = 0;
			}

			else if (str[i] == '!')
				std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}