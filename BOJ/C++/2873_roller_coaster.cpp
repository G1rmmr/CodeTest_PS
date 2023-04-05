#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

std::string GetMax(const int& R, const int& C,
	const std::vector<std::vector<int>>& Field)
{
	std::string Buffer = "";

	if (R % 2)
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C - 1; ++j)
			{
				if (i % 2)
				{
					Buffer += 'L';
				}
				else
				{
					Buffer += 'R';
				}
			}

			if (i != R - 1)
			{
				Buffer += 'D';
			}
		}
	}
	else if (C % 2)
	{
		for (int i = 0; i < C; ++i)
		{
			for (int j = 0; j < R - 1; ++j)
			{
				if (i % 2)
				{
					Buffer += 'U';
				}
				else
				{
					Buffer += 'D';
				}
			}

			if (i != C - 1)
			{
				Buffer += 'R';
			}
		}
	}
	else
	{
		std::pair<int, int> MinJoy;
		int Min = 1000;

		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if ((i + j) % 2 && Min > Field[i][j])
				{
					Min = Field[i][j];
					MinJoy = std::make_pair(i, j);
				}
			}
		}

		int Row = MinJoy.first % 2 ? MinJoy.first - 1 : MinJoy.first;

		for (int i = 0; i < Row; ++i)
		{
			for (int j = 0; j < C - 1; ++j)
			{
				if (i % 2)
				{
					Buffer += 'L';
				}
				else
				{
					Buffer += 'R';
				}
			}
			Buffer += 'D';
		}

		int Col = MinJoy.second;

		for (int i = 0; i < Col; ++i)
		{
			if (i % 2)
			{
				Buffer += "UR";
			}
			else
			{
				Buffer += "DR";
			}
		}

		for (int i = Col; i < C - 1; ++i)
		{
			if (i % 2)
			{
				Buffer += "RU";
			}
			else
			{
				Buffer += "RD";
			}
		}

		Row = R - (MinJoy.first + (MinJoy.first % 2 ? 1 : 2));

		for (int i = 0; i < Row; ++i)
		{
			Buffer += 'D';

			for (int j = 0; j < C - 1; ++j)
			{
				if (i % 2)
				{
					Buffer += 'R';
				}
				else
				{
					Buffer += 'L';
				}
			}
		}
	}
	return Buffer;
}

int main()
{
	int R = 0, C = 0;
	scanf("%d %d", &R, &C);

	std::vector<std::vector<int>> Field(
		R, std::vector<int>(C));

	for (auto& Row : Field)
	{
		for (auto& Joy : Row)
		{
			scanf("%d", &Joy);
		}
	}

	std::cout << GetMax(R, C, Field);
	return 0;
}