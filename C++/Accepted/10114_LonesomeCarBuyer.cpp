#include <iostream>
#include <cmath>
const double epsion = 0.0000001;
int main()
{
    int N, n, i;
    double down, amount, owe, worth, rate;
    double arr[110];
    double prev;
    int index;

    while(std::cin >> N >> down >> amount >> n) {
            if(N < 0 || down < 0 || amount < 0 || n < 0) break;
    std::fill(arr, arr + N, 0);

    for(int i = 0; i < n; i++) {
        std::cin >> index;
        std::cin >> arr[index];
    }
    prev = arr[0];
    for(int i = 0; i < N; i++) {
        if(std::abs(arr[i] - 0) < epsion)
            arr[i] = prev;
        else {
            prev = arr[i];
        }
    }
    owe = amount;
    worth = amount + down;
    rate = amount / N;
    for(i = 0; i < N; i++){
        worth -= worth * arr[i];
        if ( owe < worth) break;
        owe -= rate;
    }

    if(i  == 1) std::cout << "1 month" << std::endl;
    else std::cout << i << " months" << std::endl;

    }

    return 0;
}
