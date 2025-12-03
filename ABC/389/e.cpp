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
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll MOD = 998244353LL;
const ll INF = 1LL << 60;
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
ll calc(ll a, ll ma)
{
  ll ac = 0, wa = INF;
  while (ac + 1 < wa)
  {
    ll wj = (ac + wa) / 2;
    if ((__int128)ma < (__int128)wj * (__int128)wj || (__int128)ma < (__int128)a * (__int128)wj * (__int128)wj)
    {
      wa = wj;
    }
    else
    {
      ac = wj;
    }
  }
  return ac;
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vll p(n);
  rep(i, n) cin >> p[i];
  auto judge = [&](ll wj) -> bool
  {
    ll money = 0;
    rep(i, n)
    {
      ll res = calc(p[i], wj);
      money += res * res * p[i];
    }
    if (money > m)
    {
      return false;
    }
    return true;
  };

  ll ac = 0, wa = INF;
  while (ac + 1 < wa)
  {
    ll ju = (ac + wa) / 2;
    if (judge(ju))
    {
      ac = ju;
    }
    else
    {
      wa = ju;
    }
  }
  ll cnt = 0;
  rep(i, n)
  {
    ll res = calc(p[i], ac);
    cnt += res;
  }
  cout << cnt << endl;
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
