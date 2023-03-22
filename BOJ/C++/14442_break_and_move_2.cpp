#include <iostream>
#include <array>
#include <queue>
#include <string>

const short kMAX = 1001;

const std::array<int, 4> gDy = {-1, 0, 0, 1};
const std::array<int, 4> gDx = {0, -1, 1, 0};

std::array<std::array<std::array<bool, 10>, kMAX>, kMAX> gVisited;
std::array<std::string, kMAX> gGraph;

int BFS(const int& N, const int& M, const int& K)
{
    bool bFlag = false;

    std::queue<std::pair<
        std::pair<int, int>, 
        std::pair<int, int>>> BFSQueue;

    BFSQueue.push(
        std::make_pair(
            std::make_pair(0, 0),
            std::make_pair(0, 1)));

    gVisited[0][0][0] = true;

    while(!BFSQueue.empty())
	{
        std::pair<std::pair<int, int>, std::pair<int, int>>
            Now = BFSQueue.front();

        BFSQueue.pop();

        int Y = Now.first.first, X = Now.first.second;
        int Wall = Now.second.first, Count = Now.second.second;

        if(Y == N - 1 && X == M - 1)
        {
            return Count;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextY = Y + gDy[i], NextX = X + gDx[i];

            if((NextY >= 0 && NextY < N)
                && (NextX >= 0 && NextX < M)
                && !gVisited[NextY][NextX][Wall])
			{
                if (gGraph[NextY][NextX] == '1' && Wall < K)
				{
                    BFSQueue.push(std::make_pair(
                        std::make_pair(NextY, NextX),
                        std::make_pair(Wall + 1, Count + 1)));

                    gVisited[NextY][NextX][Wall + 1] = true;
                }
                else if (gGraph[NextY][NextX] == '0')
				{
                    BFSQueue.push(std::make_pair(
                        std::make_pair(NextY, NextX),
                        std::make_pair(Wall, Count + 1)));

                    gVisited[NextY][NextX][Wall] = true;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int N = 0, M = 0, K = 0;
    std::cin >> N >> M >> K;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> gGraph[i];
    } 

    std::cout << BFS(N, M, K);
    return 0;
}