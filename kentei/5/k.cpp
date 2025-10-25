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
const ll MOD = 998244353LL;
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
ll dx[5] = {0, 1, 0, 0, -1};
ll dy[5] = {1, 0, 0, -1, 0};
int main()
{
  string S[4];
  rep(y, 4) cin >> S[y];
  cout << fixed << setprecision(10);

  vector<double> dp(1 << 16, 1e9);
  auto dfs = [&](auto f, int i) -> double
  {
    if (__builtin_popcount(i) == 0)
    {
      return dp[i] = 0;
    }
    if (dp[i] != 1e9)
    {
      return dp[i];
    }
    rep(x, 4) rep(y, 4)
    {
      int cnt = 0;
      double tot = 5;
      rep(d, 5)
      {
        int xx = dx[d] + x;
        int yy = dy[d] + y;
        if (0 <= xx && xx < 4 && 0 <= yy && yy < 4 && i & (1 << (yy * 4 + xx)))
        {
          cnt++;
          tot += f(f, i ^ (1 << (yy * 4 + xx)));
        }
      }
      if (0 < cnt)
        chmin(dp[i], tot / cnt);
    }
    return dp[i];
  };
  int Smsk = 0;
  rep(y, 4) rep(x, 4)
  {
    if (S[y][x] == '#')
      Smsk |= 1 << (y * 4 + x);
  }
  cout << dfs(dfs, Smsk) << endl;
}
/*cin.tie(0);
ios::sync_with_studio(false);
next_permutation(v.begin(), v.end())

cout << fixed << setprecision(10);

__builtin_popcount(i)*/

