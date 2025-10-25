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
using u128 = __uint128_t;

ll floor_sqrt(ll x)
{
  ll r = (ll)sqrtl((long double)x); // 近似
  while ((u128)(r + 1) * (r + 1) <= x)
    ++r; // 小さすぎたら上げる
  while ((u128)r * r > x)
    --r; // 大きすぎたら下げる
  return r;
}
ll keta(ll s)
{
  ll now = 0;
  while (s)
  {
    now++;
    s /= 10;
  }
  return now;
}
int main()
{
  ll t;
  cin >> t;
  // ll a;
  // cout << fixed << setprecision(20);

  // cin >> a;
  // cout << (double)sqrt(a) << endl;
  map<ll, ll> m;
  ll v = 9;
  rep(i, 18)
  {
    m[i + 1] = v;
    v *= 10;
    v += 9;
  }

  rep(T, t)
  {
    ll c, d;
    cin >> c >> d;
    ll fc = c;
    ll s = c + 1;
    ll e;
    ll res = 0;
    ll mi_keta = keta(s);
    ll ma_keta = keta(c + d);
    rep(i, mi_keta - 1) c *= 10;
    e = m[mi_keta];
    ll se_s = 1;
    rep(i, mi_keta) se_s *= 10;

    rep(i, (ma_keta - mi_keta + 1))
    {
      c *= 10;
      if (ma_keta - mi_keta == i)
      {
        e = fc + d;
      }
      if (i == 1)
      {
        s = se_s;
      }
      ll mi = floor_sqrt(c + s);
      ll ma = floor_sqrt(c + e);
      if (mi * mi == (c + s))
        mi--;
      res += ma - mi;
      // cout << c + s << " " << c + e << " " << res << endl;
      s *= 10;
      e *= 10;
      e += 9;
    }
    cout << res << endl;
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
