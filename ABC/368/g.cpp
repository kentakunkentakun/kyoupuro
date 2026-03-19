#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <atcoder/segtree>
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
ll op_min(ll a, ll b)
{
  return max(a, b);
}
ll e_min()
{
  return 0;
}

ll op_sum(ll a, ll b)
{
  return a + b;
}
ll e_sum()
{
  return 0;
}
ll k = 1;
bool right_f(ll a)
{
  return a <= k;
}
int main()
{
  ll n;
  cin >> n;
  vll a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll q;
  cin >> q;
  segtree<ll, op_sum, e_sum> seg_sum(a);
  segtree<ll, op_min, e_min> seg_min(b);
  rep(i, q)
  {
    ll t;
    cin >> t;
    if (t == 1)
    {
      ll it, x;
      cin >> it >> x;
      it--;
      seg_sum.set(it, x);
      a[it] = x;
    }
    else if (t == 2)
    {
      ll it, x;
      cin >> it >> x;
      it--;
      seg_min.set(it, x);
      b[it] = x;
    }
    else
    {
      ll l, r;
      cin >> l >> r;
      l--;
      ll v = 0;
      while (l < r)
      {
        if (b[l] != 1)
        {
          v = max(v + a[l], v * b[l]);
          l++;
        }
        else
        {
          ll nx = seg_min.max_right<right_f>(l);
          chmin(nx, r);
          v += seg_sum.prod(l, nx);
          l = nx;
        }
      }
      cout << v << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
