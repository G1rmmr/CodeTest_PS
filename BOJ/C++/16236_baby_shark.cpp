#include <iostream>
#include <array>
#include <queue>

struct Shark
{
    short Y;
    short X;
    short Size;
    short NumFish;
};

const short kMAX = 20;

const std::array<short, 4> gDy = {1, -1, 0, 0};
const std::array<short, 4> gDx = {0, 0, -1, 1};

std::array<std::array<short, kMAX>, kMAX> gMap, gDist;

bool BFS(const short& N, Shark& Baby, short& Time)
{
    for (auto& DistRow : gDist)
    {
        std::fill(
            DistRow.begin(), DistRow.end(), -1);
    }

    gDist[Baby.Y][Baby.X] = 0;

    std::queue<std::pair<short, short>> BFSQueue;
    BFSQueue.push(std::make_pair(Baby.Y, Baby.X));

    while (!BFSQueue.empty())
    {
        short Y = BFSQueue.front().first;
        short X = BFSQueue.front().second;
        BFSQueue.pop();

        if (gMap[Y][X] != 9 && gMap[Y][X] != 0
            && gMap[Y][X] < Baby.Size)
        {
            continue;
        }

        for (short i = 0; i < 4; ++i)
        {
            short NextY = Y + gDy[i], NextX = X + gDx[i];
            
            if (NextY >= 0 && NextY < N
                && NextX >= 0 && NextX < N
                && gDist[NextY][NextX] == -1
                && gMap[NextY][NextX] <= Baby.Size)
            {
                gDist[NextY][NextX] = gDist[Y][X] + 1;

                BFSQueue.push(std::make_pair(
                    NextY, NextX));
            }
        }
    }

    short MinY = 5 * kMAX, MinX = 5 * kMAX;
    short MinDist = kMAX * kMAX + 1;

    for (short i = N - 1; i >= 0; i--)
    {
        for (short j = N - 1; j >= 0; j--)
        {
            if (gMap[i][j] != 0 && gMap[i][j] != 9
                && gMap[i][j] < Baby.Size
                && gDist[i][j] != -1 && gDist[i][j] <= MinDist)
            {
                MinDist = gDist[i][j];
                MinY = i, MinX = j;
            }
        }
    }

    if (MinDist == (kMAX * kMAX + 1))
    {
        return false;
    }
    else
    {
        gMap[Baby.Y][Baby.X] = 0;
        Baby.Y = MinY, Baby.X = MinX, Baby.NumFish++;

        if (Baby.NumFish == Baby.Size)
        {
            Baby.NumFish = 0, Baby.Size++;
        }
        gMap[MinY][MinX] = 9;
        Time += gDist[MinY][MinX];

        return true;
    }
}

int main()
{
    short N = 0;
    std::cin >> N;

    Shark Baby;

    for (short i = 0; i < N; ++i)
    {
        for (short j = 0; j < N; ++j)
        {
            std::cin >> gMap[i][j];

            if (gMap[i][j] == 9)
            {
                Baby.Y = i;
                Baby.X = j;
                Baby.Size = 2;
                Baby.NumFish = 0;
            }
        }
    }
    short Time = 0;
    while (BFS(N, Baby, Time));

    std::cout << Time;
    return 0;
}