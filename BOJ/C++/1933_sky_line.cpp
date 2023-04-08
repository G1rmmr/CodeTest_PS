#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

struct Building
{
    int X;
    int H;
    bool bFlag;
};

void SwipeBuildings(std::vector<Building>& Buildings)
{
    std::sort(Buildings.begin(), Buildings.end(),
        [](const Building& _left, const Building& _right)
    {
        if (_left.X != _right.X)
        {
            return _left.X < _right.X;
        }
        else if (_left.bFlag != _right.bFlag)
        {
            return _right.bFlag ? true : false;
        }
        return _left.bFlag ? _left.H < _right.H : _left.H > _right.H;
    });

    std::multiset<int> Infos;

    for (auto& Info : Buildings)
    {
        if (Info.bFlag)
        {
            auto FinalIter = *Infos.rbegin();
            auto FindIter = Infos.find(Info.H);

            if (FindIter != Infos.end())
            {
                Infos.erase(FindIter);
            }

            if (Infos.empty())
            {
                printf("%d 0 ", Info.X);
            }
            else if (FinalIter != *Infos.rbegin())
            {
                printf("%d %d ", Info.X, *Infos.rbegin());
            }
        }
        else
        {
            if (Infos.empty() || *Infos.rbegin() < Info.H)
            {
                printf("%d %d ", Info.X, Info.H);
            }
            Infos.insert(Info.H);
        }
    }
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<Building> Buildings;

    while (N--)
    {
        int L = 0, H = 0, R = 0;
        scanf("%d %d %d", &L, &H, &R);

        Buildings.push_back({L, H, false});
        Buildings.push_back({R, H, true});
    }

    SwipeBuildings(Buildings);
    return 0;
}