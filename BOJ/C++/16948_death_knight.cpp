#include <iostream>
#include <array>
#include <queue>

const short kMAX = 200;

const std::array<short, 6> gDy = {-2, -2, 0, 0, 2, 2};
const std::array<short, 6> gDx = {-1, 1, -2, 2, -1, 1};

std::array<std::array<short, kMAX>, kMAX> gVisited;

void BFS(const short& N, const short& r1, const short& c1)
{
	gVisited[r1][c1] = 0;

	std::queue<std::pair<short, short>> BFSQueue;
	BFSQueue.push(std::make_pair(r1, c1));

	while (!BFSQueue.empty())
	{
		std::pair<short, short> NowPos = BFSQueue.front();
		BFSQueue.pop();

		for (short i = 0; i < 6; ++i)
		{
			short Move = gVisited[NowPos.first][NowPos.second] < 0 ? 0
			: gVisited[NowPos.first][NowPos.second];

			std::pair<short, short> NextPos = std::make_pair(
				NowPos.first + gDy[i], NowPos.second + gDx[i]
			);

			if ((NextPos.first < N && NextPos.first >= 0)
				&& (NextPos.second < N && NextPos.second >= 0)
				&& gVisited[NextPos.first][NextPos.second] < 0)
			{
				gVisited[NextPos.first][NextPos.second] = ++Move;
				BFSQueue.push(NextPos);
			}
		}
	}
}

int main(void)
{
	short N = 0;
	std::cin >> N;

	short r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	std::cin >> r1 >> c1 >> r2 >> c2;

	for (auto& Row : gVisited)
	{
		std::fill(Row.begin(), Row.end(), -1);
	}

	BFS(N, r1, c1);

	std::cout << gVisited[r2][c2];
	return 0;
}