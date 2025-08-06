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
  ll h, w;
  cin >> h >> w;
  ll rs, cs, rt, ct;
  cin >> rs >> cs >> rt >> ct;
  rs--;
  cs--;
  rt--;
  ct--;
  vector<vector<char>> t(h, vector<char>(w));
  rep(i, h) rep(j, w)
  {
    cin >> t[i][j];
  }
  vector<vector<ll>> dp(h, vector<ll>(w, INF));
  dp[rs][cs] = 0;
  priority_queue<pair<ll, tll>, vector<pair<ll, tll>>, greater<pair<ll, tll>>> que;
  que.push(mp(0, tll(rs, cs, -1)));
  while (que.size())
  {
    pair<ll, tll> now = que.top();
    que.pop();
    rep(i, 4)
    {
      ll nx = get<0>(now.S) + dx[i];
      ll ny = get<1>(now.S) + dy[i];

      if (nx >= 0 && ny >= 0 && nx < h && ny < w)
      {

        if (t[nx][ny] != '#')
        {
          if (get<2>(now.S) == -1 && dp[nx][ny] >= now.F)
          {
            dp[nx][ny] = now.F;
            que.push(mp(now.F, tll(nx, ny, i)));
          }
          else if (get<2>(now.S) != i && dp[nx][ny] >= now.F + 1)
          {
            dp[nx][ny] = now.F + 1;
            que.push(mp(now.F + 1, tll(nx, ny, i)));
          }
          else if (get<2>(now.S) == i && dp[nx][ny] >= now.F)
          {
            dp[nx][ny] = now.F;
            que.push(mp(now.F, tll(nx, ny, i)));
          }
        }
      }
    }
  }
  cout << dp[rt][ct] << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
