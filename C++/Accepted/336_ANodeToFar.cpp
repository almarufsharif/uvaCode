#include <iostream>
#include <map>
#include <queue>

int arr[35][35];
int size;
int vis;
int visit[35];
int distance[35];

void bfs(int source, int step) {
    if(step == 0) {
        if (source >=0 && source < size){
            vis++;
            return;
        } else {
            vis = 0;
            return;
        }
    }
    std::fill(visit, visit + size, 0);
    std::fill(distance, distance + size, 0);
    std::queue<int> Q;

    if(source >=0 && source < size) visit[source] = 1, vis++;

    Q.push(source);

    while(Q.size() != 0) {
        int u = Q.front();

        for(int v = 0; v < size; v++) {
            if (arr[u][v] == 1 && visit[v] == 0) {
                visit[v] = 1;
                distance[v] = distance[u] + 1;
                if (distance[v] <= step) vis++;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int main()
{
    int n;
    int a, b;
    std::map<int, int> m;
    int x, y;
    int tc = 1;
    while(std::cin >> n) {
        if (n == 0) break;

        for(int i = 0; i < 35; i++)
            std::fill(arr[i], arr[i] + 35, 0);
        for(int i = 0; i < n; i++){
            std::cin >> a >> b;
            m.insert(std::make_pair(a, m.size()));
            m.insert(std::make_pair(b, m.size()));
            if(m[a] != m[b])
                arr[m[a]][m[b]] = 1, arr[m[b]][m[a]] = 1;

        }
        size = m.size();
        while(std::cin >> x >> y) {
            if (x == 0 && y == 0) break;
            vis = 0;
            m.insert(std::make_pair(x, m.size()));
            bfs(m[x], y);
            std::cout << "Case " << tc++ << ": " << size - vis << " nodes not reachable from node " << x << " with TTL = " << y << "." << std::endl;
        }
        m.clear();
    }

    return 0;
}
