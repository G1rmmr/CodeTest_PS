#include <iostream>
#include <array>
#include <queue>
#include <string>

std::array<bool, 10000> gVisited;

void BFS(const int& A, const int& B)
{
	std::queue<std::pair<int, std::string>> BFSQueue;
	BFSQueue.push(std::make_pair(A, ""));
	gVisited[A] = true;

	while (!BFSQueue.empty())
	{
		int Num = BFSQueue.front().first;
		std::string Command = BFSQueue.front().second;
		BFSQueue.pop();

		if (Num == B)
		{
			std::cout << Command << '\n';
			return;
		}

		int RegisterD = (Num * 2) % 10000;
		int RegisterS = !Num ? 9999 : Num - 1;
		int RegisterL = (Num % 1000) * 10 + Num / 1000;
		int RegisterR = Num / 10 + (Num % 10) * 1000;

		if (!gVisited[RegisterD])
		{
			gVisited[RegisterD] = true;
			BFSQueue.push(std::make_pair(RegisterD, Command + "D"));
		}
		
		if (!gVisited[RegisterS])
		{
			gVisited[RegisterS] = true;
			BFSQueue.push(std::make_pair(RegisterS, Command + "S"));
		}
		
		if (!gVisited[RegisterL])
		{
			gVisited[RegisterL] = true;
			BFSQueue.push(std::make_pair(RegisterL, Command + "L"));
		}
		
		if (!gVisited[RegisterR])
		{
			gVisited[RegisterR] = true;
			BFSQueue.push(std::make_pair(RegisterR, Command + "R"));
		}
	}
}

int main(void)
{
	int T = 0;
	std::cin >> T;

	while (T--)
	{
		int A, B;
		std::cin >> A >> B;

		std::fill(
			gVisited.begin(), gVisited.end(), false
		);
		
		BFS(A, B);
	}
	return 0;
}