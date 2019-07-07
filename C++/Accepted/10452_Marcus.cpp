#include <iostream>
#include <stdio.h>
int M, N;

char arr[10][10];
int path[10];
char val[] = "IEHOVA#";

void readCase()
{
	scanf("%d %d", &M, &N);
	for(int i= 0; i< M; i++)
		std::cin >>arr[i];
}

void solve(int n, int i, int j ) {
	if(n == 8) return;

	if(j - 1 >= 0 && arr[i][j-1] == val[n]) {
		path[n] = 2;
		solve(n + 1, i, j - 1);
	}

	if(j + 1 < N && arr[i][j+1] == val[n]) {
		path[n] = 3;
		solve(n + 1, i, j + 1);
	}

	if( i - 1 >= 0 && arr[i-1][j] == val[n]) {
		path[n] = 1;
		solve(n + 1, i - 1, j);
	}
}

void solveCase() {
	int a;
	for(int j = 0; j < N; j++)
		if(arr[M-1][j] == '@') a = j;
	
	solve(0, M - 1, a);
}

void printCase() {
	for(int i= 0; i < 7; i++) {
		if(path[i] == 1) printf("forth");
		else if(path[i] == 2) printf("left");
		else if(path[i] == 3) printf("right");
		
		if(i < 7 - 1) printf(" ");
	}

	printf("\n");
}

int main()
{
	freopen("output.txt", "w", stdout);
	freopen("Input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		readCase();
		solveCase();
		printCase();
	}

	return 0;
}
