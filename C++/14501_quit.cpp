#include <iostream>
#include <algorithm>
#include <array>

static std::array<int, 16> t, p;

void MaxCost(
	int n, int date, int cost, int& max_cost
) {
	if (cost >= max_cost)
		max_cost = cost;

	for (int i = date; i <= n; ++i) {
		if (t[i] + i > n + 1)
			continue;

		MaxCost(n, t[i] + i, p[i] + cost, max_cost);
	}
	return;
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; ++i)
		std::cin >> t[i] >> p[i];

	int max_cost = 0;

	for (int i = 1; i <= n; ++i) {
		if (t[i] + i > n + 1)
			continue;

		int cost = 0;

		MaxCost(n, t[i] + i, p[i], cost);
		max_cost = std::max(max_cost, cost);
	}
	std::cout << max_cost;
	return 0;
}