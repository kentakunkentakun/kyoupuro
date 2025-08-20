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
ll same(string s, string t)
{
  int si = 0, ti = 0;
  ll ans = 0;
  while (si < (int)s.size() && ti < (int)t.size())
  {
    if (s[si] == t[ti])
    {
      ans++;
      si++;
      ti++;
    }
    else
    {
      break;
    }
  }
  return ans;
}
int main()
{
  ll n;
  cin >> n;
  vector<string> s(n);
  vector<string> t(n);
  map<string, ll> ss;
  rep(i, n)
  {
    cin >> s[i];
    t[i] = s[i];
    ss[s[i]]++;
  }
  sort(all(s));
  rep(i, n)
  {
    ll ans = 0;
    if (ss[t[i]] >= 2)
    {
      cout << t[i].size() << endl;
      continue;
    }
    ll iter = lower_bound(all(s), t[i]) - s.begin();
    if (iter - 1 >= 0)
    {
      chmax(ans, same(s[iter - 1], t[i]));
    }
    if (iter + 1 < (int)s.size())
    {
      chmax(ans, same(s[iter + 1], t[i]));
    }
    cout << ans << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
