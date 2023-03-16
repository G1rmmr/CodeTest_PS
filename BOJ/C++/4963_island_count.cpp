#include <iostream>
#include <array>

static const std::array<int, 8> 
	kX = {-1, 0, 1, -1, 1, -1, 0, 1 },
	kY = {-1, -1, -1, 0, 0, 1, 1, 1};

static std::array<std::array<int, 50>,
	50> g_graph = { 0 };

static std::array<std::array<bool, 50>,
	50> g_visited = { false };

void DFS(int y, int x, int w, int h) {
	for (int i = 0; i < 8; ++i) {
		int nx = x + kX[i];
		int ny = y + kY[i];

		if (nx < 0 || ny < 0 || nx >= w || ny >= h)
			continue;

		if (!g_visited[ny][nx] && g_graph[ny][nx]) {
			g_visited[ny][nx] = true;
			DFS(ny, nx, w, h);
		}
	}
}

int main() {
	int w, h;

	while (true) {
		std::cin >> w >> h;

		if (!(w + h)) break;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				std::cin >> g_graph[i][j];
			
		int count = 0;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (!g_visited[i][j] && g_graph[i][j]) {
					g_visited[i][j] = true;
					DFS(i, j, w, h);
					count++;
				}

		std::cout << count << '\n';

		for (auto& col : g_visited)
			for (auto& e : col)
				e = false;
	}
	return 0;
}