#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tr1/unordered_map>
#include <utility>
#include <vector>

using namespace std;
using namespace tr1;

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
