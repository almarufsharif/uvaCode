#include <iostream>
#include <stdio.h>

int arr[8][8];
int num[8][8];
int Ans, result;
//int count;

void readCase() {
	Ans = -987654321;
	//count = 0;
	for(int i= 0; i < 8; i++)
		for(int j = 0; j < 8; j++) {
			arr[i][j] = 0;
			scanf("%d", &num[i][j]);
		}
}

int calculateCost() {
	int sum = 0;
	for(int i= 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if(arr[i][j]) sum += num[i][j];
	return sum;
}

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

void solveCase(int i) {
	if(i == 8) {
		//count++;
		result = calculateCost();
		Ans = Ans > result ? Ans : result;
		return;
	}

	for(int j = 0; j < 8; j++)
		if(!arr[i][j] && isValidPosition(i, j)) {
			arr[i][j] = 1;
			solveCase(i+1);
			arr[i][j] = 0;
		}
}

int main()
{
	int k;
	std::cin >> k;

	while(k--) {
		readCase();
		solveCase(0);
		printf("%5d\n", Ans);
		//printf("all possible is: %d\n", count);
	}

	return 0;
}
