#include <bits/stdc++.h>
#define INF 0x7fffffffffffff

using namespace std;

int n, k, e;
long long dp[1001][11][51][4];
int step[1001];
int ass[] = {0, 4, 8, 11};

long long solve(int pos, int K, int E, int last)
{
	if ( K < 0 || E < 0 )
		return INF;
	if ( pos == n )
		return 0LL;
	if ( dp[pos][K][E][last] != -1 ) return dp[pos][K][E][last];
	long long &ans = dp[pos][K][E][last];
	ans = INF;
	
	if ( K == 0 && last > E )
		last = 0;
	for ( int i = 0 ; i < 4 ; i++ )
		ans = min(ans, solve(pos+1, K - (i != last), E-i, i) + max(0, step[pos] - ass[i]));

	return ans;
}

int main()
{
	int t;
	cin >> t;
	for ( int tc = 1 ; tc <= t ; tc++ )
	{
		cin >> n >> k >> e;
		
		for ( int i = 0 ; i < n ; i++ )
			cin >> step[i];

		for ( int i = 0; i <= n ; i++ )
			for ( int j = 0 ; j <= k ; j++ )
				for ( int l = 0 ; l <= e ; l++ )
					for ( int m = 0 ; m < 4 ; m++ )
						dp[i][j][l][m] = -1LL;
		
		cout << "Case #" << tc << ": " << solve(0, k, e, 0) << "\n";
	}
    return 0;
}
