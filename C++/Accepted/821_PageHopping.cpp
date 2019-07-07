#include <iostream>
#include <cstdio>
const int MAX = 50000;
int a, b;
int arr[110][110];

int main()
{
    int tc = 1;
    int maxNode = 0;
    while(std::cin >> a >> b) {
        for(int i = 0; i < 110; i++) {
            std::fill(arr[i], arr[i] + 110, MAX);
            arr[i][i] = 0;
        }

        if ( a == 0 && b == 0) break;
        arr[a][b] = 1;
        maxNode = std::max(maxNode, a);
        maxNode = std::max(maxNode, b);

        while(std::cin >> a >> b) {
            if ( a== 0 && b == 0) break;
            arr[a][b] = 1;
            maxNode = std::max(maxNode, a);
            maxNode = std::max(maxNode, b);
        }

        for(int k = 1; k <= maxNode; k++)
            for(int i = 1; i <= maxNode; i++)
                for(int j = 1; j <= maxNode; j++)
                    if(arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];

        int sum = 0;
        int link = 0;
        for(int i = 1; i <= maxNode; i++)
            for(int j = 1; j <= maxNode; j++) {
                if (arr[i][j] != MAX){ sum += arr[i][j];
                    if(arr[i][j] > 0) link++;
                }
            }
        float res = static_cast<float>(sum)/static_cast<float>(link);
        std::printf("Case %d: average length between pages = %.3f clicks\n", tc++, res);
    }

    return 0;
}
