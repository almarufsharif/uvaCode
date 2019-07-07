#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
	int u;
	int v;
	int weight;
	Edge(int uu, int vv, int ww) : u(uu), v(vv), weight(ww) { }
	Edge() { }
};

int N, K, M, connection;
std::vector<Edge> V;

int parent[1000000];
int rank[1000000];

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

bool cmp(const Edge& x, const Edge& y) {
	return x.weight < y.weight;
}

int mst() {
	int x, y;
	long cost = 0;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	std::sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < connection; i++) {
		x = findRoot(V[i].u);
		y = findRoot(V[i].v);
		if (x != y) {
			Union(x, y);
			cost += V[i].weight;
		}
	}

	return cost;
}

int main()
{
	int u, v, w, f = 0;

	while (std::cin >> N) {
		connection = N - 1;
		if (f) std::cout << std::endl;
		f = 1;

		for (int i = 0; i < connection; i++) {
			std::cin >> u >> v >> w;
			V.push_back(Edge(u - 1, v - 1, w));
		}

		std::cout << mst() << std::endl;
		V.clear();

		std::cin >> K;
		for (int i = 0; i < K; i++) {
			std::cin >> u >> v >> w;
			V.push_back(Edge(u - 1, v - 1, w));
		}

		std::cin >> M;
		for (int i = 0; i < M; i++) {
			std::cin >> u >> v >> w;
			V.push_back(Edge(u - 1, v - 1, w));
		}

		connection = K + M;
		std::cout << mst() << std::endl;
		V.clear();
	}

	return 0;
}