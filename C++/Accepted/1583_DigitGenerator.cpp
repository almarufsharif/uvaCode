#include <iostream>
#include <algorithm>
int arr[100010];
int digitSum(int i)
{
    int sum  = 0;
    sum += i;
    while(i) {
        sum += i%10;
        i /= 10;
    }
    return sum;
}

int digitS(int n) {
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    for(int i = 0; i < 100010; i++)
        arr[i] = digitSum(i);
    int testCase, num, f, index;
    std::cin >> testCase;
    while(testCase--) {
        std::cin >> num;
        f = 0;
        if(num > 90) {
            for(int i = num - 54; i <= num; i++)
                if(arr[i] == num) {index = i; f = 1; break;}
        }
        else {
            for(int i = 0; i <= num; i++)
            if(arr[i] == num) { index = i, f = 1; break;}
        }
        if(f) std::cout << index << std::endl;
        else std::cout << 0 << std::endl;
    }

    return 0;
}
