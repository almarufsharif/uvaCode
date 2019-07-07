#include <iostream>
#include <sstream>

int graph[120][120];
int visit[120];
int N, nVisit;

void dfs(int u) {
	for (int v = 0; v < N; v++) {
		if (graph[u][v] && visit[v] == 0) {
			visit[v] = 1;
			nVisit--;
			dfs(v);
		}
	}
}

int main()
{
	std::string str;
	int from, num;
	while (std::cin >> N) {
		if (N == 0)
			break;
		std::getline(std::cin, str);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				graph[i][j] = 0;
		while (std::getline(std::cin, str)) {
			std::stringstream ss(str);
			ss >> from;
			if (from == 0) break;
			while (ss >> num) {
				graph[from - 1][num - 1] = 1;
				graph[num - 1][from - 1] = 1;
			}
		}

		int count = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				visit[j] = 0;
			visit[i] = 1;
			nVisit = N - 1;

			if (i == 0 && N > 1) {
				visit[1] = 1;
				nVisit--;
				dfs(1);
			}
			else {
				visit[0] = 1;
				nVisit--;
				dfs(0);
			}
			if(nVisit)
				count++;
			visit[i] = 0;
		}

		std::cout << count << std::endl;
		
	}
	return 0;
}