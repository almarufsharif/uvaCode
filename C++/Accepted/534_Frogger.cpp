#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

struct Point {
	int x;
	int y;
};

struct Edge {
	int u;
	int v;
	double w;
};

Point point[210];
Edge edge[41000];
int parent[210];
int rank[210];
int N, M;

bool cmp(Edge &x, Edge &y) {
	return x.w < y.w;
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

double kruskal() {
	double max;
	int x, y;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	std::sort(edge, edge + M, cmp);
	max = edge[0].w;
	for (int i = 0; i < M; i++) {
		x = findRoot(edge[i].u);
		y = findRoot(edge[i].v);
		
		if (x != y) {
			Union(x, y);
			if (max < edge[i].w)
				max = edge[i].w;
			if (findRoot(0) == findRoot(1))
				return max;
		}
	}

	if (findRoot(0) == findRoot(0))
		return max;
	else - 1;
}

int main()
{
	int tc = 1;
	while (std::cin >> N) {
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			std::cin >> point[i].x >> point[i].y;

		M = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				edge[M].u = i;
				edge[M].v = j;
				edge[M].w = std::sqrt((double)((point[i].x - point[j].x) * (point[i].x - point[j].x)) + ((point[i].y - point[j].y) * (point[i].y - point[j].y)));
				M++;
			}
		std::cout << "Scenario #" << tc++ << std::endl;
		std::cout << "Frog Distance = " << std::setprecision(3) << std::fixed << kruskal() << std::endl << std::endl;
	}

	return 0;
}