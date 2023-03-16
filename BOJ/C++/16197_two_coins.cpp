#include <iostream>
#include <array>
#include <string>

struct Coin
{
    short Y, X;
};

static std::array<std::string, 21> gBoard;

static const std::array<short, 4> gDx = {-1, 1, 0, 0};
static const std::array<short, 4> gDy = {0, 0, -1, 1};

void DFS(
    const short& N, const short& M,
    const Coin& Coin1, const Coin& Coin2,
    const short& CmdCount, short& MinCmd)
{
    if(CmdCount == 10)
    {
        return;
    }

    for(int i = 0; i < 4; ++i)
    {
        Coin NextPos1 = {
            static_cast<short>(Coin1.Y + gDy[i]),
            static_cast<short>(Coin1.X + gDx[i])
        };

        Coin NextPos2 = {
            static_cast<short>(Coin2.Y + gDy[i]),
            static_cast<short>(Coin2.X + gDx[i])
        };

        if((NextPos1.Y >= 0 && NextPos1.Y < N
        && NextPos1.X >= 0 && NextPos1.X < M)
        && (NextPos2.Y >= 0 && NextPos2.Y < N
        && NextPos2.X >= 0 && NextPos2.X < M))
        {
            if(gBoard[NextPos1.Y][NextPos1.X] == '#'
            && gBoard[NextPos2.Y][NextPos2.X] == '#')
            {
                continue;
            }
            else if(gBoard[NextPos1.Y][NextPos1.X] == '#')
            {
                NextPos1.Y = Coin1.Y;
                NextPos1.X = Coin1.X;
            }
            else if(gBoard[NextPos2.Y][NextPos2.X] == '#')
            {
                NextPos2.Y = Coin2.Y;
                NextPos2.X = Coin2.X;
            }

            DFS(N, M, NextPos1, NextPos2, CmdCount + 1, MinCmd);
        }
        else if((NextPos1.Y < 0 || NextPos1.Y >= N
        || NextPos1.X < 0 || NextPos1.X >= M)
        && (NextPos2.Y < 0 || NextPos2.Y >= N
        || NextPos2.X < 0 || NextPos2.X >= M))
        {
            continue;
        }
        else
        {
            if(MinCmd > CmdCount + 1)
            {
                MinCmd = CmdCount + 1;
            }
            return;
        }
    }
}

int main()
{
    short N = 0, M = 0;
    std::cin >> N >> M;

    bool bFlag = false;
    Coin Coin1 = {0, 0}, Coin2 = {0, 0};

    for(short i = 0; i < N; ++i)
    {
        std::cin >> gBoard[i];

        for(short j = 0; j < M; ++j)
        {
            if(gBoard[i][j] == 'o' && !bFlag)
            {
                Coin1.Y = i, Coin1.X = j;
                bFlag = true;
            }
            else if(gBoard[i][j] == 'o' && bFlag)
            {
                Coin2.Y = i, Coin2.X = j;
            }
        }
    }
    short MinCmd = 21;
    DFS(N, M, Coin1, Coin2, 0, MinCmd);

    std::cout << (MinCmd == 21 ? -1 : MinCmd);
    return 0;
}