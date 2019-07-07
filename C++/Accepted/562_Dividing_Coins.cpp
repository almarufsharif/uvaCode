#include <iostream>
int N, total;
int val[101], dp[101][50001];

int myAbs(int n) {
	if (n < 0)
		return -n;
	return n;
}

int min(int x, int y) {
	if(x > y)
		return y;
	return x;
}

int solve(int i, int sum1) {
	if(dp[i][sum1] != -1)
		return dp[i][sum1];
	if(i == N) {
		int sum2 = total - sum1;
		return (dp[i][sum1] = myAbs(sum1 - sum2));
	}

	int left, right;
	left = solve(i+1, sum1);
	right = solve(i+1, sum1 + val[i]);

	return (dp[i][sum1] = min(left, right));
}

int main()
{
	int tc;
	std::cin >> tc;

	while(tc--) {
		std::cin >> N;
		total = 0;
		for(int i = 0; i < N; i++) {
			std::cin >> val[i];
			total += val[i];
		}
		
		for(int i = 0; i <= N; i++)
			for(int j = 0; j < 50001; j++)
				dp[i][j] = -1;
		std::cout << solve(0, 0) << std::endl;
	}

	return 0;
}