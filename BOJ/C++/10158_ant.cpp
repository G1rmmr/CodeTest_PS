#include <iostream>

std::pair<int, int> GetPos(
    const int& w, const int& h,
    const int& p, const int& q,
    const int& t)
{
    std::pair<int, int> Pos;

    Pos.first = (p + t) / w % 2 ? w - (p + t) % w : (p + t) % w;
    Pos.second = (q + t) / h % 2 ? h - (q + t) % h : (q + t) % h;

    return Pos;
}

int main()
{
    int w = 0, h = 0, p = 0, q = 0;
    std::cin >> w >> h >> p >> q;

    int t;
    std::cin >> t;

    std::pair<int, int> AntPos
        = GetPos(w, h, p, q, t);

    std::cout << AntPos.first << ' ' << AntPos.second;
    return 0;
}