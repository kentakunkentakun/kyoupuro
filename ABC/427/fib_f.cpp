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
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  ll c = (n + 1) / 2;
  vll r(n / 2);
  vll r0(max(n / 2 - 1, 0LL));
  vll l(max(c - 2, 0LL));
  vll l0(max(c - 1, 0LL));
  rep(i, l.size())
  {
    l[i] = a[i];
  }
  rep(i, l0.size())
  {
    l0[i] = a[i];
  }
  rep(i, r.size())
  {
    r[i] = a[i + (n + 1) / 2];
  }
  rep(i, r0.size())
  {
    r0[i] = a[i + (n + 1) / 2 + 1];
  }
  auto fib = [&](vll &k)
  {
    vll dp0 = {0}, dp1 = {0};
    rep(i, k.size())
    {
      vll dp2 = dp1;
      for (auto p : dp0)
      {
        ll nx = p + k[i];
        nx %= m;
        dp2.pb(nx);
      }
      swap(dp0, dp1);
      swap(dp1, dp2);
    }
    return dp1;
  };
  vll res_l = fib(l);
  ll ans = 0;
  vll res_l0 = fib(l0);
  vll res_r = fib(r);
  vll res_r0 = fib(r0);

  sort(all(res_r));
  sort(all(res_r0));

  for (auto p : res_l)
  {
    ll nx = 2 * m - ((p + a[c - 1])) % m;
    nx %= m;
    ll cnt = upper_bound(all(res_r0), nx) - lower_bound(all(res_r0), nx);
    ans += cnt;
  }
  for (auto p : res_l0)
  {
    ll nx = 2 * m - p;
    nx %= m;
    ll cnt = upper_bound(all(res_r), nx) - lower_bound(all(res_r), nx);
    ans += cnt;
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
