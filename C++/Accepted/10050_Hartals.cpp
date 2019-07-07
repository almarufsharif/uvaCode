#include <iostream>
#include <numeric>
#include <algorithm>

int arr[3660];

int main()
{
    int testCase, nDay, nParty, day;
    std::cin >> testCase;
    while(testCase--) {
        std::cin >> nDay;
        std::fill(arr, arr + nDay + 1, 0);
        std::cin >> nParty;

        for(int i = 0; i < nParty; i++) {
            std::cin >> day;
            for(int j = day; j <= nDay; j += day) arr[j] = 1;
        }

        // remove friday and saturday;
        for(int i = 6; i <= nDay; i += 7) arr[i] = 0;
        for(int i = 7; i <= nDay; i += 7) arr[i] = 0;

        std::cout << std::accumulate(arr, arr + nDay + 1, 0) << std::endl;
    }

    return 0;
}
