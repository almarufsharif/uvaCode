#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

struct Point{
    double x;
    double y;
};

struct Edge{
    int u;
    int v;
    double weight;
};

Edge edge[10010];
Point point[110];
int parent[110];
int rank[110];
int N, nEdge;
double cost;

bool cmp(Edge x, Edge y) {
    return x.weight < y.weight;
}

int findRoot(int x) {
    while(x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

void Union(int x, int y) {
    if(rank[x] > rank[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }
}

void kruskal() {
    cost = 0;
    int x, y;
    std::sort(edge, edge + nEdge, cmp);
    for(int i = 0; i < N; i++) {
        parent[i] = i;
        rank[i] = 1;
    }

    for(int i = 0; i < nEdge; i++) {
        x = findRoot(edge[i].u);
        y = findRoot(edge[i].v);
        if(x != y) {
            Union(x, y);
            cost += edge[i].weight;
        }
    }
}

int main()
{
    int tCase;
    std::cin >> tCase;

    while(tCase--) {
        std::cin >> N;
        for(int i = 0; i < N; i++)
            std::cin >> point[i].x >> point[i].y;

        nEdge = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                edge[nEdge].u = i;
                edge[nEdge].v = j;
                edge[nEdge].weight = std::sqrt(((point[i].x - point[j].x)*(point[i].x - point[j].x)) +
                                               ((point[i].y - point[j].y) * (point[i].y - point[j].y)));
                nEdge++;
            }
        kruskal();
        std::printf("%.2f\n", cost);
        if(tCase) std::cout << std::endl;
    }

    return 0;
}
