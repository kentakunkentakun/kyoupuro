#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
  ll h, w, m;
  cin >> h >> w >> m;
  vll x(m), y(m);
  rep(i, m)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vll y_min(w, INF);
  vll x_min(h, INF);
  vvll t(h, vll(0));
  rep(i, m)
  {
    t[x[i]].pb(y[i]);
  }
  rep(i, m)
  {
    chmin(y_min[y[i]], x[i]);
    chmin(x_min[x[i]], y[i]);
  }
  ll ans = h * min(x_min[0], w);
  rep(i, min(x_min[0], w))
  {
    if (y_min[i] != INF)
    {
      ans -= h - y_min[i];
    }
  }
  fenwick_tree<ll> bit(w);
  for (int i = min(w, x_min[0]); i < w; i++)
  {
    bit.add(i, 1);
  }
  rep(i, min(h, y_min[0]))
  {
    ll ma = min(x_min[i], w);
    ans += bit.sum(0, ma);
    for (auto p : t[i])
    {
      if (bit.sum(p, p + 1) == 0)
        bit.add(p, 1);
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
