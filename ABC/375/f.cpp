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
const ll INF = 1LL << 61;
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
  ll n, m, q;
  cin >> n >> m >> q;
  vll a(m), b(m), c(m);
  rep(i, m)
  {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }
  set<ll> s;
  vector<pll> query(q);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll it;
      cin >> it;
      it--;
      query[i] = pll(it, -1);
      s.insert(it);
    }
    else
    {
      ll x, y;
      cin >> x >> y;
      x--;
      y--;
      query[i] = pll(x, y);
    }
  }
  vvll dist(n, vll(n, INF));
  rep(i, n)
  {
    dist[i][i] = 0;
  }
  rep(i, m)
  {
    if (!s.count(i))
    {
      dist[a[i]][b[i]] = c[i];
      dist[b[i]][a[i]] = c[i];
    }
  }
  rep(k, n)
  {
    rep(i, n)
    {
      rep(j, n)
      {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  vector<ll> ans(0);
  repR(i, q)
  {
    auto [x, y] = query[i];
    if (y != -1)
    {
      ans.pb(dist[x][y]);
    }
    else
    {
      if (chmin(dist[a[x]][b[x]], c[x]))
      {
        chmin(dist[b[x]][a[x]], c[x]);
        rep(i, n)
        {
          rep(j, n)
          {
            chmin(dist[i][j], dist[i][a[x]] + dist[b[x]][j] + c[x]);
            chmin(dist[i][j], dist[i][b[x]] + dist[a[x]][j] + c[x]);
          }
        }
      }
    }
  }
  repR(i, ans.size())
  {
    if (ans[i] == INF)
      cout << -1 << endl;
    else
      cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
