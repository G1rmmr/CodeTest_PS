#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>

static std::array<char, 20> g_signs;
static std::array<int, 10> g_visisted = { 0 };

bool IsRight(char n1, char n2, char sign) {
	if ((n1 < n2 && sign == '<') ||
		(n1 > n2 && sign == '>'))
		return true;

	else return false;
}

void Calc(std::vector<std::string>& seq,
	std::string num, int k, int level) {
	if (level == k + 1) {
		seq.emplace_back(num);
		return;
	}

	for (int i = 0; i < 10; ++i) {
		if (g_visisted[i]) continue;

		if (level == 0 || IsRight(
			num[level - 1], i + '0', g_signs[level - 1]
		)) {
			g_visisted[i] = 1;
			Calc(seq, num + std::to_string(i), k, level + 1);
			g_visisted[i] = 0;
		}
	}
	return;
}

int main() {
	int k;
	std::cin >> k;

	for(int i = 0; i < k; ++i)
		std::cin >> g_signs[i];

	std::vector<std::string> seq;

	Calc(seq, "", k, 0);
	std::sort(seq.begin(), seq.end());

	std::cout << *(seq.end() - 1) << '\n'
		<< *seq.begin();

	return 0;
}