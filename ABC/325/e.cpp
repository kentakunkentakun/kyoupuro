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
struct edge
{
  ll to, cost;
};
int main()
{
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  vvll d(n, vll(n));
  vector<vector<edge>> t(n, vector<edge>(0));

  rep(i, n)
  {
    rep(j, n)
    {
      cin >> d[i][j];
      t[i].pb({j, d[i][j]});
    }
  }
  vll car(n, INF);
  vll train(n, INF);
  car[0] = 0;
  train[n - 1] = 0;
  PQR(pll)
  que;
  que.push({0, 0});
  while (que.size())
  {
    auto [d, now] = que.top();
    que.pop();
    if (car[now] < d)
      continue;
    for (auto [nx, cost] : t[now])
    {
      if (chmin(car[nx], d + cost * a))
      {
        que.push({car[nx], nx});
      }
    }
  }
  que.push({0, n - 1});
  while (que.size())
  {
    auto [d, now] = que.top();
    que.pop();
    if (train[now] < d)
      continue;
    for (auto [nx, cost] : t[now])
    {
      if (chmin(train[nx], d + cost * b + c))
      {
        que.push({train[nx], nx});
      }
    }
  }
  ll ans = INF;
  rep(i, n)
  {
    chmin(ans, car[i] + train[i]);
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
