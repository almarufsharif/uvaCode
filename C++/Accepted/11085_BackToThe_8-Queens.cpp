#include <stdio.h>
#include <iostream>

int Case = 1;
int Ans, t;
int arr[8][8];
int val[8];

int isValidPosition(int I, int J) {
	int i, j;
	for(int i = 0; i < 8; i++)
		if(i != I && arr[i][J]) return 0;
	
	for(int j = 0; j < 8; j++)
		if(j!=J && arr[I][j]) return 0;

	// upper right diagonal
	i = I, j = J;
	while(i >= 0 && j < 8) {
		if(arr[i][j]) return 0;
		i--; j++;
	}

	// lower right diagonal
	i = I, j = J;
	while(i < 8 && j < 8) {
		if(arr[i][j]) return 0;
		i++; j++;
	}

	// upper left diagonal
	i = I, j=J;
	while(i >= 0 && j >= 0) {
		if(arr[i][j]) return 0;
		i--; j--;
	}

	// lower left diagonal
	i = I, j = J;
	while(i < 8 && j >= 0) {
		if(arr[i][j]) return 0;
		i++; j--;
	}

	return 1;
}

int solve() {
	int count = 0;
	for(int j = 0; j < 8; j++)
		if(!arr[val[j]-1][j]) count++;

	return count;
}

void solveCase(int i) {
	if(i == 8) {
		t = solve();
		Ans = Ans < t ? Ans : t;
		return;
	}

	for(int j = 0; j < 8; j++)
		if(!arr[i][j] && isValidPosition(i, j)) {
			arr[i][j] = 1;
			solveCase(i+1);
			arr[i][j] = 0;
		}
}

void printCase() {
	printf("Case %d: %d\n", Case++, Ans);
}

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while(std::cin >> val[0]) {
		for(int i = 1; i < 8; i++) std::cin >> val[i];
		Ans = 9876543210;
		solveCase(0);
		printCase();
	}

	return 0;
}
