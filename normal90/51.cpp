#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n - 1; i >= 0; i--)
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
int main()
{
  ll n, k, p;
  cin >> n >> k >> p;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> x(25, vector<ll>(0));
  vector<vector<ll>> y(25, vector<ll>(0));
  for (int bit = 0; bit < (1 << (n / 2)); bit++)
  {
    ll res = 0;
    rep(i, n / 2)
    {
      if (bit & (1 << i))
      {
        res += a[i];
      }
    }
    int xx = __builtin_popcount(bit);
    x[xx].pb(res);
  }
  for (int bit = 0; bit < (1 << ((n + 1) / 2)); bit++)
  {
    ll res = 0;
    rep(i, (n + 1) / 2)
    {
      if (bit & (1 << i))
      {
        res += a[i + (n / 2)];
      }
    }
    int yy = __builtin_popcount(bit);
    y[yy].pb(res);
  }
  ll ans = 0;
  rep(i, 25)
  {
    sort(all(x[i]));
    sort(all(y[i]));
  }
  rep(i, 21)
  {
    rep(j, 21)
    {
      if (i + j == k)
      {
        for (ll xx : x[i])
        {
          // y[j] 内で p - xx 以下の値の個数を数える（二分探索）
          ll ok = upper_bound(all(y[j]), p - xx) - y[j].begin();
          ans += ok;
        }
      }
    }
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
