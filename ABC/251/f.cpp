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
int main()
{
  ll n, m;
  cin >> n >> m;
  vvll t(n, vll(0));
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].pb(v);
    t[v].pb(u);
  }
  vector<pll> p1(0);
  vector<pll> p2(0);
  vll ch1(n, -1);
  vll ch2(n, -1);
  ch1[0] = 1;
  ch2[0] = 1;
  auto dfs = [&](auto dfs, ll now) -> void
  {
    for (auto nx : t[now])
    {
      if (ch1[nx] == -1)
      {
        ch1[nx] = 1;
        p1.pb({now + 1, nx + 1});
        dfs(dfs, nx);
      }
    }
  };
  dfs(dfs, 0);
  queue<ll> que;
  que.push(0);
  while (que.size())
  {
    ll now = que.front();
    que.pop();
    for (auto nx : t[now])
    {
      if (ch2[nx] == -1)
      {
        ch2[nx] = 1;
        p2.pb({now + 1, nx + 1});
        que.push(nx);
      }
    }
  }
  rep(i, n - 1)
  {
    cout << p1[i].F << " " << p1[i].S << endl;
  }
  rep(i, n - 1)
  {
    cout << p2[i].F << " " << p2[i].S << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
