#include <iostream>
#include <algorithm>

struct Edge {
	int u;
	int v;
	int weight;
};

Edge edge[10100];
int parent[120];
int rank[120];
int N, M, start, end;

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

bool cmp(Edge &x, Edge&y) {
	return x.weight > y.weight;
}

int kruskal() {
	int x, y, min;
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

	return min;
}

int main()
{
	int u, v, w, cost, result, tc = 1;
	while (std::cin >> N >> M) {
		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < M; i++) {
			std::cin >> u >> v >> w;
			edge[i].u = u - 1;
			edge[i].v = v - 1;
			edge[i].weight = w;
		}

		std::cin >> start >> end >> w;
		start--;
		end--;
		cost = kruskal();
		cost--;
		result = w / cost;
		if (w%cost != 0)
			result++;
		if (start == end) result = 1;
		std::cout << "Scenario #" << tc++ << std::endl;
		std::cout << "Minimum Number of Trips = " << result << std::endl << std::endl;
	}

	return 0;
}