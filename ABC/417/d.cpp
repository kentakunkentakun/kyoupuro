#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
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
  ll n;
  cin >> n;
  vector<ll> p(n), a(n), b(n);
  vll bb(n + 1);
  rep(i, n)
  {
    cin >> p[i] >> a[i] >> b[i];
  }
  rep(i, n)
  {
    bb[i + 1] += bb[i] + b[i];
  }
  vvll t(n + 1, vll(1005));
  rep(i, 1005)
  {
    t[n][i] = i;
  }
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 1004; j >= 0; j--)
    {
      if (j <= p[i])
      {
        t[i][j] = t[i + 1][j + a[i]];
      }
      else
      {
        t[i][j] = t[i + 1][max(0LL, j - b[i])];
      }
    }
  }
  ll q;
  cin >> q;
  vll xx(q);
  rep(i, q) cin >> xx[i];
  rep(i, q)
  {
    ll x = xx[i];
    if (x > 1000)
    {
      ll sa = x - 1000;
      ll iter = lower_bound(all(bb), sa) - bb.begin();
      if (iter == bb.size())
      {
        cout << x - bb[n] << endl;
      }
      else
      {
        x -= bb[iter];
        cout << t[iter][x] << endl;
      }
    }
    else
    {
      cout << t[0][x] << endl;
    }
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
