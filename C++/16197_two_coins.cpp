#include <iostream>
#include <algorithm>
#include <vector>

void DFS(
    const short& N, const short& X,
    const std::vector<short>& W,
    int& MaxEnegy)
{
    if(N == 2)
    {
        return;
    }

    int TempEnergy = 0;

    for(int i = 1; i < N; ++i)
    {
        if(X == i)
        {
            continue;
        }
        else if(TempEnergy < W[i - 1] * W[i + 1])
        {
            if(i - 1 == X && i > 1)
            {
                TempEnergy = W[i - 2] * W[i + 1];
            }
            else if(i + 1 == X && i < N - 1)
            {
                TempEnergy = W[i - 1] * W[i + 2];
            }
            else
            {
                TempEnergy = W[i - 1] * W[i + 1];
            }
            DFS(N - 1, i, W, TempEnergy);
        }
        MaxEnegy += TempEnergy;
    }
}

int main()
{
    short N = 0;
    std::cin >> N;

    std::vector<short> W(N + 1);

    for(short i = 1; i <= N; ++i)
    {
        std::cin >> W[i];
    }

    short X = 0;
    int MaxEnergy = 0;

    DFS(N, X, W, MaxEnergy);

    std::cout << MaxEnergy;
    return 0;
}