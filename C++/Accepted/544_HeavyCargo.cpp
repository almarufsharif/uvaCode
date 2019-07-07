#include <iostream>
#include <algorithm>
#include <map>
#include <string>

struct Edge {
	int u;
	int v;
	int weight;
};

std::map<std::string, int> mapM;
Edge edge[20000];
int parent[210];
int rank[210];
int N, M, start, end;

bool cmp(Edge &x, Edge &y) {
	return x.weight > y.weight;
}

int findRoot(int x) {
	while (x != parent[x]) {
		parent[x] = parent[parent[x]];
		x = parent[x];
	}

	return x;
}

void Union(int x, int y) {
	if (rank[x] > rank[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}
}

int kruskal() {
	int min, x, y;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	std::sort(edge, edge + M, cmp);
	min = edge[0].weight;
	for (int i = 0; i < M; i++) {
		x = findRoot(edge[i].u);
		y = findRoot(edge[i].v);

		if (x != y) {
			Union(x, y);
			if (min > edge[i].weight)
				min = edge[i].weight;
			if (findRoot(start) == findRoot(end))
				return min;
		}
	}

	if (findRoot(start) == findRoot(end))
		return min;
	else return -1;
}

int main()
{
	std::string uStr, vStr;
	int w, tc = 1;

	while (std::cin >> N >> M) {
		if (N == 0 && M == 0)
			break;
		for (int i = 0; i < M; i++) {
			std::cin >> uStr >> vStr >> w;
			mapM.insert(std::make_pair(uStr, mapM.size()));
			mapM.insert(std::make_pair(vStr, mapM.size()));
			edge[i].u = mapM[uStr];
			edge[i].v = mapM[vStr];
			edge[i].weight = w;
		}

		std::cin >> uStr >> vStr;
		mapM.insert(std::make_pair(uStr, mapM.size()));
		mapM.insert(std::make_pair(vStr, mapM.size()));
		start = mapM[uStr];
		end = mapM[vStr];

		std::cout << "Scenario #" << tc++ << std::endl;
		std::cout << kruskal() << " tons" << std::endl << std::endl;
		mapM.clear();
	}

	return 0;
}