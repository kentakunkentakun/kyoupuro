#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (ll)(b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0LL; i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout << (x) << "\n"
#define PQ(x) priority_queue<x>
#define PQR(x) priority_queue<x, vector<x>, greater<x>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n")
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n")
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template <class T>
constexpr void printArray(const vector<T> &vec, char split = ' ')
{
  rep(i, vec.size())
  {
    cout << vec[i];
    cout << (i == (int)vec.size() - 1 ? '\n' : split);
  }
}
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
template <typename T = int>
struct SCC
{
  using Edge = T;
  using SGraph = vector<vector<Edge>>;

  // input
  SGraph G, rG;

  // result
  vector<vector<T>> scc; // 各成分に含まれる頂点
  vector<int> cmp;       // 各頂点が属する成分番号（-1初期化）
  SGraph dag;            // SCCを縮約したDAG

  // constructor
  SCC(T n) : G(n), rG(n) {}

  // add edge
  void addedge(T u, T v)
  {
    G[u].push_back(v);
    rG[v].push_back(u);
  }

  // decomposition
  vector<char> seen;
  vector<T> vs, rvs;

  void dfs(T v)
  {
    seen[v] = true;
    for (auto e : G[v])
      if (!seen[e])
        dfs(e);
    vs.push_back(v);
  }

  void rdfs(T v, int k)
  {
    seen[v] = true;
    cmp[v] = k;
    for (auto e : rG[v])
      if (!seen[e])
        rdfs(e, k);
    rvs.push_back(v);
  }

  // reconstruct DAG
  set<pair<int, int>> newEdges;
  void reconstruct()
  {
    int N = (int)G.size();
    int dV = (int)scc.size();
    dag.assign(dV, vector<Edge>());
    newEdges.clear();
    for (int i = 0; i < N; ++i)
    {
      int u = cmp[i];
      for (auto e : G[i])
      {
        int v = cmp[e];
        if (u == v)
          continue;
        if (!newEdges.count({u, v}))
        {
          dag[u].push_back(v);
          newEdges.insert({u, v});
        }
      }
    }
  }
  void topo_reorder()
  {
    int dV = (int)dag.size();
    if (dV == 0)
      return;

    // 1) indeg 計算（dag は成分DAG）
    vector<int> indeg(dV, 0);
    for (int u = 0; u < dV; ++u)
      for (auto v : dag[u])
        ++indeg[v];

    // 2) Kahn 法で一旦 source→sink のトポ順を作る
    queue<int> q;
    for (int i = 0; i < dV; ++i)
      if (indeg[i] == 0)
        q.push(i);

    vector<int> ord;
    ord.reserve(dV);
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      ord.push_back(u);
      for (auto v : dag[u])
        if (--indeg[v] == 0)
          q.push(v);
    }
    if ((int)ord.size() != dV)
      return; // 念のため

    // ★ ここが肝：あなたの出力が「逆」に見えるとのことなので
    //     並びを反転して sink→source 側に切り替える
    //     （= あなたの期待する“順”になるように揃える）
    reverse(ord.begin(), ord.end());

    // 3) 旧→新 ID
    vector<int> newid(dV, -1);
    for (int i = 0; i < dV; ++i)
      newid[ord[i]] = i;

    // 4) scc 並べ替え
    vector<vector<T>> scc_new(dV);
    for (int old = 0; old < dV; ++old)
      scc_new[newid[old]] = move(scc[old]);
    scc.swap(scc_new);

    // 5) cmp 更新（添字で安全に）
    for (int newId = 0; newId < dV; ++newId)
      for (auto v : scc[newId])
        cmp[v] = newId;

    // 6) dag 並べ替え
    SGraph dag_new(dV);
    for (int old_u = 0; old_u < dV; ++old_u)
    {
      int u = newid[old_u];
      for (auto old_v : dag[old_u])
      {
        int v = newid[old_v];
        if (u != v)
          dag_new[u].push_back(v);
      }
    }
    dag.swap(dag_new);
  }

  // main
  void solve()
  {
    int N = (int)G.size();
    seen.assign(N, 0);
    vs.clear();
    for (int v = 0; v < N; ++v)
      if (!seen[v])
        dfs(v);

    int k = 0;
    scc.clear();
    cmp.assign(N, -1);
    seen.assign(N, 0);
    for (int i = N - 1; i >= 0; --i)
    {
      if (!seen[vs[i]])
      {
        rvs.clear();
        rdfs(vs[i], k++);
        scc.push_back(rvs);
      }
    }
    reconstruct();
    topo_reorder();
  }
};

int main()
{
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep(i, n) cin >> a[i];
  SCC<ll> scc(n);
  vvll t(n, vll(0));
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    if (a[u] >= a[v])
    {
      scc.addedge(u, v);
      t[v].pb(u);
    }
    if (a[v] >= a[u])
    {
      scc.addedge(v, u);
      t[u].pb(v);
    }
  }
  scc.solve();
  ll N = scc.scc.size();
  vvll t2(n, vll(0));
  ll start;
  ll end;
  vll nx(n, 0);
  for (int i = 0; i < N; i++)
  {
    for (auto p : scc.scc[i])
    {
      if (p == 0)
        start = i;
      if (p == n - 1)
        end = i;
      nx[p] = i;
    }
  }
  for (int i = 0; i < N; i++)
  {
    set<ll> s;
    for (auto p : scc.scc[i])
    {
      rep(j, t[p].size())
      {
        ll g = nx[t[p][j]];
        s.insert(g);
      }
    }
    for (auto z : s)
    {
      if (z != i)
        t2[i].pb(z);
    }
  }
  vb used(N);
  vll dp(N, 0);
  auto dfs = [&](auto dfs, int i) -> ll
  {
    // cout << "i " << i << endl;
    if (used[i])
      return dp[i];
    if (i == end)
    {
      used[i] = true;
      return dp[i] = 1;
    }
    ll res = 0;
    for (auto p : t2[i])
    {
      dfs(dfs, p);
      if (dp[p] != 0)
      {
        res = max(dp[p] + 1, res);
      }
    }
    used[i] = true;
    return dp[i] = res;
  };

  dfs(dfs, start);
  cout << dp[start] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
