#include <iostream>
#include <algorithm>
#include <vector>

void DFS(
    const std::vector<short>& W,
    int TempEnergy, int& MaxEnergy)
{
    if(W.size() == 3)
    {
        TempEnergy += W[0] * W[2];
        MaxEnergy = std::max(MaxEnergy, TempEnergy);
        return;
    }

    for (short i = 0; i < W.size() - 2; ++i)
    {
        std::vector<short> EnergySeg = W;
        EnergySeg.erase(EnergySeg.begin() + i + 1);

        DFS(EnergySeg, TempEnergy + W[i] * W[i + 2], MaxEnergy);
    }
}

int main()
{
    short N = 0;
    std::cin >> N;

    std::vector<short> W(N);

    for(auto& Energy : W)
    {
        std::cin >> Energy;
    }

    int MaxEnergy = 0;

    DFS(W, 0, MaxEnergy);

    std::cout << MaxEnergy;
    return 0;
}