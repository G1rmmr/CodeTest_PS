#include <iostream>
#include <array>

static std::array<std::array<char, 10>, 10> g_signs;

bool IsRight(std::array<int, 10>& seq, int level) {
	int sum = 0;

	for (int i = level; i >= 0; --i) {
		sum += seq[i];

		if ((sum <= 0 && g_signs[i][level] == '+') ||
			(sum >= 0 && g_signs[i][level] == '-') ||
			(sum != 0 && g_signs[i][level] == '0'))
			return false;
	}
	return true;
}

void GetSeq(std::array<int, 10>& seq,
	int n, int level) {
	if (level == n) {
		for (int i = 0; i < n; ++i)
			std::cout << seq[i] << ' ';

		exit(0);
	}

	for (int i = -10; i <= 10; ++i) {
		seq[level] = i;

		if (IsRight(seq, level))
			GetSeq(seq, n, level + 1);
	}
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			std::cin >> g_signs[i][j];

	std::array<int, 10> seq;
	
	GetSeq(seq, n, 0);
	return 0;
}