#include <iostream>
#include <limits>

int nVertex, nPath;
const int INF = 2000000;
struct Edge{
    int v1;
    int v2;
    int weight;
};

Edge paths[2010];
int vertex[1010];

void relax(int u, int v, int w) {
    if(vertex[v] > vertex[u] + w)
        vertex[v] = vertex[u] + w;
}

int bellmanFord() {
    for(int i = 0; i < nVertex; i++)
        vertex[i] = INF; //std::numeric_limits<int>::max();
    vertex[0] = 0;

    for(int i = 0; i < nVertex - 1; i++)
        for(int j = 0; j < nPath; j++)
            relax(paths[j].v1, paths[j].v2, paths[j].weight);

    // negative cycle detection
    for(int i = 0; i < nPath; i++)
        if(vertex[paths[i].v2] > vertex[paths[i].v1] + paths[i].weight)
            return 1;

    return 0;
}

int main()
{
    int tc;
    std::cin >> tc;

    while(tc--) {
        std::cin >> nVertex >> nPath;
        for(int i = 0; i < nPath; i++)
            std::cin >> paths[i].v1 >> paths[i].v2 >> paths[i].weight;

        if(bellmanFord()) std::cout << "possible" << std::endl;
        else std::cout << "not possible" << std::endl;
    }

    return 0;
}
