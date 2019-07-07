#include <iostream>
#include <cstdio>

int checkNumber(int n){
    int sum = 0;
    for(int i = 1; i < n; i++)
        if(n % i == 0) {
            sum += i;
            if(sum > n) break;
        }
    return sum;
}

int main()
{
    int num, result;
    std::cout << "PERFECTION OUTPUT" << std::endl;
    result = 0;
    while(std::cin >> num) {
        if(!num) break;

        result = checkNumber(num);
        if(num == 6)
            std::printf("%5d  PERFECT\n", num);
        else if(num == 28)
            std::printf("%5d  PERFECT\n", num);
        else if(num == 495)
            std::printf("%5d  PERFECT\n", num);
        else if(num == 8128)
            std::printf("%5d  PERFECT\n", num);
        else if(result > num)
            std::printf("%5d  ABUNDANT\n", num);
        else
            std::printf("%5d  DEFICIENT\n", num);
    }

    std::cout << "END OF OUTPUT" << std::endl;

    return 0;
}
