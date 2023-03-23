#include <iostream>
#include <array>
#include <queue>

const short kMAX = 8;

const std::array<short, kMAX + 1> gDy = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const std::array<short, kMAX + 1> gDx = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

std::array<std::array<char, kMAX>, kMAX> gGraph;
std::array<std::array<std::array<bool, kMAX + 1>, kMAX>, kMAX> gVisited;

bool BFS()
{
    std::queue<std::pair<std::pair<short, short>, short>> BFSQueue;
    BFSQueue.push(std::make_pair(std::make_pair(7, 0), 0));
    gVisited[7][0][0] = true;

    while (!BFSQueue.empty())
    {
        short Y = BFSQueue.front().first.first;
        short X = BFSQueue.front().first.second;
        short Time = BFSQueue.front().second;
        BFSQueue.pop();

        if (!Y)
        {
            return true;
        }

        for (short i = 0; i < kMAX + 1; ++i)
        {
            short NextY = Y + gDy[i], NextX = X + gDx[i];
            short NextTime = Time + 1;

            if (NextTime >= kMAX)
            {
                return true;
            }

            if (NextY < 0 || NextY >= kMAX 
                || NextX < 0 || NextX >= kMAX)
            {
                continue;
            }

            if (NextY >= Time
                && gGraph[NextY - Time][NextX] == '#')
            {
                continue;
            }

            if (NextY >= Time + 1
                && gGraph[NextY - Time - 1][NextX] == '#')
            {
                continue;
            }

            if (!gVisited[NextY][NextX][NextTime])
            {
                gVisited[NextY][NextX][NextTime] = true;

                BFSQueue.push(std::make_pair(
                    std::make_pair(NextY, NextX),
                    NextTime));
            }
        }
    }
    return false;
}

int main()
{
    for (auto& Row : gGraph)
    {
        for (auto& Element : Row)
        {
            std::cin >> Element;
        }
    }
    std::cout << BFS();
    return 0;
}