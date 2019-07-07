#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
struct Edge;
int node[2010];
int RANK[2010];
int noOfComputer;
int noOfConnection;
std::vector<Edge> v;

int findRoot(int root) {
    if ( node[root] == root) return root;
    else return findRoot(node[root]);
}

void Union(int root1, int root2) {
    int p = findRoot(root1);
    int q = findRoot(root2);
    if ( p == q) return;

    if (RANK[p] < RANK[q]) {
        node[q] = p;
        RANK[p]++;
    } else {
        node[p] = q;
        RANK[q]++;
    }
}

bool isConnected(int root1, int root2) {
    return findRoot(root1) == findRoot(root2);
}

struct Edge{
    int vertex1;
    int vertex2;
    int weight;
};
bool compare(const Edge& x, const Edge& y) {
    return x.weight < y.weight;
}
long Kruskal() {
    long mst = 0;
    std::sort(v.begin(), v.end(), compare);

    for(std::vector<Edge>::iterator it = v.begin(); it != v.end(); it++)
        if (!isConnected(it->vertex1, it->vertex2))
            Union(it->vertex1, it->vertex2), mst += it->weight;
    return mst;
}

int main()
{
    int testCase;
    std::cin >> testCase;
    std::string s1, s2, str;
    int w;
    std::map<std::string, int> m;
    Edge e;
    while(testCase--) {
        std::cin >> noOfComputer;
        std::cin >> noOfConnection;
        std::getline(std::cin, str);
        for(int i = 0; i < noOfComputer; i++) node[i] = i, RANK[i] = 0;

        for(int i = 0; i < noOfConnection; i++) {
            std::cin >> s1 >> s2 >> w;
            m.insert(std::make_pair(s1, m.size()));
            m.insert(std::make_pair(s2, m.size()));
            e.vertex1 = m[s1];
            e.vertex2 = m[s2];
            e.weight = w;
            v.push_back(e);
        }

        std::cout << Kruskal() << std::endl;
        if(testCase) std::cout << std::endl;
        v.clear();
        m.clear();
    }

    return 0;
}
