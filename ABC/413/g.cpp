#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <atcoder/dsu>
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
ll dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int main()
{
  ll h, w, k;
  cin >> h >> w >> k;
  map<pll, ll> m;
  ll iter = 0;
  rep(i, h)
  {
    m[{i + 1, w + 1}] = iter;
    iter++;
  }
  rep(i, h)
  {
    m[{i + 1, 0}] = iter;
    iter++;
  }
  rep(i, w)
  {
    m[{h + 1, i + 1}] = iter;
    iter++;
  }
  rep(i, w)
  {
    m[{0, i + 1}] = iter;
    iter++;
  }

  vector<pll> p(k);
  rep(i, k)
  {
    ll r, c;
    cin >> r >> c;
    m[{r, c}] = iter;
    p[i] = {r, c};
    iter++;
  }
  m[{h + 1, 0}] = iter;
  iter++;
  m[{0, w + 1}] = iter;
  iter++;
  p.pb({h + 1, 0});
  p.pb({0, w + 1});

  dsu uf(iter);
  rep(i, h - 1)
  {
    uf.merge(i, i + 1);
  }
  rep(i, h - 1)
  {
    uf.merge(h + i, h + i + 1);
  }
  rep(i, w - 1)
  {
    uf.merge(2 * h + i, 2 * h + i + 1);
  }
  rep(i, w - 1)
  {
    uf.merge(2 * h + w + i, 2 * h + w + i + 1);
  }
  rep(i, k+2)
  {
    auto [x, y] = p[i];
    rep(z, 8)
    {
      ll nx = x + dx[z];
      ll ny = y + dy[z];
      if (nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1)
      {
        if (m.count({nx, ny}))
        {
          ll iter = m[{nx, ny}];
          uf.merge(2 * (h + w) + i, iter);
        }
      }
    }
  }
  if (uf.same(0, h))
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
