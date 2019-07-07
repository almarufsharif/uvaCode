#include <iostream>
#include <stack>

int N, M, count, tCount;
std::stack<int> S;

int graph[2010][2010];
int tGraph[2010][2010];
int visit[2010];
int tVisit[2010];

void dfs_visit(int u) {
	for (int v = 0; v < N; v++)
		if (!visit[v] && graph[u][v]) {
			visit[v] = 1;
			count++;
			dfs_visit(v);
		}
}

void t_dfs_visit(int u) {
	for (int v = 0; v < N; v++)
		if (!tVisit[v] && tGraph[u][v]) {
			tVisit[v] = 1;
			tCount++;
			t_dfs_visit(v);
		}
}

int scc() {
	count = 0;
	tCount = 0;
	for (int i = 0; i < N; i++) {
		visit[i] = 0;
		tVisit[i] = 0;
	}
	visit[0] = 1;
	count++;
	dfs_visit(0);

	if (count == N) {
		tVisit[0] = 1;
		tCount++;
		t_dfs_visit(0);
	}
	else return 0;

	if (tCount == N) return 1;
	else return 0;
}

int main()
{
	int d, u, v;
	while (std::cin >> N >> M) {
		if (N == 0 && M == 0) break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (i == j) { graph[i][j] = 1; tGraph[i][j] = 1; }
				else { graph[i][j] = 0; tGraph[i][j] = 0; }
			}

		for (int i = 0; i < M; i++) {
			std::cin >> u >> v >> d;
			u--;
			v--;
			if (d == 1) {
				graph[u][v] = 1;
				tGraph[v][u] = 1;
			}
			else if (d == 2) {
				graph[u][v] = 1;
				graph[v][u] = 1;

				tGraph[u][v] = 1;
				tGraph[v][u] = 1;
			}
		}

		if (scc()) std::cout << "1" << std::endl;
		else std::cout << "0" << std::endl;
	}

	return 0;
}
