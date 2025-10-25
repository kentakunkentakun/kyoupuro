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
  ll n, X, Y;
  cin >> n >> X >> Y;
  vll a(n);
  rep(i, n) cin >> a[i];
  vll big(0);
  vll small(0);
  vll y(0);
  vll x(0);
  rep(i, n)
  {
    if (a[i] > X)
      big.pb(i);
    if (a[i] < Y)
      small.pb(i);
    if (a[i] == X)
      x.pb(i);
    if (a[i] == Y)
      y.pb(i);
  }
  ll ans = 0;
  rep(i, n)
  {
    ll big_iter = upper_bound(all(big), i) - big.begin();
    ll small_iter = upper_bound(all(small), i) - small.begin();
    ll x_iter = upper_bound(all(x), i) - x.begin();
    ll y_iter = upper_bound(all(y), i) - y.begin();
    if (x_iter == 0 || y_iter == 0)
    {
      continue;
    }
    x_iter--;
    y_iter--;
    ll mi = min(x[x_iter], y[y_iter]);
    ll limit_max = -1;
    if (big_iter != 0)
    {
      chmax(limit_max, big[big_iter - 1]);
    }
    if (small_iter != 0)
    {
      chmax(limit_max, small[small_iter - 1]);
    }
    if (limit_max < mi)
      ans += mi - limit_max;
  }
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
