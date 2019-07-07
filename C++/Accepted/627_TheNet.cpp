#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <sstream>
const int NIL = 1234567890;

int N, M, Q;
int U, V;
int graph[350][350];
int visit[350];
int predecessor[350];
int index;
std::string str;

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			graph[i][j] = 0;
}

int bfs(int src) {
	for (int i = 0; i < N; i++)
		visit[i] = 0;
	std::queue<int> Q;
	visit[src] = 1;
	predecessor[src] = NIL;
	Q.push(src);
	index = 0;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		visit[u] = 1;

		for (int v = 0; v < N; v++)
			if (graph[u][v] && !visit[v]) {
				Q.push(v);
				visit[v] = 1;
				predecessor[v] = u;
				index = v;
				if (visit[V] == 1) return 1;
			}
	}

	if (visit[V] == 1) return 1;
	else return 0;

}

void print(int i) {
	if (predecessor[i] == NIL) {
		std::cout << i + 1;
		return;
	}
	print(predecessor[i]);
	std::cout << " " << i + 1;
}

int main()
{
	int u, v;
	char ch, buf;
	while (std::cin >> N) {
		std::getline(std::cin, str);
		for (int i = 0; i < N; i++) {
			std::getline(std::cin, str);
			std::stringstream ss(str);
			ss >> u;
			if (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '-')
				ss.ignore();
			while (ss >> v) {
				graph[u - 1][v - 1] = 1;
				if (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '-')
					ss.ignore();
			}
		}

		std::cin >> Q;
		std::cout << "-----" << std::endl;
		for (int i = 0; i < Q; i++) {
			std::cin >> U >> V;
			U--, V--;
			int f = bfs(U);
			if (f)
				print(index);
			else
				std::cout << "connection impossible";
			std::cout << std::endl;
		}
		init();
	}

	return 0;
}