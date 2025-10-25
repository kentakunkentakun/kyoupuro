#include <bits/stdc++.h>

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
  vector<vector<char>> c(n, vector<char>(n));
  vector<vvll> t(n, vvll(26, vll(0)));
  vector<vvll> rt(n, vvll(26, vll(0)));

  rep(i, n)
  {
    rep(j, n)
    {
      cin >> c[i][j];
      if (c[i][j] != '-')
      {
        t[i][c[i][j] - 'a'].pb(j);
        rt[j][c[i][j] - 'a'].pb(i);
      }
    }
  }
  vvll dp(n, vll(n, INF));
  queue<tuple<ll, ll, ll>> que;
  rep(i, n)
  {
    rep(j, n)
    {
      if (c[i][j] != '-')
      {
        dp[i][j] = 1;
        que.push({i, j, 1});
      }
    }
  }
  rep(i, n)
  {
    dp[i][i] = 0;
    que.push({i, i, 0});
  }

  while (que.size())
  {
    auto [x, y, d] = que.front();
    que.pop();
    if (dp[x][y] < d)
      continue;
    rep(a, 26)
    {
      ll xs = rt[x][a].size();
      ll ys = t[y][a].size();
      rep(i, xs)
      {
        rep(j, ys)
        {
          ll ni = rt[x][a][i];
          ll nj = t[y][a][j];
          if (x == y && ni == nj)
            continue;
          if (chmin(dp[ni][nj], dp[x][y] + 2))
          {
            que.push({ni, nj, dp[ni][nj]});
          }
        }
      }
    }
  }
  rep(i, n)
  {
    rep(j, n)
    {
      if (dp[i][j] == INF)
      {
        cout << -1 << " ";
      }
      else
      {
        cout << dp[i][j] << " ";
      }
    }
    cout << endl;
  }
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/
