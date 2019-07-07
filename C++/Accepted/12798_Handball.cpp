#include <iostream>

int main()
{
    int N, M;
    int num;
    int f = 0, count;
    while(std::cin >> N >> M) {
        count = 0;
        for(int i = 0; i < N; i++) {
                f = 1;
            for(int j = 0; j < M; j++) {
                std::cin >> num;
                if (num <= 0) f = 0;
            }
            if(f)count++;
        }
        std::cout << count << std::endl;
    }

    return 0;
}
