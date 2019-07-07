#include <iostream>
#include <algorithm>
#include <string>

int arr[50];

int myabs(int x) {
	if (x < 0)
		return -x;
	return x;
}
int main()
{
	int N, min, count;
	std::string line, buf;
	while (std::cin >> N) {
		if (N == 0)
			break;
		std::getline(std::cin, buf);
		min = 1234567890;
		
		for (int i = 0; i < N; i++) {
			std::getline(std::cin, line);

			for (int j = 0; j < 25; j++) {
				if (line[j] == ' ')
					arr[i]++;
			}

			min = std::min(min, arr[i]);
		}

		count = 0;
		for (int i = 0; i < N; i++)
			count += myabs(min - arr[i]);
		
		std::cout << count << std::endl;

		for (int i = 0; i < N; i++)
			arr[i] = 0;
	}

	return 0;
}