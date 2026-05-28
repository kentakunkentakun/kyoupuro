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
int main()
{
  ll n, k;
  cin >> n >> k;
  vll a(n);
  rep(i, n) cin >> a[i];
  vll p(0), m(0);
  ll z = 0;
  rep(i, n)
  {
    if (a[i] > 0)
    {
      p.pb(a[i]);
    }
    else if (a[i] < 0)
    {
      m.pb(-1 * a[i]);
    }
    else
    {
      z++;
    }
  }
  sort(all(p));
  sort(all(m));
  ll ac = -INF, wa = INF;
  auto judge = [&](ll wj) -> bool
  {
    ll cnt = 0;
    vll tmp(0);
    rep(i, p.size())
    {
      if (wj > 0)
      {
        cnt += m.size() + z;
        auto it = lower_bound(all(tmp), (wj + p[i]) / p[i]) - tmp.begin();
        cnt += it;
        tmp.pb(p[i]);
      }
      else if (wj == 0)
      {
        cnt += m.size() + z;
      }
      else
      {
        auto it = m.end() - lower_bound(all(m), (-1 * wj + p[i] - 1) / p[i]);
        cnt += it;
      }
    }
    tmp = {};
    rep(i, m.size())
    {
      if (wj > 0)
      {
        cnt += z;
        auto it = lower_bound(all(tmp), (wj + m[i]) / m[i]) - tmp.begin();
        cnt += it;
        tmp.pb(m[i]);
      }
      else if (wj == 0)
      {
        cnt += z;
      }
    }
    if (wj >= 0)
    {
      cnt += z * (z - 1) / 2;
    }
    return (cnt < k);
  };
  while (ac + 1 < wa)
  {
    ll mid = (ac + wa) / 2;
    if (judge(mid))
    {
      ac = mid;
    }
    else
    {
      wa = mid;
    }
  }
  cout << ac + 1 << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);
__int128

//ソート済み
v.erase(unique(v.begin(), v.end()), v.end());
__builtin_popcount(i)*/
