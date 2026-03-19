#include <bits/stdc++.h>
#include <atcoder/all>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using namespace atcoder;
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
  ll n, m;
  cin >> n >> m;
  vll a(m), b(m);
  vector<tuple<ll, ll, ll>> p(m);
  rep(i, m)
  {
    cin >> a[i] >> b[i];
    p[i] = {a[i], b[i], -1};
  }
  ll q;
  cin >> q;
  rep(i, q)
  {
    ll c, d;
    cin >> c >> d;
    p.pb({c, d, i});
  }
  fenwick_tree<ll> bit(2 * n + 5);
  sort(all(p));
  vll ans(q);
  rep(i, m + q)
  {
    auto [x, y, it] = p[i];
    // cout << x << " " << y << " " << it << endl;
    if (it != -1)
    {
      ans[it] = bit.sum(x, y + 1);
    }
    else
    {
      bit.add(y, 1);
    }
  }
  rep(i, m + q)
  {
    auto [x, y, it] = p[i];
    p[i] = {y, x, it};
  }

  sort(rall(p));
  fenwick_tree<ll> rbit(2 * n + 5);
  rep(i, m + q)
  {
    auto [x, y, it] = p[i];
    if (it != -1)
    {
      ans[it] += rbit.sum(y, x + 1);
    }
    else
    {
      rbit.add(y, 1);
    }
  }
  rep(i, q)
  {
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
