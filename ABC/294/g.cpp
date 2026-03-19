#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
struct edge
{
  ll it, from, to, cost;
};
ll op_sum(ll a, ll b)
{
  return a + b;
}
ll e_sum()
{
  return 0;
}

struct S_min
{
  ll it, d;
};
S_min op_min(S_min a, S_min b)
{
  if (a.d < b.d)
  {
    return a;
  }
  return b;
}
S_min e_min()
{
  return (S_min){-1, INF};
}
int main()
{
  ll n;
  cin >> n;
  vector<edge> e(n - 1);
  vector<vector<edge>> t(n, vector<edge>(0));
  vll in(n, -1);
  vll out(n, -1);
  vll in_path(n - 1, -1);
  vll out_path(n - 1, -1);
  vll path(2 * n);
  vector<S_min> depth(2 * n);
  rep(i, n - 1)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    e[i] = {i, u, v, w};
    t[u].pb({i, u, v, w});
    t[v].pb({i, v, u, w});
  }
  ll iter = 0;
  depth[0] = {0, 0};
  path[0] = 0;
  depth[2 * n - 1] = {0, 0};
  auto dfs = [&](auto dfs, ll now, ll par, ll w, ll i) -> void
  {
    in[now] = iter;
    if (now != 0)
    {
      depth[iter] = {now, depth[in[par]].d + 1};
      path[iter] = w;
      in_path[i] = iter;
    }
    iter++;
    for (auto [it, u, v, w] : t[now])
    {
      if (v != par)
        dfs(dfs, v, now, w, it);
    }
    out[now] = iter;
    if (now != 0)
    {
      depth[iter] = {par, depth[in[now]].d - 1};
      path[iter] = -1 * w;
      out_path[i] = iter;
    }
    iter++;
  };
  dfs(dfs, 0, -1, 0, 0);
  segtree<S_min, op_min, e_min> seg_min(depth);
  segtree<ll, op_sum, e_sum> seg_sum(path);
  ll q;
  cin >> q;
  vll ans(0);
  rep(i, q)
  {
    ll r;
    cin >> r;
    if (r == 1)
    {
      ll it, w;
      cin >> it >> w;
      it--;
      ll IN = in_path[it];
      ll OUT = out_path[it];
      seg_sum.set(IN, w);
      seg_sum.set(OUT, -1 * w);
    }
    else
    {
      ll u, v;
      cin >> u >> v;
      u--;
      v--;
      ll mi = min(in[u], in[v]);
      ll ma = max(in[u], in[v]);
      ll lca = seg_min.prod(mi, ma + 1).it;
      ll lca_sum = seg_sum.prod(0, in[lca] + 1);
      ll u_sum = seg_sum.prod(0, in[u] + 1);
      ll v_sum = seg_sum.prod(0, in[v] + 1);
      ans.pb(u_sum + v_sum - 2 * lca_sum);
    }
  }
  rep(i, ans.size())
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
