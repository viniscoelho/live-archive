#include <tr1/unordered_map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace tr1;

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	int tt, a, m, n;
	cin >> tt;
	while ( tt-- ){
		cin >> a >> m >> n;
		cout << a << " " << 1 + (m-n)*n << "\n";
	}
	return 0;
}
