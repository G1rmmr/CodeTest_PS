#include <iostream>

typedef long long LL;

bool IsPrime(const LL& n)
{
	if (n < 2)
	{
		return false;
	}

	for (LL i = 2; i * i <= n; ++i)
	{
		if (!(n % i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
    LL T;
	std::cin >> T;

	while (T--)
	{
		LL n = 0;
		std::cin >> n;

		while (true)
		{
			if (IsPrime(n))
			{
				std::cout << n << '\n';
				break;
			}
			n++;
		}
	}
    return 0;
}