#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

ll GetMax(std::vector<ll>& Cards)
{
    std::sort(Cards.begin(), Cards.end());
    ll MaxCard = Cards[0], TempMax = 1L, Count = 1L;

    for (std::size_t i = 1; i < Cards.size(); ++i)
    {
        Count = Cards[i] == Cards[i - 1] ? Count + 1 : 1;

        if (TempMax < Count)
        {
            TempMax = Count;
            MaxCard = Cards[i];
        }
    }
    return MaxCard;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<ll> Cards(N);

    for (auto& Card : Cards)
    {
        scanf("%lld", &Card);
    }

    printf("%lld", GetMax(Cards));
    return 0;
}