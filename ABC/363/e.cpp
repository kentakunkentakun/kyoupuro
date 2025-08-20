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
  ll h, w, y;
  cin >> h >> w >> y;
  vvll a(h, vll(w));
  vvll ch(h, vll(w, -1));
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
  set<tuple<ll, ll, ll>> s;
  rep(i, h)
  {
    rep(j, w) cin >> a[i][j];
  }
  rep(i, h)
  {
    if (ch[i][0] == -1)
    {
      que.push({a[i][0], i, 0});
      ch[i][0] = 0;
    }
    if (ch[i][w - 1] == -1)
    {
      que.push({a[i][w - 1], i, w - 1});
      ch[i][w - 1] = 0;
    }
  }

  rep(i, w)
  {
    if (ch[0][i] == -1)
    {
      que.push({a[0][i], 0, i});
      ch[0][i] = 0;
    }
    if (ch[h - 1][i] == -1)
    {
      que.push({a[h - 1][i], h - 1, i});
      ch[h - 1][i] = 0;
    }
  }
  ll sink = 0;
  for (int i = 1; i <= y; i++)
  {
    while (que.size() && get<0>(que.top()) <= i)
    {
      auto now = que.top();
      que.pop();
      ch[get<1>(now)][get<2>(now)] = 1;
      rep(i, 4)
      {
        ll ni = dx[i] + get<1>(now);
        ll nj = dy[i] + get<2>(now);
        if (ni >= 0 && ni < h && nj >= 0 && nj < w)
        {
          if (ch[ni][nj] == -1)
          {
            que.push({a[ni][nj], ni, nj});
            ch[ni][nj] = 0;
          }
        }
      }
      sink++;
    }
    cout << h * w - sink << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
