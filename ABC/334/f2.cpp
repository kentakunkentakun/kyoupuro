#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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

double mapping(double f, double a)
{
  return f + a;
}
double composition(double f, double g)
{
  return f + g;
}
double id()
{
  return 0;
}

int main()
{
  ll n, k;
  cin >> n >> k;
  double sx, sy;
  cin >> sx >> sy;
  vector<double> x(n), y(n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }
  lazy_segtree<double, op, e, double, mapping, composition, id> seg(k);
  ll nowx = sx;
  ll nowy = sy;
  ll it = k - 1;
  double d = sqrt(abs(nowx - x[0]) * abs(nowx - x[0]) + abs(nowy - y[0]) * abs(nowy - y[0]));
  seg.set(it, d);
  nowx = x[0];
  nowy = y[0];
  rep(i, n)
  {
    if (i == 0)
      continue;
    double d = sqrt(abs(nowx - x[i]) * abs(nowx - x[i]) + abs(nowy - y[i]) * abs(nowy - y[i]));
    double m = seg.all_prod();
    // to s
    m += sqrt(abs(nowx - sx) * abs(nowx - sx) + abs(nowy - sy) * abs(nowy - sy));
    // to next
    m += sqrt(abs(x[i] - sx) * abs(x[i] - sx) + abs(y[i] - sy) * abs(y[i] - sy));
    seg.apply(0, k, d);
    it++;
    it %= k;
    seg.set(it, m);
    nowx = x[i];
    nowy = y[i];
  }
  double m = seg.all_prod();
  cout << fixed << setprecision(10);

  cout << sqrt(abs(x[n - 1] - sx) * abs(x[n - 1] - sx) + abs(y[n - 1] - sy) * abs(y[n - 1] - sy)) + m << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
