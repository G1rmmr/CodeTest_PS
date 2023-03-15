#include <iostream>
#include <array>
#include <string>

static std::array<std::array<short, 10>, 10> gBoard;
static std::array<std::array<bool, 10>, 10> gVisited;

bool Check(const short& Y, const short& X)
{	
	for (short i = 0; i < 9; ++i)
	{
		if (gBoard[Y][X] == gBoard[Y][i] && i != X)
		{
			return false;
		}
		else if(gBoard[Y][X] == gBoard[i][X] && i != Y)
		{
			return false;
		}
	}
		
	for (short i = (Y / 3) * 3; i < (Y / 3) * 3 + 3; ++i)
	{
		for (short j = (X / 3) * 3; j < (X / 3) * 3 + 3; ++j)
		{
			if(i == Y && j == X)
			{
				continue;
			}
			else if (gBoard[i][j] == gBoard[Y][X])
			{
				return false;
			}
		}
	}
	return true;
}

void SimulateSudominoku(bool& bExistZero)
{
	if (!bExistZero)
	{
		return;
	}
	
	short Y = -1, X = -1;

	for (short i = 0; i < 9; ++i)
	{
		for (short j = 0; j < 9; ++j)
		{
			if (!gBoard[i][j])
			{
				Y = i, X = j;
				break;
			}
		}
		
		if (!(Y < 0))
		{
			break;
		}
	}

	if (Y < 0)
	{
		bExistZero = false;

		for (short i = 0; i < 9; ++i)
		{
			for (short j = 0; j < 9; ++j)
			{
				std::cout << gBoard[i][j];
			}
			std::cout << '\n';
		}

		return;
	}

	for (short i = 1; i < 9; ++i)
	{
		for (short j = i + 1; j < 10; ++j)
		{
			if (!gVisited[i][j])
			{
				gVisited[i][j] = true;
				gVisited[j][i] = true;

				if (X < 8 && !gBoard[Y][X + 1])
				{
					gBoard[Y][X] = i;
					gBoard[Y][X + 1] = j;

					if (Check(Y, X) && Check(Y, X + 1))
					{
						SimulateSudoku(bExistZero);
					}

					gBoard[Y][X] = 0;
					gBoard[Y][X + 1] = 0;
				}

				if (X < 8 && !gBoard[Y][X + 1])
				{
					gBoard[Y][X] = j;
					gBoard[Y][X + 1] = i;

					if (Check(Y, X) && Check(Y, X + 1))
					{
						SimulateSudoku(bExistZero);
					}

					gBoard[Y][X] = 0;
					gBoard[Y][X + 1] = 0;
				}

				if (Y < 8 && !gBoard[Y + 1][X])
				{
					gBoard[Y][X] = i;
					gBoard[Y + 1][X] = j;

					if (Check(Y, X) && Check(Y + 1, X))
					{
						SimulateSudoku(bExistZero);
					}

					gBoard[Y][X] = 0;
					gBoard[Y + 1][X] = 0;
				}

				if (Y < 8 && !gBoard[Y + 1][X])
				{
					gBoard[Y][X] = j;
					gBoard[Y + 1][X] = i;

					if (Check(Y, X) && Check(Y + 1, X))
					{
						SimulateSudoku(bExistZero);
					}

					gBoard[Y][X] = 0;
					gBoard[Y + 1][X] = 0;
				}

				gVisited[i][j] = false;
				gVisited[j][i] = false;
			}
		}
	}
}

int main()
{
	short N = 0, PuzzleNum = 1;

	while (true)
	{
		std::cin >> N;

		if (!N)
		{
			break;
		}

		short U = 0, V = 0;
		std::string LU, LV;

		for (short i = 0; i < N; ++i)
		{
			std::cin.ignore();
			std::cin >> U >> LU >> V >> LV;

			gBoard[LU[0] - 'A'][LU[1] - '1'] = U;
			gBoard[LV[0] - 'A'][LV[1] - '1'] = V;

			gVisited[U][V] = true;
			gVisited[V][U] = true;
		}

		std::string NumPos;

		for (short i = 1; i <= 9; ++i)
		{
			std::cin.ignore();
			std::cin >> NumPos;

			gBoard[NumPos[0] - 'A'][NumPos[1] - '1'] = i;
		}

		std::cout << "Puzzle " << PuzzleNum++ << "\n";

		bool bExistZero = true;
		SimulateSudominoku(bExistZero);

		for (short i = 0; i < 10; ++i)
		{
			std::fill(gBoard[i].begin(), gBoard[i].end(), 0);
			std::fill(gVisited[i].begin(), gVisited[i].end(), false);
		}
	}
	return 0;
}