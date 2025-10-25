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
<<<<<<< Updated upstream
const ll MOD = 998244353LL;
=======
const ll MOD = 1000000007LL;
>>>>>>> Stashed changes
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
struct edge
{
  ll to, k, c;
};
int main()
{
  ll n, m, x, y;
  cin >> n >> m >> x >> y;
  x--;
  y--;
  vector<vector<edge>> t(n, vector<edge>(0));
  rep(i, m)
  {
    ll a, b, tt, k;
    cin >> a >> b >> tt >> k;
    a--;
    b--;
    t[a].pb({b, k, tt});
    t[b].pb({a, k, tt});
  }
  vll dist(n, INF);
  dist[x] = 0;
  PQR(pll)
  que;
  que.push(pll(0, x));
  while (que.size())
  {
    auto [c, now] = que.top();
    que.pop();
    if (dist[now] < c)
      continue;
    for (auto [to, k, cost] : t[now])
    {
      ll next_time = (c + k - 1) / k * k + cost;
      if (chmin(dist[to], next_time))
      {
        que.push({dist[to], to});
      }
    }
  }
  if (dist[y] == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << dist[y] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
<<<<<<< Updated upstream
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
=======

>>>>>>> Stashed changes
__builtin_popcount(i)*/
