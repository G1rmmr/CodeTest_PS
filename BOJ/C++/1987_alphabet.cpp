#include <iostream>
#include <algorithm>
#include <array>
#include <string>

static const std::array<short, 4> gY = {-1, 0, 0, 1};
static const std::array<short, 4> gX = {0, -1, 1, 0};

static std::array<std::string, 21> gBoard;
static std::array<std::array<short, 21>, 21> gVisited;
static std::array<bool, 26> gTraced;

void DFS(
	const short& R, const short& C,
	const short& Y, const short& X,
	const short& Count)
{
	for (short i = 0; i < 4; ++i)
	{
		short NextY = Y + gY[i], NextX = X + gX[i];

		if ((NextY >= 0 && NextY < R && NextX >= 0 && NextX < C)
			&& !gTraced[gBoard[NextY][NextX] - 'A'])
		{
			if (gVisited[NextY][NextX] < Count + 1)
			{
				gVisited[NextY][NextX] = Count + 1;
			}
			gTraced[gBoard[NextY][NextX] - 'A'] = true;
			
			DFS(R, C, NextY, NextX, Count + 1);
			gTraced[gBoard[NextY][NextX] - 'A'] = false;
		}
	}
}

int main()
{
	short R = 0, C = 0;
	std::cin >> R >> C;

	for (short i = 0; i < R; ++i)
	{
		std::cin >> gBoard[i];
	}

	gVisited[0][0] = 1;
	gTraced[gBoard[0][0] - 'A'] = true;

	DFS(R, C, 0, 0, 1);

	short MaxCount = 0;

	for (short i = 0; i < R; ++i)
	{
		for (short j = 0; j < C; ++j)
		{
			MaxCount = std::max(MaxCount, gVisited[i][j]);
		}
	}
	std::cout << MaxCount;
	return 0;
}