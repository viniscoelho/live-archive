#include <cmath>
#include <iostream>

using namespace std;

long bigmod(long b, long p, long m)
{
    if (p == 0)
        return 1;
    else if (p % 2 == 0) {
        long x = bigmod(b, p / 2, m);
        return (x * x) % m;
    } else
        return ((b % m) * bigmod(b, p - 1, m)) % m;
}

int main()
{
    ios::sync_with_stdio(false);
    long b, p, m;
    while (cin >> b >> p >> m)
        cout << bigmod(b, p, m) << "\n";
    return 0;
}
