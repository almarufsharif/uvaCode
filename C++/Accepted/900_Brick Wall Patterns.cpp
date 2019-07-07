#include <iostream>
long long num[51];
long long pattern(int n) {
    if (n < 4) return num[n];
    else if (num[n] != -1) return num[n];
    else {
        long long x = pattern(n-1) + pattern(n-2);
        num[n] = x;
        return x;
    }
}

int main()
{
    int n;
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;
    num[3] = 3;

    for(int i = 4; i < 51; i++)
        num[i] = -1;

    while(std::cin >> n) {
        if (n == 0) break;
        std::cout << pattern(n) << std::endl;
    }

    return 0;
}
