#include <iostream>
#include <array>
#include <queue>
#include <string>

const short kMAX = 1001;

const std::array<int, 4> gDy = {-1, 0, 0, 1};
const std::array<int, 4> gDx = {0, -1, 1, 0};

std::array<std::array<std::array<bool, 10>, kMAX>, kMAX> gVisited;
std::array<std::string, kMAX> gGraph;

struct Info
{
    int Y;
    int X;
    int Wall;
    int Count;
    bool bIsDay;
};

int BFS(const int& N, const int& M, const int& K)
{
    bool bFlag = false;
    std::queue<Info> BFSQueue;

    BFSQueue.push({0, 0, 0, 1, true});
    gVisited[0][0][0] = true;

    bool bIsDay = true;

    while(!BFSQueue.empty())
	{
        Info Now = BFSQueue.front();
        BFSQueue.pop();

        if(Now.Y == N - 1 && Now.X == M - 1)
        {
            return Now.Count;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextY = Now.Y + gDy[i], NextX = Now.X + gDx[i];

            if(NextY >= 0 && NextY < N && NextX >= 0 && NextX < M)
			{
                if ((gGraph[NextY][NextX] == '1' && Now.Wall < K)
                    && !gVisited[NextY][NextX][Now.Wall + 1])
				{
                    if (Now.bIsDay)
                    {
                        gVisited[NextY][NextX][Now.Wall + 1] = true;
                        BFSQueue.push(
                            {NextY, NextX, Now.Wall + 1, Now.Count + 1, false}
                        );
                    }
                    else
                    {
                        BFSQueue.push(
                            {Now.Y, Now.X, Now.Wall, Now.Count + 1, true}
                        );
                    }
                }
                else if (gGraph[NextY][NextX] == '0'
                    && !gVisited[NextY][NextX][Now.Wall])
				{
                    gVisited[NextY][NextX][Now.Wall] = true;

                    BFSQueue.push({NextY, NextX, Now.Wall, Now.Count + 1,
                        (Now.bIsDay ? false : true)}
                    );
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