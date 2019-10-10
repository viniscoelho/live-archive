#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, N) for (int i = 0; i < N; ++i)
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;

struct tri {
    int atual, custo;
    tri(int atual = 0, int custo = 0)
        : atual(atual)
        , custo(custo)
    {
    }
};

int n, m;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<tri> vtri;
typedef vector<vtri> vvtri;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> ii;

int visitado[100000], dist[1000000], res[1001][1001], p[10000], visited[10000], check = 1, s, t, f;
vvtri grafo;

void initialize()
{
    REP(i, n)
    {
        FOR(j, i, n)
        res[i][j] = res[j][i] = 0;
        res[i][i] = 0;
    }
}

void augment(int v, int minEdge)
{
    if (v == s) {
        f = minEdge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void dfs(int u)
{
    if (u == t)
        return;
    REP(i, grafo[u].size())
    {
        tri atual = grafo[u][i];
        if (visited[atual.atual] != check && res[u][atual.atual] > 0) {
            visited[atual.atual] = check;
            p[atual.atual] = u;
            dfs(atual.atual);
        }
    }
}

int djsktra(int de, int para)
{
    REP(i, n)
    {
        dist[i] = INF;
        visitado[i] = false;
    }
    tri atual;
    ii at;
    priority_queue<ii> pq;
    pq.push(mp(INF, de));
    dist[de] = 0;
    int ans = 0;
    while (!pq.empty()) {
        at = pq.top();
        pq.pop();
        if (at.second == para)
            ans = max(ans, at.first);
        if (visitado[at.second])
            continue;
        visitado[at.second] = true;
        int custo = at.first;
        int v = at.second;
        REP(i, grafo[v].size())
        {
            atual = grafo[v][i];
            pq.push(mp(min(custo, atual.custo), atual.atual));
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int tt, de, para, atoa, custo;
    cin >> tt;
    while (tt--) {
        cin >> atoa >> n >> m >> s >> t;
        grafo.resize(n + 10);
        initialize();
        REP(i, m)
        {
            cin >> de >> para >> custo;
            grafo[de].pb(tri(para, custo));
            grafo[para].pb(tri(de, custo));
            res[de][para] = custo;
        }
        int ans, mf = 0;
        ans = djsktra(s, t);
        while (true) {
            f = 0;
            REP(i, t + 1)
            p[i] = -1;
            visited[s] = check;
            dfs(s);
            check++;
            augment(t, INF);
            if (!f)
                break;
            mf += f;
        }
        cout << atoa << " " << setprecision(3) << fixed << (double)mf / (double)ans << "\n";
        grafo.clear();
        check++;
    }
    return 0;
}
