#include <iostream>
#include <algorithm>
#include <array>

static std::array<int, 10> g_s;
static std::vector<int> g_start, g_link;

int Sum(std::vector<int>& team) {
	int sum = 0;

	for (auto i : team)
		for (auto j : team)
			sum += g_s[i][j];

	return sum;
}

void MinDiff(int n, int level, int& min_diff) {
	if (level == n) {
		min_diff = std::min(
			min_diff, std::abs(Sum(g_start) - Sum(g_link))
		);
		return;
	}
	g_start.emplace_back(level);
	MinDiff(n, level + 1, min_diff);
	g_start.pop_back();

	g_link.emplace_back(level);
	MinDiff(n, level + 1, min_diff);
	g_link.pop_back();
}

int main() {
	int n, min_diff = 2000000;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> g_s[i][j];

	MinDiff(n, 0, min_diff);

	std::cout << min_diff;
	return 0;
}