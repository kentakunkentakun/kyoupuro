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
const ll MOD = 998244353LL;
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
int main()
{
  ll n, q;
  cin >> n >> q;
  vll x(n);
  rep(i, n) cin >> x[i];
  vvll t(n, vll(0));
  vvll d(n, vll(0));
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  auto dfs = [&](auto dfs, int i, int par) -> vll
  {
    if (t[i].size() == 1 && t[i][0] == par)
    {
      d[i].pb(x[i]);
      vll tmp = {x[i]};
      return tmp;
    }
    vll tmp(0);
    tmp.pb(x[i]);
    for (auto nx : t[i])
    {
      if (nx != par)
      {
        vll res = dfs(dfs, nx, i);
        rep(j, res.size()) tmp.pb(res[j]);
      }
    }
    sort(rall(tmp));
    ll v = tmp.size();
    vll res(0);
    rep(j, min(20LL, v))
    {
      res.pb(tmp[j]);
      d[i].pb(tmp[j]);
    }
    return res;
  };
  dfs(dfs, 0, -1);
  rep(i, q)
  {
    ll v, k;
    cin >> v >> k;
    v--;
    k--;
    cout << d[v][k] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
