#include <iostream>
#include <cstdio>
int I, J, row[8];
int lineCounter;

int myAbs(int n) {
	if(n < 0)
		return -n;
	return n;
}

int place(int r, int c) {
	for(int p = 0; p < c; p++)
		if(row[p] == r || (myAbs(row[p] - r) == abs(p - c)))
			return false;
	return true;

}

void solve(int c) {
	if(c == 8 && row[J] == I) {
		printf("%2d      %d", ++lineCounter, row[0]+1);
		for(int i = 1; i < 8; i++)
			std::cout << " " << row[i]+1;
		std::cout << std::endl;
	}

	for(int r = 0; r < 8; r++)
		if(place(r, c))
			row[c] = r, solve(c + 1);
}

int main()
{
	int tc;
	std::cin >> tc;
	while(tc--) {
		std::cin >> I >> J;
		I--, J--;
		for(int i = 0; i < 8; i++)
			row[i] = 0;
		lineCounter = 0;
		std::printf("SOLN       COLUMN\n");
		std::printf(" #      1 2 3 4 5 6 7 8\n\n");
		solve(0);
		if(tc) std::cout << std::endl;
	}

	return 0;
}