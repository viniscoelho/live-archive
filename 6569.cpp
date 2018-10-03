#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string a, b;
	int k = 1;
	while ( cin >> a >> b )
	{
		if ( a == "END" && b == "END" ) break;
		
		cout << "Case " << k++;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if ( a == b ) cout << ": same\n";
		else cout << ": different\n";
	}
	return 0;
}