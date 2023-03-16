#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

static const short kMAX = 300;

static const std::vector<short> gX = {1, -1, 0, 0};
static const std::vector<short> gY = {0, 0, -1, 1};

static std::vector<std::vector<short>> gGraph(
    100, std::vector<short>(100));

static std::vector<std::vector<bool>> gVisited(
    100, std::vector<bool>(100));

void DFS (
    const short& n, 
    const short& y, 
    const short& x, 
    const short& count) {
    gVisited[y][x] = true;
    gGraph[y][x] = count;

    for (short i = 0; i < 4; ++i) {
        short nY = y + gY[i], nX = x + gX[i];

        if (nY >= 0 && nY < n && nX >= 0 && nX < n) {
            if (gGraph[nY][nX] && !gVisited[nY][nX]) {
                DFS(n, nY, nX, count);
            }
        }
    }
}

short BFS(const short& n, const short& count) {
    std::queue<std::pair<short, short>> bfsQueue;

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < n; ++j) {
            if (gGraph[i][j] == count) {
                gVisited[i][j] = true;
                bfsQueue.push(std::make_pair(i, j));
            }
        }
    }

    short bridgeDistance = 0;

    while (!bfsQueue.empty()) {
        short nowQueueSize = bfsQueue.size();

        for (short i = 0; i < nowQueueSize; ++i) {
            short y = bfsQueue.front().first;
            short x = bfsQueue.front().second;

            bfsQueue.pop();

            for (short i = 0; i < 4; ++i) {
                short nY = y + gY[i], nX = x + gX[i];

                if (nY >= 0 && nY < n && nX >= 0 && nX < n) {
                    if (gGraph[nY][nX] && gGraph[nY][nX] != count) {
                        return bridgeDistance;
                    } else if (!gGraph[nY][nX] && !gVisited[nY][nX]) {
                        gVisited[nY][nX] = true;
                        bfsQueue.push(std::make_pair(nY, nX));
                    }
                }
            }
        }
        bridgeDistance++;
    }
}

short GetDistance(const short& n) {
    short count = 1;

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < n; ++j) {
            if (gGraph[i][j] && !gVisited[i][j]) {
                DFS(n, i, j, count++);
            }
        }
    }

    short bridgeDistance = kMAX;

    for (short i = 1; i < count; ++i) {
        for (auto& graphCol : gVisited) {
            std::fill(graphCol.begin(), graphCol.end(), false);
        }
        bridgeDistance = std::min(bridgeDistance, BFS(n, i));
    }
    return bridgeDistance;
}

int main() {
    short n;
    std::cin >> n;

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < n; ++j) {
            std::cin >> gGraph[i][j];
        }
    }
    
    std::cout << GetDistance(n);
    return 0;
}