#include <iostream>
#include <algorithm>
#include <vector>

static const int kLIMIT = 5;

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

void Initialize(std::vector<std::vector<int>>& Board)
{
	int N = Board.size();
	
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			
			std::swap(Board[i][j], Board[j][i]);
		}
	}
}

void Simulate(std::vector<std::vector<int>>& Board)
{
	int N = Board.size(), Count = 0;

	for (auto& Row : Board)
	{
		Count = 0;

		for (int i = 0; i < Row.size(); ++i)
		{
			if (!Row[i])
			{
				Row.erase(Row.begin() + i);
				i--, Count++;
			}
		}

		while (Count--)
		{
			Row.emplace_back(0);
		}
	}

	for (auto& Row : Board)
	{
		Count = 0;

		for (int i = 0; i < Row.size() - 1; ++i)
		{
			if (Row[i] == Row[i + 1])
			{
				Row[i] *= 2;
				Row.erase(Row.begin() + i + 1);
				Count++;
			}
		}

		while (Count--)
		{
			Row.emplace_back(0);
		}
	}
}

void MoveLeft(std::vector<std::vector<int>>& Board)
{
	Simulate(Board);
}

void MoveUp(std::vector<std::vector<int>>& Board)
{
	Initialize(Board);
	Simulate(Board);
	Initialize(Board);
}

void MoveRight(std::vector<std::vector<int>>& Board)
{
	for (auto& Row : Board)
	{
		std::reverse(Row.begin(), Row.end());
	}

	Simulate(Board);

	for (auto& Row : Board)
	{
		std::reverse(Row.begin(), Row.end());
	}
}

void MoveDown(std::vector<std::vector<int>>& Board)
{
	Initialize(Board);
	
	for (auto& Row : Board)
	{
		std::reverse(Row.begin(), Row.end());
	}

	Simulate(Board);

	for (auto& Row : Board)
	{
		std::reverse(Row.begin(), Row.end());
	}

	Initialize(Board);
}

void Interface(const int& K, std::vector<std::vector<int>>& Board)
{
	switch (K)
	{
	case 0:
		MoveUp(Board);
		break;

	case 1:
		MoveDown(Board);
		break;

	case 2:
		MoveRight(Board);
		break;

	case 3:
		MoveLeft(Board);
		break;
	}
}

int GetMaxNum(std::vector<std::vector<int>> Board,
	const std::vector<int>& GeneratedRow)
{
	int RowSize = GeneratedRow.size();
	int MaxNum = -1, N = Board.size();

	for (int i = 0; i < RowSize; ++i)
	{
		Interface(GeneratedRow[i], Board);
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				MaxNum = std::max(MaxNum, Board[i][j]);
			}
		}
	}
	return MaxNum;
}

int main(void)
{
	int N = 0,  MaxNum = -1;
	std::cin >> N;

	std::vector<std::vector<int>> Board(
		N, std::vector<int>(N)
	);

	for (auto& Row : Board)
	{
		for (auto& Num : Row)
		{
			std::cin >> Num;
		}
	}

	for (int k = 0; k < (1 << kLIMIT * 2); ++k)
	{
		std::vector<int> GeneratedRow = Generate(k);

		MaxNum = std::max(
			MaxNum, GetMaxNum(Board, GeneratedRow)
		);
	}
	std::cout << MaxNum;
	return 0;
}