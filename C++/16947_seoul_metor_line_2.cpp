#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

static std::vector<int> g_graph[3001];
static std::vector<bool> g_visited(3001), g_cycle(3001);

void DFS(int now, int start, int level, bool& is_cycle) {
	if (now == start && level >= 2) {
		is_cycle = true;
		return;
	}

	g_visited[now] = true;

	for (int i = 0; i < g_graph[now].size(); ++i) {
		int next = g_graph[now][i];

		if (!g_visited[next])
			DFS(next, start, level + 1, is_cycle);

		else if (next == start && level >= 2)
			DFS(next, start, level, is_cycle);

		if (is_cycle) return;
	}
}

int BFS(int start) {
	std::fill(g_visited.begin(), g_visited.end(), false);

	std::queue<std::pair<int, int>> buf;

	buf.push(std::make_pair(start, 0));
	g_visited[start] = true;

	while (!buf.empty()) {
		std::pair<int, int> node = buf.front();
		buf.pop();

		if (g_cycle[node.first]) return node.second;

		for (int i = 0; i < g_graph[node.first].size(); ++i) {
			int next = g_graph[node.first][i];

			if (!g_visited[next]) {
				g_visited[next] = true;
				buf.push(std::make_pair(next, node.second + 1));
			}
		}
	}
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;

		g_graph[u].emplace_back(v);
		g_graph[v].emplace_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		std::fill(g_visited.begin(), g_visited.end(), false);
		bool is_cycle = false;

		int start = i;
		DFS(i, start, 0, is_cycle);

		if (is_cycle)
			g_cycle[i] = true;
	}

	std::vector<int> dists;

	for (int i = 1; i <= n; ++i)
		if (g_cycle[i]) dists.emplace_back(0);
		else dists.emplace_back(BFS(i));

	for (auto const e : dists)
		std::cout << e << ' ';

	return 0;
}