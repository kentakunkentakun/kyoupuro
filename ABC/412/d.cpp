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
ll ss(vll &a, vvll &t)
{
  ll ans = INF;
  do
  {
    ll cost = 0;
    rep(i, a.size())
    {
      ll nv, bv;

      if (i == a.size() - 1)
      {
        nv = a[0];
      }
      else
      {
        nv = a[i + 1];
      }
      if (i == 0)
      {
        bv = a[a.size() - 1];
      }
      else
      {
        bv = a[i - 1];
      }
      for (auto p : t[a[i]])
      {
        if (p != nv && p != bv)
          cost++;
      }
      if (!count(all(t[a[i]]), nv))
        cost++;
      if (!count(all(t[a[i]]), bv))
        cost++;
    }
    chmin(ans, cost);
  } while (next_permutation(all(a)));
  return ans;
}
int main()
{
  ll n, m;
  cin >> n >> m;
  vvll t(n, vll(0));
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    t[a].pb(b);
    t[b].pb(a);
  }
  ll ans = INF;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    ll on = __builtin_popcount(bit);
    vll a(0);
    vll b(0);
    if (min(on, n - on) >= 3)
    {
      rep(i, n)
      {
        if (bit & (1 << i))
        {
          a.pb(i);
        }
        else
        {
          b.pb(i);
        }
      }
      chmin(ans, (ss(a, t) + ss(b, t)) / 2);
    }
  }
  vll a(n);
  rep(i, n)
  {
    a[i] = i;
  }
  chmin(ans, ss(a, t) / 2);
  cout << ans << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
