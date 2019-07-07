#include <iostream>
#include <algorithm>

int graph[120][120];
int N, M;

void floydWarshall() {
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				graph[i][j] = std::max(graph[i][j], std::min(graph[i][k], graph[k][j]));
}
int main()
{
	int u, v, w, cost, result, tc = 1;
	while (std::cin >> N >> M) {
		if (N == 0 && M == 0)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				graph[i][j] = 0;
		for (int i = 0; i < M; i++) {
			std::cin >> u >> v >> w;
			graph[u - 1][v - 1] = w;
			graph[v - 1][u - 1] = w;
		}

		floydWarshall();
		std::cin >> u >> v >> w;
		u--;
		v--;
		cost = graph[u][v];
		cost--;
		result = w / cost;
		if (w%cost != 0)
			result++;
		if (u == v) result = 1;
		std::cout << "Scenario #" << tc++ << std::endl;
		std::cout << "Minimum Number of Trips = " << result << std::endl << std::endl;
	}

	return 0;
}