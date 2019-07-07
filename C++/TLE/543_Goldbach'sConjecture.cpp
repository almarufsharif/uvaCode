#include <iostream>
#include <stdio.h>

#define SIZE 1000010

int prime[SIZE];
int p[SIZE];
int N, count;
int a, b;
int f;
int max;

void solveCase(){
	for(int i= 0; p[i] < N; i++)
		for(int j = i + 1; p[j] < N; j++)
			if(p[i] + p[j] == N) {
				f = 1;
				if(p[j] - p[i] > max)
					a = p[i], b = p[j], max = p[j] - p[i];
			}

}

void printCase() {
	if(!f) printf("Goldbach's conjecture is wrong.\n");
	else printf("%d = %d + %d\n", N, a, b);
}

int main()
{
	//freopen("output.txt", "w", stdout);
	prime[0] = prime[1] = 0;
	prime[2] = 1;
	for(int i = 3; i < SIZE; i++)
		prime[i] = 1;

	for(int i = 2; i*i < SIZE; i++)
	{
		if(prime[i])
			for(int j = i * i; j < SIZE; j += i)
				prime[j] = 0;
	}

	count = 0;
	for(int i = 3; i < SIZE; i++)
		if(prime[i]) p[count++] = i;

	while(std::cin >> N) {
		if(!N) break;
		f = 0;
		max = -1;
		solveCase();
		printCase();
	}

	return 0;
}