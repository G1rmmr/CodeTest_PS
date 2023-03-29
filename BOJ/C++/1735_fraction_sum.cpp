#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

typedef long long LL;

inline LL GetGCD(const LL& Num1, const LL& Num2)
{
    return Num2 ? GetGCD(Num2, Num1 % Num2) : Num1;
}

inline LL GetLCM(const LL& Num1, const LL& Num2)
{
    return (Num1 * Num2) / GetGCD(Num1, Num2);
}

int main()
{
    LL A = 0L, B = 0L;
    scanf("%lld %lld", &A, &B);

    LL C = 0L, D = 0L;
    scanf("%lld %lld", &C, &D);

    LL LCM = GetLCM(B, D);

    std::pair<LL, LL> Fraction
        = std::make_pair(A * (LCM / B) + C * (LCM / D), LCM);

    LL GCD = GetGCD(Fraction.first, Fraction.second);

    printf("%lld %lld", Fraction.first / GCD, Fraction.second / GCD);
    return 0;
}