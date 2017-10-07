#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <cstdio>
#define MAX 2000
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef long long int64;

char num[1000010];

const int INF = 0x3f3f3f3f;

int64 m, n, fib[MAX];
char mine[110][110];

int main(){
	ios::sync_with_stdio(false);
    while ( cin >> m >> n && m + n ){
		for ( int i = 0; i < m; ++i )
			for ( int j = 0; j < n; ++j )
				cin >> mine[i][j];
		for ( int i = 0; i < m; ++i ){
			for ( int j = 0; j < n; ++j ){
				if ( mine[i][j] == '*' );
				else{
					if ( i+1 < m && mine[i+1][j] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( i+1 < m && j+1 < n && mine[i+1][j+1] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( j+1 < n && mine[i][j+1] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( i-1 >= 0 && j+1 < n && mine[i-1][j+1] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( i-1 >= 0 && mine[i-1][j] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( i-1 >= 0 && j-1 >= 0 && mine[i-1][j-1] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( j-1 >= 0 && mine[i][j-1] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
					if ( i+1 < m && j-1 >= 0 && mine[i+1][j-1] == '*' ){
						if ( mine[i][j] == '.' ) mine[i][j] = '1';
						else mine[i][j]++;
					}
				}
			}
		}
		for ( int i = 0; i < m; ++i ){
			for ( int j = 0; j < n; ++j ){
				if ( mine[i][j] == '.' ) cout << "0";
				else cout << mine[i][j];
			}
			cout << "\n";
		}
    }
       
    return 0;
}
