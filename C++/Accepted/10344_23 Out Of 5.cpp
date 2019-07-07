#include <iostream>
#include <stdio.h>

#define ADD 0
#define SUB 1
#define MUL 2

int val[5];
int used[5];
int arr[5];
int allOpr[4];
int possible;

void print();

void calculate() {
	int f = arr[0];
	int s;
	int sum;
	for(int i = 0; i < 4; i++) {
		s = arr[i+1];
		switch(allOpr[i]) {
		case 0: sum = f + s;
			f = sum;
			break;
		case 1:
			sum = f - s;
			f = sum;
			break;
		case 2:
			sum = f * s;
			f = sum;
			break;
		}
	}

	//printf("sum = %d\n", sum);
	if(sum == 23) possible = 1;
}

void solve(int i) {
	if(possible) return;

	if(i == 5) {
		calculate();
		return;
	}

	for(int j = 0; j < 5; j++) if(!used[j]) {
		used[j] = 1;
		arr[i] = val[j];
		solve(i+1);
		used[j] = 0;
	}
}

void solveCase(int n) {

	if(possible) return;

	if(n == 4) {
		solve(0);
		return;
	}

	for(int i = 0; i < 3; i++) {
		allOpr[n] = i;
		solveCase(n+1);
	}
}

void print() {
	for(int i = 0; i < 4; i++) {
		if(allOpr[i] == ADD) printf("+");
		else if (allOpr[i] == SUB) printf("-");
		else if (allOpr[i] == MUL) printf("*");
	}
	
	printf("\n");
}


void printCase() {
	if(possible) printf("Possible\n");
	else printf("Impossible\n");
}

void clearAll() {
	for(int i = 0; i < 5; i++) used[i] = 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sum;
	while(std::cin >> val[0]) {
		for(int i = 1; i < 5; i++) std::cin >> val[i];
		sum = 0;
		for(int i = 0; i < 5; i++) sum += val[i];
		if(!sum) break;

		clearAll();
		possible = 0;
		solveCase(0);
		printCase();
	}

	return 0;
}
