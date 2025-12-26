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
struct S
{
  double v;
  bool empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  else if (b.empty)
  {
    return a;
  }
  return {min(a.v, b.v), false};
}
S e()
{
  return {0, true};
}
S mapping(double f, S a)
{
  if (a.empty)
  {
    return a;
  }
  return {f + a.v, false};
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
  cout << fixed << setprecision(10);

  ll n, k;
  cin >> n >> k;
  double sx, sy;
  cin >> sx >> sy;
  vector<double> x(n), y(n);
  rep(i, n)
  {
    cin >> x[i] >> y[i];
  }
  vector<S> ini(k);
  rep(i, k)
  {
    ini[i] = {0.0, true};
  }
  ini[k - 1] = {sqrt(abs(sx - x[0]) * abs(sx - x[0]) + abs(sy - y[0]) * abs(sy - y[0])), false};
  lazy_segtree<S, op, e, double, mapping, composition, id> seg(ini);
  ll s = k - 1;
  rep(i, n - 1)
  {
    s++;
    if (s == k)
      s = 0;
    double a = sqrt(abs(sx - x[i]) * abs(sx - x[i]) + abs(sy - y[i]) * abs(sy - y[i]));
    double b = sqrt(abs(x[i + 1] - x[i]) * abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]) * abs(y[i + 1] - y[i]));
    double c = sqrt(abs(sx - x[i + 1]) * abs(sx - x[i + 1]) + abs(sy - y[i + 1]) * abs(sy - y[i + 1]));
    auto [mi, _] = seg.all_prod();
    seg.apply(0, k, b);
    seg.set(s, {mi + c + a, false});
  }
  auto [mi, _] = seg.all_prod();
  cout << mi + sqrt(abs(sx - x[n - 1]) * abs(sx - x[n - 1]) + abs(sy - y[n - 1]) * abs(sy - y[n - 1])) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
