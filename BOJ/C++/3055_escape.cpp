#include <iostream>
#include <array>
#include <queue>
#include <string>

const short kMAX = 50;

const std::array<short, 4> gDy = {-1, 0, 0, 1};
const std::array<short, 4> gDx = {0, -1, 1, 0};

std::array<std::array<char, kMAX>, kMAX> gMap;
std::queue<std::pair<short, short>> gHogQueue, gWaterQueue;

void BFS(const short& R, const short& C,
    const std::pair<short, short>& CavePos)
{
    int Time = 0;

    while (!gHogQueue.empty())
    {
        size_t WaterSize = gWaterQueue.size();
        for (size_t i = 0; i < WaterSize; ++i)
        {
            short NowWaterY = gWaterQueue.front().first;
            short NowWaterX = gWaterQueue.front().second;
            gWaterQueue.pop();

            for (short i = 0; i < 4; ++i)
            {
                short NextWaterY = NowWaterY + gDy[i];
                short NextWaterX = NowWaterX + gDx[i];

                if ((NextWaterY >= 0 && NextWaterY < R) 
                    && (NextWaterX >= 0 && NextWaterX < C)
                    && gMap[NextWaterY][NextWaterX] == '.')
                {
                    gWaterQueue.push(std::make_pair(NextWaterY, NextWaterX));
                    gMap[NextWaterY][NextWaterX] = '*';
                }
            }
        }

        size_t HogSize = gHogQueue.size();
        for (size_t i = 0; i < HogSize; ++i)
        {
            short NowHogY = gHogQueue.front().first;
            short NowHogX = gHogQueue.front().second;
            gHogQueue.pop();

            for (short i = 0; i < 4; ++i)
            {
                short NextHogY = NowHogY + gDy[i];
                short NextHogX = NowHogX + gDx[i];

                if ((NextHogY == CavePos.first)
                    && (NextHogX == CavePos.second))
                {
                    std::cout << ++Time;
                    return;
                }

                if ((NextHogY >= 0 && NextHogY < R) 
                    && (NextHogX >= 0 && NextHogX < C)
                    && gMap[NextHogY][NextHogX] == '.')
                {
                    gHogQueue.push(std::make_pair(NextHogY, NextHogX));
                    gMap[NextHogY][NextHogX] = 'S';
                }
            }
        }
        Time++;
    }
    std::cout << "KAKTUS";
    return;
}

int main()
{
    short R = 0, C = 0;
    std::cin >> R >> C;

    std::pair<short, short> CavePos;
    std::string MapRow;

    for (short i = 0; i < R; ++i)
    {
        std::cin >> MapRow;

        for (short j = 0; j < C; ++j)
        {
            gMap[i][j] = MapRow[j];

            if (gMap[i][j] == '*')
            {
                gWaterQueue.push(std::make_pair(i, j));
            }
            else if (gMap[i][j] == 'S')
            {
                gHogQueue.push(std::make_pair(i, j));
            }
            else if (gMap[i][j] == 'D')
            {
                CavePos.first = i, CavePos.second = j;
            }
        }
    }
    BFS(R, C, CavePos);
    return 0;
}