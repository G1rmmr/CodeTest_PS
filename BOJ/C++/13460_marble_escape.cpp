#include <iostream>
#include <array>
#include <vector>
#include <string>

static const std::array<short, 4> gDy = {0, 0, 1, -1};
static const std::array<short, 4> gDx = {1, -1, 0, 0};

static const short kLIMIT = 10;

std::vector<int> Generate(int K)
{
	std::vector<int> Seq(kLIMIT);

	for (auto& Num : Seq)
	{
		Num = (K & 3);
		K >>= 2;
	}
	return Seq;
}

bool IsValid(std::vector<int>& Direction)
{
	int Length = Direction.size();

	for (int i = 0; i < Length - 1; i++)
	{
		if (!Direction[i] && Direction[i + 1] == 1)
		{
			return false;
		}
		else if (Direction[i] == 1 && !Direction[i + 1])
		{
			return false;
		}
		else if (Direction[i] == 2 && Direction[i + 1] == 3)
		{
			return false;
		}
		else if (Direction[i] == 3 && Direction[i + 1] == 2)
		{
			return false;
		}
		else if (Direction[i] == Direction[i + 1])
		{
			return false;
		}
	}
	return true;
}

std::pair<bool, bool> Simulate(
	std::vector<std::string>& Board,
	const int& K, short& Y, short& X)
{
	if (Board[Y][X] == '.')
	{
		return std::make_pair(false, false);
	}

	bool bMoved = false;

	while (true)
	{
		short NextY = Y + gDy[K], NextX = X + gDx[K];

		if (Board[NextY][NextX] == '#')
		{
			return std::make_pair(bMoved, false);
		}
		else if(Board[NextY][NextX] == 'R' || Board[NextY][NextX] == 'B')
		{
			return std::make_pair(bMoved, false);
		}
		else if (Board[NextY][NextX] == '.')
		{
			std::swap(Board[NextY][NextX], Board[Y][X]);
			Y = NextY, X = NextX;
			bMoved = true;
		}
		else if (Board[NextY][NextX] == 'O')
		{
			Board[Y][X] = '.';
			bMoved = true;
			return std::make_pair(bMoved, true);
		}
	}
	return std::make_pair(false, false);
}

int Check(std::vector<std::string> Board,
	std::vector<int>& Direction)
{
	short N = Board.size(), M = Board[0].size();
	short HoleY, HoleX, RedY, RedX, BlueY, BlueX;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Board[i][j] == 'O')
			{
				HoleY = i, HoleX = j;
			}
			else if (Board[i][j] == 'R')
			{
				RedY = i, RedX = j;
			}
			else if (Board[i][j] == 'B')
			{
				BlueY = i, BlueX = j;
			}
		}
	}

	int RotCount = 0;

	for (int Dir : Direction)
	{
		RotCount++;
		bool Hole1 = false, Hole2 = false;

		while (true)
		{
			auto Pos1 = Simulate(Board, Dir, RedY, RedX);
			auto Pos2 = Simulate(Board, Dir, BlueY, BlueX);

			if (!Pos1.first && !Pos2.first)
			{
				break;
			}
			
			if (Pos1.second)
			{
				Hole1 = true;
			}

			if (Pos2.second)
			{
				Hole2 = true;
			}
		}

		if (Hole2) {return -1;}
		if (Hole1) {return RotCount;}
	}
	return -1;
}

int main(void)
{
	short N = 0, M = 0;
	std::cin >> N >> M;

	std::vector<std::string> Board(N);

	for (auto& Col : Board)
	{
		std::cin >> Col;
	}

	int MinRot = -1;

	for (int k = 0; k < (1 << (kLIMIT * 2)); ++k)
	{
		std::vector<int> Direction = Generate(k);
		if (!IsValid(Direction)) {continue;} 

		int Cur = Check(Board, Direction);

		if (Cur < 0) {continue;}
		if (MinRot < 0 || MinRot > Cur) {MinRot = Cur;}
	}
	std::cout << MinRot;
	return 0;
}