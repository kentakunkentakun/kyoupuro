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
ll h, w, n;
bool is_in(ll a, ll b)
{
  if (a >= 0 && b >= 0 && a <= h - 1 && b <= w - 1)
  {
    return true;
  }
  return false;
}

int main()
{
  cin >> h >> w >> n;
  map<int, set<int>> s;
  vector<int> a(n);
  vector<int> b(n);
  set<pair<int, int>> ex;
  vector<ll> ans(10);
  rep(i, n)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    s[a[i]].insert(b[i]);
  }
  rep(i, n)
  {
    rep(x, 3)
    {
      rep(y, 3)
      {
        if (is_in(a[i] - 2 + x, b[i] - 2 + y) && is_in(a[i] - 2 + x, b[i] + y) && is_in(a[i] + x, b[i] - 2 + y) && is_in(a[i] + x, b[i] + y) && !ex.count(mp(a[i] - 2 + x, b[i] - 2 + y)))
        {
          int count = 0;
          for (int z = a[i] - 2 + x; z <= a[i] + x; z++)
          {
            for (int t = b[i] - 2 + y; t <= b[i] + y; t++)
            {
              if (s[z].count(t))
              {
                count++;
              }
            }
          }
          ans[count]++;
          ex.insert(mp(a[i] - 2 + x, b[i] - 2 + y));
        }
      }
    }
  }
  ll all = 0;
  rep(i, 10)
  {
    all += ans[i];
  }
  cout << (h - 2) * (w - 2) - all << endl;
  rep(i, 10)
  {
    if (i == 0)
      continue;
    cout << ans[i] << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
