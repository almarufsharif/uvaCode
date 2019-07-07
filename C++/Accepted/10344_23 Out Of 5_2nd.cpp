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

void solve() {

	for(int a = 0; a < 5 && !possible; a++) {
			used[a] = 1;
			for(int b = 0; b < 5 && !possible; b++) {
				if(used[b]) continue;
				used[b] = 1;
				for(int c = 0; c < 5 && !possible; c++) {
					if(used[c]) continue;
					used[c] = 1;
					for(int d = 0; d < 5 && !possible; d++) {
						if(used[d]) continue;
						used[d] = 1;
						for(int e = 0; e < 5 && !possible; e++) {
							if(used[e]) continue;
							used[e] = 1;
							calculate();
							arr[0] = val[a], arr[1] = val[b], arr[2] = val[c], arr[3] = val[d], arr[4] = val[e];
							used[e] = 0;
						}
						used[d] = 0;
					}
					used[c] = 0;
				}
				used[b] = 0;
			}
			used[a] = 0;
		}
}

void solveCase(int n) {

	if(possible) return;

	if(n == 4) {
		solve();
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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
