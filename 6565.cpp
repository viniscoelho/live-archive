#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
	ios::sync_with_stdio(false);
	int64 n, caso = 1;
	while ( cin >> n )
	{
		int64 k = (int64)round(sqrt(2*n));
        int64 ans = (k-1) * pow(2, k) - ( ((k*(k+1))/2) - n ) * pow(2, k-1) + 1;
        cout << "Case " << caso++ << ": ";
        cout << ((n == 0) ? 0 : ans) << endl;
	}
	
	return 0;
}
