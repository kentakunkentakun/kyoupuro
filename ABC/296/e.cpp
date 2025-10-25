#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n; i >= 0; i--)
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
  }
};

int main()
{
  ll n;
  cin >> n;
  SCC<ll> scc(n);
  vvll t(n);
  rep(i, n)
  {
    ll a;
    cin >> a;
    a--;
    t[i].pb(a);
    scc.addedge(i, a);
  }
  scc.solve();
  ll ans = 0;

  for (auto list : scc.scc)
  {
    if (list.size() > 1)
      ans += list.size();
    else
    {
      ll v = list[0];
      if (t[v][0] == v)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
