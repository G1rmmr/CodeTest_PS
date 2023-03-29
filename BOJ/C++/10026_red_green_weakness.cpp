#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <array>
#include <queue>

const short kMAX = 101;

const std::array<short, 4> gDy = {-1, 0, 1, 0};
const std::array<short, 4> gDx = {0, -1, 0, 1};

std::array<std::array<char, kMAX>, kMAX> gPaint;
std::array<std::array<bool, kMAX>, kMAX> gVisited;

short BFS(const short& N, const bool& bIsWeakness)
{
    for (auto& Row : gVisited)
    {
        std::fill(Row.begin(), Row.end(), false);
    }

    std::queue<std::pair<short, short>> BFSQueue;
    short AreaCount = 0;

    for (short i = 1; i <= N; ++i)
    {
        for (short j = 1; j <= N; ++j)
        {
            if (!gVisited[i][j])
            {
                if (gPaint[i][j] == 'R' && bIsWeakness)
                {
                    gPaint[i][j] = 'G';
                }

                char Color = gPaint[i][j];
                BFSQueue.push(std::make_pair(i, j));

                gVisited[i][j] = true;
                AreaCount++;

                while (!BFSQueue.empty())
                {
                    std::pair<short, short> Now = BFSQueue.front();
                    BFSQueue.pop();

                    for (short i = 0; i < 4; ++i)
                    {
                        short NextY = Now.first + gDy[i];
                        short NextX = Now.second + gDx[i];

                        if (gPaint[NextY][NextX] == 'R' && bIsWeakness)
                        {
                            gPaint[NextY][NextX] = 'G';
                        }

                        if ((NextY > 0 && NextY <= N)
                            && (NextX > 0 && NextX <= N)
                            && !gVisited[NextY][NextX]
                            && Color == gPaint[NextY][NextX])
                        {
                            BFSQueue.push(std::make_pair(NextY, NextX));
                            gVisited[NextY][NextX] = true;
                        }
                    }
                }
            }
        }
    }
    return AreaCount;
}

int main()
{
    short N = 0;
    scanf("%hd", &N);

    for (short i = 1; i <= N; ++i)
    {
        std::cin.ignore();
        for (short j = 1; j <= N; ++j)
        {
            scanf("%1c", &gPaint[i][j]);
        }
    }

    short NumWhoNot = BFS(N, false);
    short NumWhoWeak = BFS(N, true);

    printf("%hd %hd", NumWhoNot, NumWhoWeak);
    return 0;
}