#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10

// MAP은 문제에서 주어진 원본.
int MAP[MAX][MAX];

int MAP2[MAX][MAX];
bool Visited[MAX][MAX] = {false};
int dxy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M, cnt = 3, ans = 0;

void Insert()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)        
            cin >> MAP[i][j];        
}

void BFS()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            MAP2[i][j] = MAP[i][j];
    

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            // 바이러스 발견시 BFS 시작.
            if (MAP2[i][j] == 2)
            {
                queue<pair<int, int>> q;

                q.push({i, j});
                Visited[i][j] = true;

                while (!q.empty())
                {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();

                    for (int next = 0; next < 4; next++)
                    {
                        int NextY = curY + dxy[next][0];
                        int NextX = curX + dxy[next][1];

                        if (!Visited[NextY][NextX] && MAP2[NextY][NextX] == 0)
                        {
                            q.push({NextY, NextX});
                            Visited[NextY][NextX] = true;
                            MAP2[NextY][NextX] = 2;
                        }
                    }
                }
            }
        }
    }

    memset(Visited, false, sizeof(Visited));

    int temp = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP2[i][j] == 0)
                temp++;
        }
    }

    if (temp > ans)
        ans = temp;
}

// 만들 수 있는 모든 벽의 가능성.
void search()
{
    if (cnt == 0)
        return BFS();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP[i][j] == 0)
            {
                cnt--;
                MAP[i][j] = 1;
                search();
                cnt++;
                MAP[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    memset(MAP, -1, sizeof(MAP));
    memset(MAP2, -1, sizeof(MAP2));

    Insert();
    search();
    cout << ans << '\n';

    return 0;
}