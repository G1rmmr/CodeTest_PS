#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <queue>
#include <unordered_set>
#include <string>

typedef long long LL;

const LL kMAX = 1e9;

std::unordered_set<LL> gVisited;

std::string BFS(const LL& s, const LL& t)
{
    std::queue<std::pair<LL, std::string>> BFSQueue;
    BFSQueue.push(std::make_pair(s, ""));

    while (!BFSQueue.empty())
    {
        LL NowNum = BFSQueue.front().first;
        std::string NowOp = BFSQueue.front().second;
        BFSQueue.pop();

        if (NowNum == t)
        {
            return (NowOp != "" ? NowOp : "0");
        }

        if (NowNum * NowNum <= kMAX)
        {
            if (gVisited.find(NowNum * NowNum) == gVisited.end())
            {
                gVisited.insert(NowNum * NowNum);
                BFSQueue.push(std::make_pair(NowNum * NowNum, NowOp + '*'));
            }
        }

        if (NowNum + NowNum <= kMAX)
        {
            if (gVisited.find(NowNum + NowNum) == gVisited.end())
            {
                gVisited.insert(NowNum + NowNum);
                BFSQueue.push(std::make_pair(NowNum + NowNum, NowOp + '+'));
            }
        }

        if (NowNum - NowNum > 0)
        {
            if (gVisited.find(NowNum - NowNum) == gVisited.end())
            {
                gVisited.insert(NowNum - NowNum);
                BFSQueue.push(std::make_pair(NowNum - NowNum, NowOp + '-'));
            }
        }

        if (NowNum)
        {
            if (gVisited.find(NowNum / NowNum) == gVisited.end())
            {
                gVisited.insert(NowNum / NowNum);
                BFSQueue.push(std::make_pair(NowNum / NowNum, NowOp + '/'));
            }
        }
    }
    return "-1";
}

int main()
{
    LL s = 0L, t = 0L;
    scanf("%lld %lld", &s, &t);

    std::cout << BFS(s, t);
    return 0;
}