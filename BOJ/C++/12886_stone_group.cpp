#include <iostream>
#include <array>
#include <queue>

typedef unsigned short US;

std::array<std::array<bool, 1001>, 1001> gVisited;

bool BFS(const US& A, const US& B, const US& C)
{
	if ((A + B + C) % 3)
	{
		return false;
	}

	std::queue<std::pair<US, US>> BFSQueue;
	BFSQueue.push(std::make_pair(A, B));
	gVisited[A][B] = true;

	while (!BFSQueue.empty())
	{
		US NowA = BFSQueue.front().first;
		US NowB = BFSQueue.front().second;
		US NowC = A + B + C - (NowA + NowB);
		
		BFSQueue.pop();

		if (NowA == NowB && NowA == NowC)
		{
			return true;
		}

		std::array<std::pair<US, US>, 3> Combinations = {
			std::make_pair(NowA, NowB),
			std::make_pair(NowA, NowC),
			std::make_pair(NowB, NowC)
		};

		for (const auto& Pair : Combinations)
		{
			US NextA = Pair.first, NextB = Pair.second;

			if (NextA < NextB)
			{
				NextB -= NextA, NextA *= 2;
			}
			else if (NextA > NextB)
			{
				NextA -= NextB, NextB *= 2;
			}
			else
			{
				continue;
			}

			US NextC = A + B + C - (NextA + NextB);

			US MinStone = std::min(
				std::min(NextA, NextB),
				NextC
			);

			US MaxStone = std::max(
				std::max(NextA, NextB),
				NextC
			);

			if (!gVisited[MinStone][MaxStone])
			{
				gVisited[MinStone][MaxStone] = true;

				BFSQueue.push(
					std::make_pair(MinStone, MaxStone)
				);
			}
		}
	}
	return false;
}

int main(void)
{
	US A = 0, B = 0, C = 0;
	std::cin >> A >> B >> C;

	std::cout << (BFS(A, B, C) ? 1 : 0);
	return 0;
}