#include <bits/stdc++.h>
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
  ll n, q;
  cin >> n >> q;
  vector<tuple<ll, ll, ll>> t(q);
  rep(i, q)
  {
    ll l, r, c;
    cin >> l >> r >> c;
    l--;
    t[i] = {c, l, r};
  }
  sort(all(t));
  set<pll> s;
  ll ans = 0;
  rep(i, q)
  {
    auto [c, l, r] = t[i];
    pll k = {l, -1};
    auto it = s.lower_bound(k);
    if (s.size() == 0)
    {
      ans += (r - l) * c;
      s.insert({l, r});
      continue;
    }
    ll cnt = 0;
    ll left = l;
    ll right = r;
    pll e;
    if (it != s.begin())
    {
      it--;
      e = *it;
      if (e.S >= r)
      {
        ans += c;
        continue;
      }
      // 交わらない
      if (e.S <= l)
      {
        it++;
      }
      else
      {
        // 交わる
        cnt++;
        chmin(left, e.F);
        l = e.S;
        it = s.erase(it);
      }
    }

    if (it != s.end())
    {
      e = *it;
      while (1)
      {
        if (e.F >= r)
        {
          break;
        }
        else
        {
          cnt += e.F - l;
          cnt++;
          l = e.S;
          chmax(right, e.S);
          it = s.erase(it);
          if (it == s.end())
          {
            break;
          }
          e = *it;
        }
      }
    }
    cnt += max(0LL, r - l);
    ans += cnt * c;
    s.insert({left, right});
  }
  auto u = *s.begin();
  if (u.F == 0 && u.S == n)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
