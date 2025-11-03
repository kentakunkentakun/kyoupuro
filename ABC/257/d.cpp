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
struct edge
{
  ll u, v, p;
};
int main()
{
  ll n;
  cin >> n;
  vector<edge> e(n);
  rep(i, n)
  {
    ll x, y, p;
    cin >> x >> y >> p;
    x--;
    y--;
    e[i] = {x, y, p};
  }
  ll ac = 5e9 + 5;
  ll wa = -1;
  auto judge = [&](ll wj) -> bool
  {
    bool ok = false;
    rep(i, n)
    {
      vb ch(n, false);
      ch[i] = true;
      queue<tuple<ll, ll, ll>> que;
      que.push({e[i].u, e[i].v, e[i].p});
      while (que.size())
      {
        auto [x, y, p] = que.front();
        que.pop();
        rep(nx, n)
        {
          if (!ch[nx])
          {
            ll ex = e[nx].u;
            ll ey = e[nx].v;
            if (wj * p >= abs(x - ex) + abs(y - ey))
            {
              ch[nx] = true;
              que.push({ex, ey, e[nx].p});
            }
          }
        }
      }
      bool tmp = true;
      rep(i, n)
      {
        tmp &= ch[i];
      }
      if (tmp)
      {
        ok = true;
        break;
      }
    }
    return ok;
  };
  while (wa + 1 < ac)
  {
    ll wj = (ac + wa) / 2;
    if (judge(wj))
    {
      ac = wj;
    }
    else
      wa = wj;
  }
  cout << ac << endl;
}

/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
