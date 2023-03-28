#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <string>

const short kMAX = 100;

const std::array<short, 4> gDy = {-1, 0, 1, 0};
const std::array<short, 4> gDx = {0, -1, 0, 1};

std::array<std::string, kMAX> gMap;
std::array<std::array<std::array<short, 5>, kMAX>, kMAX> gVisited;

struct Laser
{
    std::pair<short, short> Pos;
    short Direction;
    short NumMir;
};

struct Compare
{
    bool operator()(const Laser& L1, const Laser& L2)
    {
        return L1.NumMir > L2.NumMir;
    }
};

short BFS(const short& W, const short& H,
    const std::pair<short, short>& Start,
    const std::pair<short, short>& End)
{
    std::priority_queue<Laser,
        std::vector<Laser>,
        Compare> BFSPriQueue;

    gVisited[Start.first][Start.second][4] = 0;
    BFSPriQueue.push({Start, 4, 0});

    while (!BFSPriQueue.empty())
    {
        auto NowPoint = BFSPriQueue.top();
        BFSPriQueue.pop();

        if (gMap[NowPoint.Pos.first][NowPoint.Pos.second] == 'C'
            && NowPoint.Direction != 4
            && (NowPoint.Pos.first != Start.first
                || NowPoint.Pos.second != Start.second))
        {
            return NowPoint.NumMir;
        }

        for (short i = 0; i < 4; ++i)
        {
            short NextY = NowPoint.Pos.first + gDy[i];
            short NextX = NowPoint.Pos.second + gDx[i];
            
            if ((NextY < 0 || NextY >= H)
                || (NextX < 0 || NextX >= W)
                || gMap[NextY][NextX] == '*')
            {
                continue;
            }

            if (NowPoint.Direction != 4
                && NowPoint.Direction % 2 != i % 2
                && NowPoint.NumMir + 1 < gVisited[NextY][NextX][i])
            {
                BFSPriQueue.push({
                    std::make_pair(NextY, NextX),
                    i, NowPoint.NumMir + 1});

                gVisited[NextY][NextX][i] = NowPoint.NumMir + 1;
            }
            else if (NowPoint.Direction == 4
                || (NowPoint.Direction % 2 == i % 2
                && NowPoint.NumMir < gVisited[NextY][NextX][i]))
            {
                BFSPriQueue.push({
                    std::make_pair(NextY, NextX),
                    i, NowPoint.NumMir});

                gVisited[NextY][NextX][i] = NowPoint.NumMir;
            }
        }
    }
}

int main()
{
    short W = 0, H = 0;
    std::cin >> W >> H;

    std::pair<short, short> Start, End;
    bool bFlag = true;

    for (short i = 0; i < H; ++i)
    {
        std::cin >> gMap[i];

        for (short j = 0; j < W; ++j)
        {
            if (gMap[i][j] == 'C')
            {
                if (bFlag)
                {
                    Start = std::make_pair(i, j);
                    bFlag = false;
                }
                else
                {
                    End = std::make_pair(i, j);
                }
            }
            std::fill(gVisited[i][j].begin(),
                gVisited[i][j].end(),
                kMAX * kMAX + 1);
        }
    }
    std::cout << BFS(W, H, Start, End);
    return 0;
}