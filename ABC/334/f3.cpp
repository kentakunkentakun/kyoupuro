#include <bits/stdc++.h>
#include <atcoder/segtree>
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
double op(double a, double b)
{
  return min(a, b);
}
double e()
{
  return (double)(1LL << 60);
}
int main()
{
  ll n, k;
  cin >> n >> k;
  double sx, sy;
  cin >> sx >> sy;
  double ans = 0.0;
  vector<double> x(n), y(n);
  double nowx = sx;
  double nowy = sy;
  rep(i, n)
  {
    cin >> x[i] >> y[i];
    ans += hypot(nowx - x[i], nowy - y[i]);
    nowx = x[i];
    nowy = y[i];
  }
  ans += hypot(nowx - sx, nowy - sy);
  segtree<double, op, e> seg(n);
  seg.set(0, 0.0);
  vector<double> d(n - 1);
  rep(i, n - 1)
  {
    d[i] = hypot(x[i] - sx, y[i] - sy) + hypot(x[i + 1] - sx, y[i + 1] - sy) - hypot(x[i] - x[i + 1], y[i] - y[i + 1]);
  }
  rep(i, n)
  {
    if (i == 0)
      continue;
    ll mi = max(0LL, i - k);
    double res = seg.prod(mi, i);
    seg.set(i, res + d[i - 1]);
  }
  cout << fixed << setprecision(10);

  ll mi = max(0LL, n - k);
  cout << seg.prod(mi, n) + ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
