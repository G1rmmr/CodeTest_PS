#include <iostream>
#include <array>
#include <vector>

static std::array<std::vector<int>, 20001> g_graph;
static std::array<int, 20001> g_visited;

void DFS(int start) {
	if(!g_visited[start])
		g_visited[start] = 1;

	for (int i = 0; i < g_graph[start].size(); ++i) {
		int vertex = g_graph[start][i];

		if (!g_visited[vertex]) {
			if (g_visited[start] == 1)
				g_visited[vertex] = 2;

			else if (g_visited[start] == 2)
				g_visited[vertex] = 1;

			DFS(vertex);
		}
	}
}

bool IsBipartite(int v) {
	for (int i = 1; i <= v; ++i)
		for (int j = 0; j < g_graph[i].size(); ++j) {
			int vertex = g_graph[i][j];

			if (g_visited[i] == g_visited[vertex])
				return false;
		}
	return true;
}

int main() {
	int k;
	std::cin >> k;

	while (k--) {
		int v, e;
		std::cin >> v >> e;

		for (int i = 0; i < e; ++i) {
			int u, w;
			std::cin >> u >> w;
		
			g_graph[u].emplace_back(w);
			g_graph[w].emplace_back(u);
		}

		for (int i = 1; i <= v; ++i)
			if (!g_visited[i])
				DFS(i);

		std::cout << (IsBipartite(v) ? "YES\n" : "NO\n");

		for (int i = 0; i <= v; ++i)
			g_graph[i].clear();

		std::fill(
			g_visited.begin(), g_visited.end(), 0
		);
	}
	return 0;
}