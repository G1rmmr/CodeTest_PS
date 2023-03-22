#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <string>

const short kMAX = 1001;

const std::array<short, 4> gDy = {-1, 0, 0, 1};
const std::array<short, 4> gDx = {0, -1, 1, 0};

std::array<std::string, kMAX> gGraph;
std::array<std::array<int, kMAX>, kMAX> gVisited;
std::array<int, (kMAX * kMAX)> gCounts;

void BFS(const short& N, const short& M,
    const short& Y, const short& X,
    int& Count)
{
    std::queue<std::pair<short, short>> BFSQueue;
    BFSQueue.push(std::make_pair(Y, X));
    gVisited[Y][X] = Count;

    int TempCount = 0;

    while (!BFSQueue.empty())
    {
        std::pair<short, short> Now = BFSQueue.front();
        BFSQueue.pop();
        TempCount++;

        for (short i = 0; i < 4; ++i)
        {
            short NextY = Now.first + gDy[i];
            short NextX = Now.second + gDx[i];

            if ((NextY >= 0 && NextY < N)
                && (NextX >= 0 && NextX < M)
                && gGraph[NextY][NextX] == '0'
                && !gVisited[NextY][NextX])
            {
                gVisited[NextY][NextX] = Count;

                BFSQueue.push(std::make_pair(
                    NextY, NextX)
                );
            }
        }
    }
    gCounts[Count++] = TempCount;
}

int main()
{
    short N = 0, M = 0;
    std::cin >> N >> M;

    for (short i = 0; i < N; ++i)
    {
        std::cin >> gGraph[i];
    }
    
    int Count = 1;

    for (short i = 0; i < N; ++i)
    {
        for (short j = 0; j < M; ++j)
        {
            if (gGraph[i][j] == '0' && gVisited[i][j] == 0)
            {
                BFS(N, M, i, j, Count);
            }
        }
    }

    std::vector<std::vector<int>> Field(kMAX, std::vector<int>(kMAX));

    for (short i = 0; i < N; ++i)
    {
        for (short j = 0; j < M; ++j)
        {
            if (gGraph[i][j] != '0')
            {
                int TempCount = 1;
                std::vector<int> Checker;

                for (short k = 0; k < 4; ++k)
                {
                    short NextY = i + gDy[k], NextX = j + gDx[k];
                    bool bFlag = false;

                    if ((NextY >= 0 && NextY < N)
                        && (NextX >= 0 && NextX < M))
                    {
                        for (const auto& Check : Checker)
                        {
                            if (Check == gVisited[NextY][NextX])
                            {
                                bFlag = true;
                                break;
                            }
                        }
                        Checker.emplace_back(gVisited[NextY][NextX]);

                        if (bFlag)
                        {
                            continue;
                        }
                        TempCount += gCounts[gVisited[NextY][NextX]];
                    }
                    Field[i][j] = TempCount;
                }
            }
        }
    }
    
    for (short i = 0; i < N; ++i)
    {
        for (short j = 0; j < M; ++j)
        {
            std::cout << Field[i][j] % 10;
        }
        std::cout << '\n';
    }
    return 0;
}