#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <list>
#include <vector>

int N, M;
std::map<std::string, int> mapStrInt;
std::map<int, std::string> mapIntStr;
std::list<int> graph[120];
std::stack<int> Stack;
int visit[120];
std::vector<int> V;

void dfs(int src) {
	visit[src] = 1;
	for (std::list<int>::iterator it = graph[src].begin(); it != graph[src].end(); it++)
		if (visit[*it] == 0) {
			visit[*it] = 1;
			dfs(*it);
		}
	Stack.push(src);
}

int main()
{
	std::string str, uStr, vStr;
	int tc = 1;
	while (std::cin >> N) {
		for (int i = 0; i < N; i++) {
			std::cin >> str;
			mapStrInt.insert(std::make_pair(str, mapStrInt.size()));
			mapIntStr.insert(std::make_pair(mapStrInt[str], str));
		}
		std::cin >> M;
		for (int i = 0; i < M; i++) {
			std::cin >> uStr >> vStr;
			graph[mapStrInt[uStr]].push_back(mapStrInt[vStr]);
		}

		for (int i = 0; i < mapStrInt.size(); i++)
			visit[i] = 0;
		V.clear();

		for (int i = 0; i < mapStrInt.size(); i++)
			if (visit[i] == 0) {
				dfs(i);
				while (!Stack.empty()) {
					V.push_back(Stack.top());
					Stack.pop();
				}
			}
		std::cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
		for (std::vector<int>::iterator it = V.begin(); it != V.end(); it++)
			std::cout << " " << mapIntStr[*it];
		std::cout << "." << std::endl << std::endl;

		for (int i = 0; i < N; i++)
			graph[i].clear();
		mapStrInt.clear();
		mapIntStr.clear();
	}

	return 0;
}