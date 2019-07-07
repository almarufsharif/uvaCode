#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
int count = 0;
int arr[8][8];
int max;
void solve(int n, int col, int *hist)
{
	if (col == n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if(j == hist[i]) sum += arr[i][j];
				//putchar(j == hist[i] ? 'Q' : ((i + j) & 1) ? ' ' : '.');
 
		if(sum > max) max = sum;
	}
 
#	define attack(i, j) (hist[j] == i || abs(hist[j] - i) == col - j)
	for (int i = 0, j = 0; i < n; i++) {
		for (j = 0; j < col && !attack(i, j); j++);
		if (j < col) continue;
 
		hist[col] = i;
		solve(n, col + 1, hist);
	}
}
 
int main()
{

	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				std::cin >> arr[i][j];

		int hist[8];
		max = 0;
		solve(8, 0, hist);
		printf("%5d\n", max);
	}

	return 0;
}