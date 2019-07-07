#include <iostream>
#include <string>
#include <stack>

int num[26];

int main()
{
	int tCase;
	std::string line;
	std::cin >> tCase;
	std::stack<int> S;
	for (int tc = 1; tc <= tCase; tc++) {
		std::fill(num, num + 26, 0);
		//std::getline(std::cin, line);
		std::cin >> line;
		//num[line[0] - 'A'];
		S.push(line[0]);
		for (int i = 1; i < line.size(); i++) {
			if (S.top() != line[i]) {
				num[S.top() - 'A']++;
				num[line[i] - 'A']++;
				S.push(line[i]);
			}
			else if (S.top() == line[i] && !S.empty())
				S.pop();
		}
		std::cout << "Case " << tc << std::endl;
		for (int i = 0; i < 26; i++)
			if (num[i])
				std::cout << (char)(i + 'A') << " = " << num[i] << std::endl;
	}

	return 0;
}