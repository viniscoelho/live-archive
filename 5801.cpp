#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long int64;
typedef unsigned long long uint64;

int main()
{
    ios::sync_with_stdio(false);
    int tt, a, m, n;
    cin >> tt;
    while (tt--) {
        cin >> a >> m >> n;
        cout << a << " " << 1 + (m - n) * n << "\n";
    }
    return 0;
}
