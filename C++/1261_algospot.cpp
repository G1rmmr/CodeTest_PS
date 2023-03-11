#include <iostream>
#include <vector>
#include <deque>
#include <string>

static const short kMAX = 101;

static std::vector<std::string> gGraph(kMAX);

static std::vector<std::vector<short>> gDist(
    kMAX, std::vector<short>(kMAX)
);

static const std::vector<short> gX = {1, 0, -1, 0};
static const std::vector<short> gY = {0, 1, 0, -1};

short BFS(const short& n, const short& m) {
    gDist[0][0] = 0;

    std::deque<std::pair<short, short>> bfsQueue;
    bfsQueue.push_back(std::make_pair(0, 0));

    while (!bfsQueue.empty()) {
        auto nowDir = bfsQueue.front();
        bfsQueue.pop_front();

        for (short i = 0; i < 4; ++i) {
            short ny = nowDir.first + gY[i];
            short nx = nowDir.second + gX[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (gDist[ny][nx] != -1) {
                continue;
            }
            
            if (gGraph[ny][nx] == '0') {
                bfsQueue.push_front(std::make_pair(ny, nx));
                gDist[ny][nx] 
                    = gDist[nowDir.first][nowDir.second];
            } else if (gGraph[ny][nx] == '1') {
                bfsQueue.push_back(std::make_pair(ny, nx));
                gDist[ny][nx] 
                    = gDist[nowDir.first][nowDir.second] + 1;
            }
        }
    }
    return gDist[n - 1][m - 1];
}

int main() {
    short m, n;
    std::cin >> m >> n;

    for (short i = 0; i < n; ++i) {
        std::cin >> gGraph[i];
    }

    for (auto& distCol : gDist) {
        std::fill(distCol.begin(), distCol.end(), -1);
    }
    std::cout << BFS(n, m);
    return 0;
}