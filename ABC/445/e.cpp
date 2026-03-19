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
using u64 = unsigned long long;
using vii = vector<int>;
using vvii = vector<vii>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
// const ll MOD = 1e9+7LL;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
const double INF_D = numeric_limits<double>::infinity();
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
bool isIn(ll nx, ll ny, ll h, ll w)
{
  if (nx >= 0 && nx < h && ny >= 0 && ny < w)
  {
    return true;
  }
  return false;
}
int main()
{
  ll h, w, n;
  cin >> h >> w >> n;
  vector<pll> x(n), y(n);
  vector<pll> p(n);
  rep(i, n)
  {
    ll xx, yy;
    cin >> xx >> yy;
    x[i] = {xx, i};
    y[i] = {yy, i};
    p[i] = {xx, yy};
  }
  sort(rall(x));
  sort(rall(y));
  ll h_ma = h;
  ll w_ma = w;
  vector<pll> ans(n);
  ll x_it = 0;
  ll y_it = 0;
  set<ll> s;
  pll res = {1, 1};
  rep(i, n)
  {
    while (x_it < n && s.count(x[x_it].S))
      x_it++;
    while (y_it < n && s.count(y[y_it].S))
      y_it++;

    if (x[x_it].F == h_ma)
    {
      ans[x[x_it].S] = res;
      res = {res.F, res.S + p[x[x_it].S].S};
      w_ma -= p[x[x_it].S].S;
      s.insert(x[x_it].S);
      x_it++;
    }
    else
    {
      ans[y[y_it].S] = res;
      res = {res.F + p[y[y_it].S].F, res.S};
      h_ma -= p[y[y_it].S].F;
      s.insert(y[y_it].S);
      y_it++;
    }
  }
  rep(i, n)
  {
    cout << ans[i].F << " " << ans[i].S << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcountll(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
