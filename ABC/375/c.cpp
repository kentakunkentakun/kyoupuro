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
  vvc a(n, vc(n));
  rep(i, n)
  {
    rep(j, n)
    {
      cin >> a[i][j];
    }
  }
  auto nx = [](ll x, ll y, ll ma, ll mi) -> pll
  {
    if (x == mi && y + 1 <= ma)
    {
      y++;
    }
    else if (y == ma && x + 1 <= ma)
    {
      x++;
    }
    else if (x == ma && y - 1 >= mi)
    {
      y--;
    }
    else
    {
      x--;
    }
    return {x, y};
  };
  vvc ans(n, vc(n, '-'));
  rep(i, n / 2)
  {
    ll x = i, y = i;
    ll sx = i, sy = i;
    ll m = n - 1 - i;
    if (i % 4 == 0)
    {
      sx = m, sy = i;
    }
    else if (i % 4 == 1)
    {
      sx = m, sy = m;
    }
    else if (i % 4 == 2)
    {
      sx = i, sy = m;
    }
    while (ans[x][y] == '-')
    {
      ans[x][y] = a[sx][sy];
      pll r = nx(x, y, m, i);
      x = r.F, y = r.S;
      r = nx(sx, sy, m, i);
      sx = r.F, sy = r.S;
    }
  }
  rep(i, n)
  {
    rep(j, n)
    {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
