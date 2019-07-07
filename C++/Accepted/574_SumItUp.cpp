#include <iostream>
int total, N, sumCount;
int arr[20];
int used[20];
int res[100][20];
int temp[20];
int KK, MM;

int findMatch(int zz) {
	int f = 0;
	
	for(int i = 0; i <= MM; i++) {
		f = 0;
		for(int k = 0; k < zz; k++)
			if(res[i][k] != temp[k]) f = 1;
		if(!f) return 1;
	}

	return 0;
}

int checkAll() {
	int j = 0;
	for(int i = 0; i < N; i++)
		if(used[i]) temp[j++] = arr[i];
	KK = j;

	if(!findMatch(KK)) {
		for(int i = 0; i < KK; i++)
				res[MM][i] = temp[i];
		MM++;
		return 1;
	}

	return 0;
}

void resetAll() {
	sumCount = 0;
	MM = 0;
	for(int i= 0; i < N; i++)
		used[i] = temp[i] = 0;
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < N; j++)
			res[i][j] = 0;
}

void printResult() {
	sumCount++;
	int i;
	for(i = 0; i < N; i++)
		if(used[i]) { printf("%d", arr[i]); break;}
	for(int j = i+1; j < N; j++)
		if(used[j]) printf("+%d", arr[j]);
	printf("\n");
}



void solve(int i, int sum) {
	if(sum > total) return;
	if(sum == total) {
		if(checkAll())
			printResult();
		return;
	}

	if(i == N) {
		if(sum == total) printResult();
		return;
	}
	
	/*for(int j = 0; j < N; j++) if(!used[j]) {
		used[j] = 1;
		solveCase(i + 1, sum + arr[j]);
		used[j] = 0;
	}*/
	used[i] = 1;
	solve(i+1, sum + arr[i]);
	used[i] = 0;
	solve(i+1, sum);
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int val;
	while(std::cin >> total) {
		std::cin >> N;
		if(!N) break;

		for(int i = 0; i < N; i++)
			std::cin >> arr[i];
		//printAll();
		resetAll();
		printf("Sums of %d:\n", total);
		solve(0, 0);
		if(!sumCount) printf("NONE\n");
	}

	return 0;
}
