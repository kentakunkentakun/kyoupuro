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
  ll n;
  cin >> n;
  vvll t(n, vll(0));
  vector<pll> path(n - 1);
  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
    path[i] = pll(a, b);
  }
  vll dist(n, INF);
  dist[0] = 0;
  queue<pll> que;
  que.push(pll(0, -1));
  while (que.size())
  {
    auto [now, par] = que.front();
    que.pop();
    for (auto p : t[now])
    {
      if (p != par)
      {
        dist[p] = dist[now] + 1;
        que.push(pll(p, now));
      }
    }
  }
  ll q;
  cin >> q;
  vll ans(n);
  rep(i, q)
  {
    ll t, e, x;
    cin >> t >> e >> x;
    e--;
    auto [a, b] = path[e];

    if (t == 1)
    {
      if (dist[a] > dist[b])
      {
        ans[a] += x;
      }
      else
      {
        ans[b] -= x;
        ans[0] += x;
      }
    }
    else
    {
      if (dist[a] > dist[b])
      {
        ans[0] += x;
        ans[a] -= x;
      }
      else
      {
        ans[b] += x;
      }
    }
  }
  que.push(pll(0, -1));
  while (que.size())
  {
    auto [now, par] = que.front();
    que.pop();
    for (auto p : t[now])
    {
      if (p != par)
      {
        ans[p] += ans[now];
        que.push(pll(p, now));
      }
    }
  }
  rep(i, n)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
