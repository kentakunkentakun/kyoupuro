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
int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  vll a(n);
  rep(i, n) cin >> a[i];
  multiset<ll> ok, ng;
  rep(i, m)
  {
    ok.insert(a[i]);
  }
  rep(i, m - k)
  {
    auto it = ok.rbegin();
    ng.insert(*it);
    ok.erase(prev(it.base()));
  }
  ll ans = 0;
  for (auto p : ok)
  {
    ans += p;
  }
  cout << ans << " ";
  if (k == m)
  {
    for (int i = m; i < n; i++)
    {
      ans += a[i] - a[i - m];
      cout << ans << " ";
    }
    cout << endl;
    return 0;
  }
  for (int i = m; i < n; i++)
  {
    ll challenger = a[i];
    ll retire = a[i - m];
    if (ng.count(retire))
    {
      ng.erase(ng.find(retire));
      auto it = ok.rbegin();
      if (*it > challenger)
      {
        ok.insert(challenger);
        ans += challenger - *it;
        ng.insert(*it);
        ok.erase(prev(it.base()));
      }
      else
      {
        ng.insert(challenger);
      }
    }
    else
    {
      ok.erase(ok.find(retire));
      auto it = ng.begin();
      if (*it < challenger)
      {
        ok.insert(*it);
        ans += *it - retire;
        ng.erase(it);
        ng.insert(challenger);
      }
      else
      {
        ok.insert(challenger);
        ans += challenger - retire;
      }
    }
    cout << ans << " ";
  }
  cout << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
