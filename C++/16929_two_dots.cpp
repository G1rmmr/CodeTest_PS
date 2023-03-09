#include <iostream>
#include <array>

static int g_x, g_y;

static const std::array<int, 4> 
	kX = {0, 1, 0, -1}, kY = {-1, 0, 1, 0};

static std::array<std::array<char, 50>, 50> g_graph;

static std::array<std::array<bool, 50>, 50> g_visited;

void DFS(int y, int x, int n, int m, int level) {
	g_visited[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		int nx = x + kX[i];
		int ny = y + kY[i];

		if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
			g_graph[y][x] == g_graph[ny][nx] &&!g_visited[ny][nx]) {
			DFS(ny, nx, n, m, level + 1);
		}

		else if (g_x == nx && g_y == ny && level >= 4) {
			std::cout << "Yes";
			exit(0);
		}
	}
	g_visited[y][x] = false;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> g_graph[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!g_visited[i][j]) {
				g_x = j, g_y = i;
				DFS(i, j, n, m, 1);
				g_visited[i][j] = true;
			}

	std::cout << "No";
	return 0;
}