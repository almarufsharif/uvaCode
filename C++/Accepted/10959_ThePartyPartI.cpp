#include <iostream>
#include <queue>
#include <stdio.h>
int arr[1010][1010];
int visit[1010];
int distance[1010];

int main()
{
    int testCase;
    scanf("%d", &testCase);
    int p, d;
    int x, y;
    while(testCase--){
        scanf("%d %d", &p, &d);
        for(int i = 0; i < p; i++)
            std::fill(arr[i], arr[i] + p, 0), std::fill(visit, visit+p, 0), std::fill(distance, distance + p, 0);
        for(int i = 0; i < d; i++) {
            scanf("%d %d", &x, &y);
            arr[x][y] = 1, arr[y][x] = 1;
        }

        visit[0] = 1;
        std::queue<int> Q;
        Q.push(0);
        while(Q.size() != 0) {
            int u = Q.front();
            for(int v = 0; v < p; v++){
                if(arr[u][v] && !visit[v]) {
                    visit[v] = 1;
                    distance[v] += distance[u] + 1;
                    Q.push(v);
                }
            }
            Q.pop();
        }

        for(int i = 0; i < p; i++)
            if(distance[i])
                printf("%d\n", distance[i]);
        if(testCase) printf("\n");
    }

    return 0;
}
