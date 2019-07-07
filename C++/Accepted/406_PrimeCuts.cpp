#include <iostream>
#include <stdio.h>

#define SIZE 1000

int prime[300];
int nPrime, N, C;

void generateAllPrime() {
	int arr[SIZE];
	arr[1] = 1;
	for(int i = 2; i < SIZE; i++)
		arr[i] = 1;

	for(int i = 2; i < SIZE; i++) if (arr[i]) {
		for(int j = i * 2; j < SIZE; j += i)
			arr[j] = 0;
	}

	nPrime = 0;
	for(int i = 1; i < SIZE; i++) if (arr[i])
		prime[nPrime++] = i;
}

void printAllPrime() {
	for(int i = 0; i < nPrime; i++) printf("%d. %d\n", i, prime[i]);
}

int searchNum(int b, int e, int key) {
	int mid;
	while ( b <= e) {
		mid = (b + e)/2;
		if(key == prime[mid]) return mid;
		else if (key < prime[mid]) e = mid - 1;
		else if (key > prime[mid]) b = mid + 1;
	}

	return mid;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int index, nPrint;
	generateAllPrime();
	//printAllPrime();

	while(std::cin >> N >> C) {
		printf("%d %d:", N, C);
		index = searchNum(0, 168, N);
		if(prime[index] > N) index--;

		if((index + 1) % 2 == 0) nPrint = 2*C;
		else nPrint = 2*C - 1;

		if(nPrint > index + 1) for(int i = 0; i <= index; i++) printf(" %d", prime[i]);
		else {
			int p = index / 2;
			if(nPrint % 2 == 0)	for (int i = p + 1 - C; i <= p + C; i++) printf(" %d", prime[i]);
			else for(int i = p - C+1; i <= p + C - 1; i++) printf(" %d", prime[i]);
		}
		printf("\n\n");
	}

	return 0;
}
