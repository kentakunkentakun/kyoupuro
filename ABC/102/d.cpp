#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace atcoder;
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (ll i = (a); i <= (b); i++)
#define repR(i, n) for (ll i = n; i >= 0; i--)
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

long long modpow(long long a, long long n, long long mod)
{
  a %= mod;
  long long res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
struct S
{
  ll l, r, sum;
  bool empty;
};
S op(S a, S b)
{
  if (a.empty)
  {
    return b;
  }
  if (b.empty)
  {
    return a;
  }
  return {
      a.l, b.r, a.sum + b.sum, false};
};
S e()
{
  return {-1, -1, -1, true};
}
ll r_k;
bool right_f(S a)
{
  if (a.empty)
  {
    return true;
  }
  return a.sum <= r_k;
}
ll l_k;
bool left_f(S a)
{
  if (a.empty)
  {
    return true;
  }
  return a.sum <= l_k;
}
int main()
{
  ll n;
  cin >> n;
  vll a(n);
  vector<S> init(n);
  fenwick_tree<ll> bit(n);
  rep(i, n)
  {
    cin >> a[i];
    bit.add(i, a[i]);
    init[i].l = i;
    init[i].r = i + 1;
    init[i].sum = a[i];
    init[i].empty = false;
  }
  segtree<S, op, e> seg(init);
  ll ans = INF;
  for (int i = 1; i < n - 2; i++)
  {
    ll left_sum = seg.prod(0, i + 1).sum;
    ll right_sum = seg.prod(i + 1, n).sum;
    l_k = left_sum / 2;
    r_k = right_sum / 2;
    ll left_it = seg.min_left<left_f>(i + 1);
    ll right_it = seg.max_right<right_f>(i + 1);
    ll l_ma = -1;
    ll l_mi = INF;
    ll l_0 = bit.sum(0, left_it);
    ll l_1 = bit.sum(left_it, i + 1);
    ll l_2 = bit.sum(0, left_it - 1);
    ll l_3 = bit.sum(left_it - 1, i + 1);
    if (abs(l_0 - l_1) > abs(l_2 - l_3))
    {
      chmax(l_ma, max(l_2, l_3));
      chmin(l_mi, min(l_2, l_3));
    }
    else
    {
      chmax(l_ma, max(l_0, l_1));
      chmin(l_mi, min(l_0, l_1));
    }
    ll r_ma = -1;
    ll r_mi = INF;
    ll r_0 = bit.sum(i + 1, right_it);
    ll r_1 = bit.sum(right_it, n);
    ll r_2 = bit.sum(i + 1, right_it + 1);
    ll r_3 = bit.sum(right_it + 1, n);
    if (abs(r_0 - r_1) > abs(r_2 - r_3))
    {
      chmax(r_ma, max(r_2, r_3));
      chmin(r_mi, min(r_2, r_3));
    }
    else
    {
      chmax(r_ma, max(r_0, r_1));
      chmin(r_mi, min(r_0, r_1));
    }
    chmin(ans, max(r_ma, l_ma) - min(r_mi, l_mi));
    // cout << i << " " << ans << " " << l_mi << " " << l_ma << " " << r_mi << " " << r_ma << endl;
  }
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
