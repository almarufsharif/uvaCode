#include <iostream>
#include <string>

char arr[50][100];
int lineCount, colCount;

void floodFill(int i, int j) {
	if (i < 0 || j < 0 || i >= lineCount || arr[i][j] == '\0') return;
	if (arr[i][j] != ' ') return;
	arr[i][j] = '#';
	floodFill(i - 1, j);
	floodFill(i, j + 1);
	floodFill(i + 1, j);
	floodFill(i, j - 1);
}

void printGraph() {
	for (int i = 0; i < lineCount; i++) {
		for (int j = 0; arr[i][j] != '\0'; j++)
			std::cout << arr[i][j];
		std::cout << std::endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tCase, i;
	std::string str;
	std::cin >> tCase;
	std::getline(std::cin, str);
	while (tCase--) {
		lineCount = 0;
		colCount = -1;
		while (std::getline(std::cin, str)) {
			for (i = 0; i < str.size(); i++)
				arr[lineCount][i] = str[i];
			colCount = colCount > i ? colCount : i;
			arr[lineCount][i] = '\0';
			lineCount++;
			if (str[0] == '_')
				break;
		}

		int f = 0;
		int x, y;

		for (int i = 0; i < lineCount; i++) {
			for (int j = 0; j < colCount; j++)
				if (arr[i][j] == '*') {
					x = i;
					y = j;
					f = 1;
					break;
				}
			if (f)
				break;
		}

		arr[x][y] = ' ';
		floodFill(x, y);
		printGraph();
	}

	return 0;
}
