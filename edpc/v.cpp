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
// const ll MOD = 1e9+7LL;
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
int main()
{
  ll n, m;
  cin >> n >> m;
  vvll t(n, vll(0));
  rep(i, n - 1)
  {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    t[x].pb(y);
    t[y].pb(x);
  }
  vll d(n);
  auto dfs = [&](auto dfs, ll now, ll par) -> ll
  {
    ll res = 1;
    for (auto nx : t[now])
    {
      if (nx == par)
        continue;
      res *= (dfs(dfs, nx, now) + 1);
      res %= m;
    }
    return d[now] = res;
  };
  dfs(dfs, 0, -1);
  vll ans(n);
  auto dfs2 = [&](auto dfs2, ll now, ll par, ll s) -> void
  {
    ans[now] = ((s + 1) * (d[now])) % m;
    vll lft(t[now].size());
    vll rht(t[now].size());
    rep(i, t[now].size())
    {
      if (t[now][i] == par)
      {
        if (i > 0)
        {
          lft[i] = lft[i - 1];
        }
        else
        {
          lft[i] = 1;
        }
        continue;
      }
      lft[i] = (d[t[now][i]] + 1);
      if (i > 0)
      {
        lft[i] *= lft[i - 1];
        lft[i] %= m;
      }
    }
    repR(i, t[now].size())
    {
      if (t[now][i] == par)
      {
        if (i < t[now].size()-1)
        {
          rht[i] = rht[i + 1];
        }
        else
        {
          rht[i] = 1;
        }
        continue;
      }
      rht[i] = (d[t[now][i]] + 1);
      if (i < t[now].size() - 1)
      {
        rht[i] *= rht[i + 1];
        rht[i] %= m;
      }
    }
    rep(i, t[now].size())
    {
      if (t[now][i] == par)
        continue;
      ll v = (s + 1);
      if (i > 0)
      {
        v *= lft[i - 1];
        v %= m;
      }
      if (i < t[now].size() - 1)
      {
        v *= rht[i + 1];
        v %= m;
      }
      dfs2(dfs2, t[now][i], now, v);
    }
  };
  dfs2(dfs2, 0, -1, 0);
  rep(i, n)
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
