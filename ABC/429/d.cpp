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
using vvvll = vector<vvll>;
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
  ll n, m, c;
  cin >> n >> m >> c;
  vll a(n);
  rep(i, n) cin >> a[i];
  map<ll, ll> z;
  rep(i, n)
  {
    z[a[i]]++;
  }
  ll z_cnt = z.size();
  vll d(2 * z_cnt + 1);
  rep(i, 2)
  {
    ll iter = i * z_cnt;
    for (auto p : z)
    {
      d[iter + 1] += d[iter] + p.S;
      iter++;
    }
  }
  vector<pll> p(0);
  p.pb({0, 0});
  for (auto e : z)
  {
    p.pb(e);
  }
  for (auto e : z)
  {
    p.pb({e.F + m, e.S});
  }
  ll ans = 0;
  ll iter = z_cnt + 1;
  rep(i, z_cnt)
  {
    ll a = d[iter - 1];
    auto it = lower_bound(all(d), a - (c - 1)) - d.begin();
    // cout << "it " << it << endl;
    // cout << "p[it].F " << p[it].F << endl;
    // cout << "p[iter].F " << p[iter].F << endl;
    ll k;
    k = p[iter].F - p[it].F;
    // cout << a << " " << it << " " << p[iter].S << " " << k << " " << p[it].F << " " << p[iter].F << " " << it << " " << iter << endl;

    ans += k * p[iter].S;

    iter++;
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
__builtin_popcount(i)

// maskからnowのビットだけ削除
mask & ~(1 << now)

*/
