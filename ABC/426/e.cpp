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
  cout << fixed << setprecision(20);
  ll t;
  cin >> t;

  rep(T, t)
  {
    double tsx, tsy, tgx, tgy, asx, asy, agx, agy;
    cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;
    auto p = [&](double now, double sx, double sy, double gx, double gy) -> pair<double, double>
    {
      double L = sqrt((sx - gx) * (sx - gx) + (sy - gy) * (sy - gy));
      double r = min(1.0, now / L);
      double x = sx + (gx - sx) * r;
      double y = sy + (gy - sy) * r;
      return pll(x, y);
    };
    auto f = [&](double now) -> double
    {
      auto [sx, sy] = p(now, tsx, tsy, tgx, tgy);
      auto [gx, gy] = p(now, asx, asy, agx, agy);
      return sqrt((sx - gx) * (sx - gx) + (sy - gy) * (sy - gy));
    };
    double low = 0;
    double high = 1e12;
    int cnt = 500;
    while (cnt--)
    {
      double c1 = (low * 2 + high) / 3;
      double c2 = (low + high * 2) / 3;
      if (f(c1) > f(c2))
        low = c1;
      else
        high = c2;
    }
    cout << f(low) << endl;
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
