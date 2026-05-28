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
using vvvll = vector<vvll>;
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
struct edge
{
  ll to;
  char c;
};
int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<edge>> t(n, vector<edge>(0));
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    char c;
    cin >> c;
    t[a].pb({b, c});
    t[b].pb({a, c});
  }
  queue<pll> que;
  map<pll, ll> dp;
  que.push({0, n - 1});
  dp[{0, n - 1}] = 0;
  ll ans = INF;
  while (que.size())
  {
    auto [x, y] = que.front();
    que.pop();
    ll v = dp[{x, y}];
    if (x == y)
    {
      chmin(ans, v * 2);
    }
    for (auto [nx, c] : t[x])
    {
      for (auto [ny, cy] : t[y])
      {
        if (nx == y && ny == x)
        {
          chmin(ans, v * 2 + 1);
        }
        if (c == cy && !dp.count({nx, ny}))
        {
          dp[{nx, ny}] = v + 1;
          que.push({nx, ny});
        }
      }
    }
  }
  if (ans == INF)
    ans = -1;
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
