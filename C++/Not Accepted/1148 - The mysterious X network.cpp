#include <iostream>
#include <list>
#include <queue>

std::list<int> graph[100010];
int distance[100010];
int visit[100010];
int N, max, dest;

int bfs(int src) {
	for (int i = 0; i < max; i++) {
		distance[i] = 0;
		visit[i] = 0;
	}

	distance[src] = 0;
	std::queue<int> Q;
	Q.push(src);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		visit[u] = 1;
		for (std::list<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
			if (!visit[*it]) {
				distance[*it] = distance[u] + 1;
				Q.push(*it);
			}
	}

	return distance[dest] - 1;
}

int main()
{
	int tCase, count, u, val;
	std::cin >> tCase;

	while (tCase--) {
		std::cin >> N;
		max = N + 1;
		for (int i = 0; i < N; i++) {
			std::cin >> u >> count;
			if (count > max) max = count + 1;
			for (int j = 0; j < count; j++) {
				std::cin >> val;
				if (val > max) max = val + 1;
				graph[i].push_back(val);
			}
		}

		std::cin >> u >> dest;
		std::cout << u << " " << dest << " " << bfs(u) << std::endl;
		if (tCase) std::cout << std::endl;

		for (int i = 0; i < max; i++)
			graph[i].clear();
	}

	return 0;
}