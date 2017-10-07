#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, k = 1;
	while ( cin >> n && n >= 0 )
	{
		double sumA = 0.0, sumB = 0.0, sumM = 0.0;
		double x[n], y[n], m[n];
		for ( int i = 0; i < n; i++ )
		{
			cin >> x[i] >> y[i] >> m[i];
		}
		for ( int i = 0; i < n; i++ )
		{
			sumA += m[i]*x[i];
			sumB += m[i]*y[i];
			sumM += m[i];
		}
		cout << "Case " << k++ << ": ";
		cout << fixed << setprecision(2) << sumA/sumM << " "<< sumB/sumM << endl;
		
	}
	return 0;
}