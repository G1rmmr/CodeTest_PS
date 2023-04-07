#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

typedef long long ll;

std::pair<ll, ll> GetPos(const ll& y, const ll& x,
    const ll& Size, const std::string& Num, const ll& idx)
{
    if (Size == 1)
    {
        return std::make_pair(y, x);
    }
    else
    {
        switch (Num[idx])
        {
        case '1':
            return GetPos(y, x + Size / 2,
                Size / 2, Num, idx + 1);

        case '2':
            return GetPos(y, x,
                Size / 2, Num, idx + 1);
        
        case '3':
            return GetPos(y + Size / 2, x,
                Size / 2, Num, idx + 1);

        case '4':
            return GetPos(y + Size / 2, x + Size / 2,
                Size / 2, Num, idx + 1);

        default:
            break;
        }
    }
    return std::make_pair(0, 0);
}

std::string GetNum(const ll& y, const ll& x,
    const std::pair<ll, ll>& Pos,const ll& Size)
{
    if (Size == 1)
    {
        return "";
    }

    if (Pos.first < y + Size / 2)
    {
        if (Pos.second >= x + Size / 2)
        {
            return '1' + GetNum(y, x + Size / 2, Pos, Size / 2);
        }
        else
        {
            return '2' + GetNum(y, x, Pos, Size / 2);
        }
    }
    else
    {
        if (Pos.second < x + Size / 2)
        {
            return '3' + GetNum(y + Size / 2, x, Pos, Size / 2);
        }
        else
        {
            return '4' + GetNum(y + Size / 2, x + Size / 2, Pos, Size / 2);
        }
    }
}

int main()
{
    ll d = 0;
    scanf("%lld", &d);

    std::string Num;
    std::cin >> Num;

    ll Size = ((1LL) << d);

    auto Pos = GetPos(0, 0, Size, Num, 0);

    ll x = 0, y = 0;
    scanf("%lld %lld", &x, &y);

    Pos.first -= y;
    Pos.second += x;

    if ((Pos.first >= 0 && Pos.first < Size)
        && (Pos.second >= 0 && Pos.second < Size))
    {
        std::cout << GetNum(0, 0, Pos, Size);
    }
    else
    {
        std::cout << -1;
    }
    return 0;
}